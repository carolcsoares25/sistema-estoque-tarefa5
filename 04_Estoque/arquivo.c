#include <stdio.h>
#include "arquivo.h"
void carregarCategorias(struct Categoria lista[],int *total){
    FILE *f=fopen("categorias.txt","r");if(!f)return;
    while(*total<MAX_CATEGORIAS && fscanf(f,"%d;%29[^\n]\n",&lista[*total].codigo,lista[*total].nome)==2)(*total)++;
    fclose(f);
}
void carregarProdutos(struct Produto lista[],int *total){
    FILE *f=fopen("produtos.txt","r");if(!f)return;
    while(*total<MAX_PRODUTOS && fscanf(f,"%d;%49[^;];%c;%f;%d;%d;%d;%d\n",&lista[*total].codigo,lista[*total].nome,&lista[*total].prateleira,&lista[*total].preco,&lista[*total].quantidade,&lista[*total].disponivel,&lista[*total].categoria_codigo,&lista[*total].ativo)==8)(*total)++;
    fclose(f);
}
void salvarCategorias(struct Categoria lista[],int total){
    FILE *f=fopen("categorias.txt","w");if(!f){perror("Erro ao salvar categorias");return;}
    for(int i=0;i<total;i++)fprintf(f,"%d;%s\n",lista[i].codigo,lista[i].nome);
    fclose(f);
}
void salvarProdutos(struct Produto lista[],int total){
    FILE *f=fopen("produtos.txt","w");if(!f){perror("Erro ao salvar produtos");return;}
    for(int i=0;i<total;i++)fprintf(f,"%d;%s;%c;%.2f;%d;%d;%d;%d\n",lista[i].codigo,lista[i].nome,lista[i].prateleira,lista[i].preco,lista[i].quantidade,lista[i].disponivel,lista[i].categoria_codigo,lista[i].ativo);
    fclose(f);
}
