#include <stdio.h>
#include <string.h>
#include "produto.h"
#include "util.h"
int buscarPorCodigo(struct Produto lista[],int total,int codigo){for(int i=0;i<total;i++)if(lista[i].codigo==codigo)return i;return -1;}
int buscarPorNome(struct Produto lista[],int total,char nome[]){for(int i=0;i<total;i++)if(strcmp(lista[i].nome,nome)==0)return i;return -1;}
void exibirProduto(struct Produto p,struct Categoria categorias[],int totalCategorias){
    int pos=buscarCategoria(categorias,totalCategorias,p.categoria_codigo);
    puts("\n===== DADOS DO PRODUTO =====");
    printf("Codigo: %d\nNome: %s\nPrateleira: %c\nPreco unitario: R$ %.2f\nQuantidade em estoque: %d\nDisponivel para venda: %d\nCategoria: %s\n",p.codigo,p.nome,p.prateleira,p.preco,p.quantidade,p.disponivel,pos>=0?categorias[pos].nome:"Categoria desconhecida");
}
int cadastrarProduto(struct Produto lista[],int total,struct Categoria categorias[],int totalCategorias){
    struct Produto p;
    if(total>=MAX_PRODUTOS){puts("Limite de produtos atingido.");return total;}
    if(totalCategorias==0){puts("Cadastre uma categoria antes de cadastrar produtos.");return total;}
    do {printf("Codigo do produto: ");if(scanf("%d",&p.codigo)!=1){while(getchar()!='\n');p.codigo=0;}if(p.codigo<=0||buscarPorCodigo(lista,total,p.codigo)!=-1)puts("Codigo invalido ou repetido.");}while(p.codigo<=0||buscarPorCodigo(lista,total,p.codigo)!=-1);
    do {printf("Nome: ");scanf(" %49[^\n]",p.nome);if(!validarTextoPreenchido(p.nome))puts("Nome invalido.");}while(!validarTextoPreenchido(p.nome));
    do {printf("Prateleira (A, B, C ou D): ");scanf(" %c",&p.prateleira);if(!validarPrateleira(p.prateleira))puts("Prateleira invalida.");}while(!validarPrateleira(p.prateleira));
    do {printf("Preco unitario: ");if(scanf("%f",&p.preco)!=1){while(getchar()!='\n');p.preco=0;}if(!validarPositivoFloat(p.preco))puts("Preco invalido.");}while(!validarPositivoFloat(p.preco));
    do {printf("Quantidade: ");if(scanf("%d",&p.quantidade)!=1){while(getchar()!='\n');p.quantidade=-1;}if(!validarNaoNegativoInt(p.quantidade))puts("Quantidade invalida.");}while(!validarNaoNegativoInt(p.quantidade));
    listarCategorias(categorias,totalCategorias);
    do {printf("Digite o codigo de uma categoria cadastrada: ");if(scanf("%d",&p.categoria_codigo)!=1){while(getchar()!='\n');p.categoria_codigo=-1;}if(buscarCategoria(categorias,totalCategorias,p.categoria_codigo)==-1)puts("Categoria nao encontrada. Tente novamente.");}while(buscarCategoria(categorias,totalCategorias,p.categoria_codigo)==-1);
    p.disponivel=p.quantidade>0;
    p.ativo=1;
    lista[total]=p;
    puts("Produto cadastrado com sucesso!");exibirProduto(p,categorias,totalCategorias);
    return total+1;
}
void listarProdutos(struct Produto lista[],int total,struct Categoria categorias[],int totalCategorias){
    int ativos=0; for(int i=0;i<total;i++)if(lista[i].ativo)ativos++;
    if(!ativos){puts("Nenhum produto ativo cadastrado.");return;}
    printf("\n===== LISTA DE PRODUTOS (%d) =====\n",ativos);
    for(int i=0;i<total;i++)if(lista[i].ativo)exibirProduto(lista[i],categorias,totalCategorias);
}
void pesquisarProduto(struct Produto lista[],int total,struct Categoria categorias[],int totalCategorias){
    int tipo=0,codigo,pos;char nome[50];
    if(!total){puts("Nenhum produto cadastrado.");return;}
    do {printf("\n1 - Pesquisar por codigo\n2 - Pesquisar por nome\nOpcao: ");if(scanf("%d",&tipo)!=1){while(getchar()!='\n');tipo=0;}}while(!validarIntervalo(tipo,1,2));
    if(tipo==1){printf("Codigo: ");if(scanf("%d",&codigo)!=1){while(getchar()!='\n');codigo=-1;}pos=buscarPorCodigo(lista,total,codigo);}
    else {printf("Nome: ");scanf(" %49[^\n]",nome);pos=buscarPorNome(lista,total,nome);}
    if(pos==-1 || !lista[pos].ativo)puts("Produto nao encontrado.");else exibirProduto(lista[pos],categorias,totalCategorias);
}

void alterarEstoque(struct Produto lista[], int total, struct Categoria categorias[], int totalCategorias){
    int codigo,pos,tipo,quantidade;
    printf("Codigo do produto para alterar estoque: ");
    if(scanf("%d",&codigo)!=1){while(getchar()!='\n');puts("Codigo invalido.");return;}
    pos=buscarPorCodigo(lista,total,codigo);
    if(pos<0 || !lista[pos].ativo){puts("Produto nao encontrado.");return;}
    printf("1 - Entrada\n2 - Saida\nOpcao: ");
    if(scanf("%d",&tipo)!=1){while(getchar()!='\n');puts("Operacao invalida.");return;}
    if(tipo!=1 && tipo!=2){puts("Operacao invalida.");return;}
    printf("Quantidade movimentada (positiva): ");
    if(scanf("%d",&quantidade)!=1){while(getchar()!='\n');puts("Quantidade invalida.");return;}
    if(quantidade<=0){puts("Quantidade invalida.");return;}
    if(tipo==2 && quantidade>lista[pos].quantidade){puts("Estoque insuficiente. Operacao cancelada.");return;}
    if(tipo==1){
        if(quantidade>2147483647-lista[pos].quantidade){puts("Quantidade excede limite. Operacao cancelada.");return;}
        lista[pos].quantidade+=quantidade;
    } else lista[pos].quantidade-=quantidade;
    lista[pos].disponivel=(lista[pos].quantidade>0);
    puts("Estoque atualizado com sucesso!");
    exibirProduto(lista[pos],categorias,totalCategorias);
}
void removerProduto(struct Produto lista[], int total){
    int codigo,pos;
    printf("Codigo do produto para remover: ");
    if(scanf("%d",&codigo)!=1){while(getchar()!='\n');puts("Codigo invalido.");return;}
    pos=buscarPorCodigo(lista,total,codigo);
    if(pos<0 || !lista[pos].ativo){puts("Produto nao encontrado.");return;}
    lista[pos].ativo=0;
    puts("Produto removido logicamente com sucesso!");
}
