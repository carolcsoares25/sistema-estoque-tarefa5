#ifndef PRODUTO_H
#define PRODUTO_H
#include "categoria.h"
#define MAX_PRODUTOS 50
struct Produto { int codigo; char nome[50]; char prateleira; float preco; int quantidade; int disponivel; int categoria_codigo; int ativo; };
int buscarPorCodigo(struct Produto lista[], int total, int codigo);
int buscarPorNome(struct Produto lista[], int total, char nome[]);
void exibirProduto(struct Produto p, struct Categoria categorias[], int totalCategorias);
int cadastrarProduto(struct Produto lista[], int total, struct Categoria categorias[], int totalCategorias);
void listarProdutos(struct Produto lista[], int total, struct Categoria categorias[], int totalCategorias);
void alterarEstoque(struct Produto lista[], int total, struct Categoria categorias[], int totalCategorias);
void removerProduto(struct Produto lista[], int total);
void pesquisarProduto(struct Produto lista[], int total, struct Categoria categorias[], int totalCategorias);
#endif
