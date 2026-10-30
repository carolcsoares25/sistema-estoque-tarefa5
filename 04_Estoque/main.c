#include <stdio.h>
#include "produto.h"
#include "categoria.h"
#include "arquivo.h"
int main(void){
    struct Produto produtos[MAX_PRODUTOS];struct Categoria categorias[MAX_CATEGORIAS];
    int totalProdutos=0,totalCategorias=0,opcao=0;
    carregarCategorias(categorias,&totalCategorias);
    carregarProdutos(produtos,&totalProdutos);
    do {
        puts("\n===== SISTEMA DE ESTOQUE =====\n1 - Cadastrar Produto\n2 - Listar Produtos\n3 - Pesquisar Produto\n4 - Alterar Estoque de um Produto\n5 - Remover Produto\n6 - Categorias\n7 - Sair");
        printf("Digite uma opcao: ");
        if(scanf("%d",&opcao)!=1){while(getchar()!='\n');opcao=0;}
        switch(opcao){
            case 1:totalProdutos=cadastrarProduto(produtos,totalProdutos,categorias,totalCategorias);break;
            case 2:listarProdutos(produtos,totalProdutos,categorias,totalCategorias);break;
            case 3:pesquisarProduto(produtos,totalProdutos,categorias,totalCategorias);break;
            case 4:alterarEstoque(produtos,totalProdutos,categorias,totalCategorias);break;
            case 5:removerProduto(produtos,totalProdutos);break;
            case 6:menuCategorias(categorias,&totalCategorias);break;
            case 7:salvarCategorias(categorias,totalCategorias);salvarProdutos(produtos,totalProdutos);puts("Dados salvos. Saindo do sistema...");break;
            default:puts("Opcao invalida!");
        }
    }while(opcao!=7);
    return 0;
}
