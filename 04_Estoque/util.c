#include <ctype.h>
#include "util.h"

int validarPositivoInt(int numero) {
    return numero > 0;
}

int validarPositivoFloat(float numero) {
    return numero > 0;
}

int validarNaoNegativoInt(int numero) {
    return numero >= 0;
}

int validarIntervalo(int numero, int min, int max) {
    return numero >= min && numero <= max;
}

int validarTextoPreenchido(char texto[]) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (!isspace((unsigned char) texto[i])) {
            return 1;
        }
    }
    return 0;
}

int validarPrateleira(char prateleira) {
    return prateleira == 'A' || prateleira == 'B' ||
           prateleira == 'C' || prateleira == 'D' ||
           prateleira == 'a' || prateleira == 'b' ||
           prateleira == 'c' || prateleira == 'd';
}
