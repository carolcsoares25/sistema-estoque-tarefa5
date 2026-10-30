#ifndef UTIL_H
#define UTIL_H

/* Validacoes genericas (nao dependem da lista de produtos).
   Todas devolvem 1 se o valor e valido e 0 se e invalido. */

int validarPositivoInt(int numero);          /* numero > 0  */
int validarPositivoFloat(float numero);      /* numero > 0  */
int validarNaoNegativoInt(int numero);       /* numero >= 0 */
int validarIntervalo(int numero, int min, int max); /* min <= numero <= max */
int validarTextoPreenchido(char texto[]);    /* tem algum caractere diferente de espaco */
int validarPrateleira(char prateleira);      /* A, B, C ou D (maiuscula ou minuscula) */

#endif
