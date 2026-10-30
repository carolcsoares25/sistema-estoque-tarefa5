#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "produto.h"
#include "categoria.h"
void carregarCategorias(struct Categoria lista[],int *total);
void carregarProdutos(struct Produto lista[],int *total);
void salvarCategorias(struct Categoria lista[],int total);
void salvarProdutos(struct Produto lista[],int total);
#endif
