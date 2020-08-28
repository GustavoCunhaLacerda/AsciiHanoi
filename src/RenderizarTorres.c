#include <stdio.h>


void renderizar_linha_torre(int tam_disco, int linha, int tamTotal) {
    // exibindo espaços
    if (tam_disco == 0) putchar(' ');
    for (int espaco = 0; espaco < tamTotal - (1 + tam_disco/2); espaco++)
        putchar(' ');
    // exibindo simbolos
    for (int simbolo = 0; simbolo < tam_disco; simbolo++)
        putchar('*');
    // exibindo espaços
    for (int espaco = 0; espaco < tamTotal - (1 + tam_disco/2); espaco++)
        putchar(' ');

    putchar(' ');
}

void exibe_torres() {
    int tamTotal, linha, espaco, simbolo;
    tamTotal = 4;

    int torre1[] = {0, 3, 5, 7}; 
    int torre2[] = {0, 0, 0, 3}; 
    int torre3[] = {0, 0, 0, 1}; 

    for (linha = 0; linha < tamTotal; linha++) {
        Torre1: renderizar_linha_torre(torre1[linha], linha, tamTotal);
        Torre2: renderizar_linha_torre(torre2[linha], linha, tamTotal);
        Torre3: renderizar_linha_torre(torre3[linha], linha, tamTotal);
        putchar('\n');
    }
    puts("---1--- ---2--- ---3---");
}

int main () {

    exibe_torres();

    return 0;
}
