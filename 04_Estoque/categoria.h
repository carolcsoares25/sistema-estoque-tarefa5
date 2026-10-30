#ifndef CATEGORIA_H
#define CATEGORIA_H
#define MAX_CATEGORIAS 20
struct Categoria { int codigo; char nome[30]; };
int buscarCategoria(struct Categoria lista[], int total, int codigo);
int cadastrarCategoria(struct Categoria lista[], int total);
void listarCategorias(struct Categoria lista[], int total);
void menuCategorias(struct Categoria lista[], int *total);
#endif
