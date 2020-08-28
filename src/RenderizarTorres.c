#include <stdio.h>
#include <stdlib.h>

void renderizar_linha_torre(short tam_disco, short linha, short tamTotal) {
    // exibindo espaços
    if (tam_disco == 0) putchar(' ');
    for (short espaco = 0; espaco < tamTotal - (1 + tam_disco/2); espaco++)
        putchar(' ');
    // exibindo simbolos
    for (short simbolo = 0; simbolo < tam_disco; simbolo++)
        putchar('*');
    // exibindo espaços
    for (short espaco = 0; espaco < tamTotal - (1 + tam_disco/2); espaco++)
        putchar(' ');

    putchar(' ');
}

void renderizar_label(short tamTotal, char label_torre) {
    for (short i = 0; i < tamTotal-1; i++)
        putchar('-');
    putchar(label_torre);
    for (short i = 0; i < tamTotal-1; i++)
        putchar('-');
    putchar(' ');
} 

void renderizar_torres(short tamTotal, short v_torre1[], short v_torre2[], short v_torre3[]) {
   
    for (short linha = 0; linha < tamTotal; linha++) {
        Torre1: renderizar_linha_torre(v_torre1[linha], linha, tamTotal);
        Torre2: renderizar_linha_torre(v_torre2[linha], linha, tamTotal);
        Torre3: renderizar_linha_torre(v_torre3[linha], linha, tamTotal);
        putchar('\n');
    }

    renderizar_label(tamTotal, '1');
    renderizar_label(tamTotal, '2');
    renderizar_label(tamTotal, '3');
    putchar('\n');

    free(v_torre1);
    free(v_torre2);
    free(v_torre3);
}

