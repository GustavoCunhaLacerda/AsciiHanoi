#include <stdio.h>

void renderizar_linha_torre(int tam_disco, int linha, int tamTotal, int vazia) {
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

int[] pilha_para_vetor() {
    // Transformando uma pilha de dados em um vetor formatado para render
}

void renderizar_torres(int tamTotal, int v_torre1[], int v_torre2[], int v_torre3[]) {
   
    for (int linha = 0; linha < tamTotal; linha++) {
        Torre1: renderizar_linha_torre(v_torre1[linha], linha, tamTotal);
        Torre2: renderizar_linha_torre(v_torre2[linha], linha, tamTotal);
        Torre3: renderizar_linha_torre(v_torre3[linha], linha, tamTotal);
        putchar('\n');
    }
    puts("---1--- ---2--- ---3---");
}

