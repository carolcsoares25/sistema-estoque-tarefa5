#include <stdio.h>
#include <string.h>
#include "categoria.h"
#include "util.h"
int buscarCategoria(struct Categoria lista[], int total, int codigo) {
    for (int i=0;i<total;i++) if(lista[i].codigo==codigo) return i;
    return -1;
}
int cadastrarCategoria(struct Categoria lista[], int total) {
    struct Categoria c;
    if(total>=MAX_CATEGORIAS){puts("Limite de categorias atingido.");return total;}
    do {
        printf("Codigo da categoria (positivo e unico): ");
        if(scanf("%d",&c.codigo)!=1){while(getchar()!='\n');c.codigo=0;}
        if(c.codigo<=0 || buscarCategoria(lista,total,c.codigo)!=-1) puts("Codigo invalido ou repetido.");
    }while(c.codigo<=0 || buscarCategoria(lista,total,c.codigo)!=-1);
    do {
        printf("Nome da categoria: ");
        scanf(" %29[^\n]",c.nome);
        if(!validarTextoPreenchido(c.nome)) puts("Nome nao pode ficar em branco.");
    }while(!validarTextoPreenchido(c.nome));
    lista[total]=c;
    puts("Categoria cadastrada com sucesso!");
    return total+1;
}
void listarCategorias(struct Categoria lista[], int total){
    if(!total){puts("Nenhuma categoria cadastrada.");return;}
    puts("\n===== CATEGORIAS =====");
    for(int i=0;i<total;i++) printf("Codigo: %d | Nome: %s\n",lista[i].codigo,lista[i].nome);
}
void menuCategorias(struct Categoria lista[], int *total){
    int opcao=0;
    do {
        puts("\n===== MENU CATEGORIAS =====\n1 - Cadastrar Categoria\n2 - Listar Categorias\n3 - Voltar");
        printf("Opcao: ");
        if(scanf("%d",&opcao)!=1){while(getchar()!='\n');opcao=0;}
        if(opcao==1)*total=cadastrarCategoria(lista,*total);
        else if(opcao==2)listarCategorias(lista,*total);
        else if(opcao!=3)puts("Opcao invalida.");
    }while(opcao!=3);
}
