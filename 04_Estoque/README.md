# Sistema de Estoque — Tarefa 5

Projeto em C com cadastro, listagem, pesquisa por codigo/nome, categorias, persistencia, movimentacao de estoque e exclusao logica.

## Compilacao

Na pasta `04_Estoque`, execute:

```bash
gcc -std=c11 -Wall -Wextra main.c produto.c categoria.c arquivo.c util.c -o estoque
./estoque
```

No Windows, execute `estoque.exe` apos compilar com `-o estoque.exe`.

## Persistencia

Os arquivos `categorias.txt` e `produtos.txt` sao criados na pasta de execucao ao selecionar Sair (7). Produtos removidos permanecem gravados com `ativo=0`. A disponibilidade e calculada com base na quantidade. O formato de produtos foi ampliado com a coluna `ativo`; arquivos da Tarefa 4 precisam ser convertidos antes de reutilizacao.

## Autores

- Caroline de Castro Soares — 47378557
- Samuel Ludovico — 48174211
- Higor Nascimento de Amorim — 47552409
