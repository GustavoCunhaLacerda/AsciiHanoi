#include <stdio.h>

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

void renderizar_torres(short tamTotal, short v_torre1[], short v_torre2[], short v_torre3[]) {
   
    for (short linha = 0; linha < tamTotal; linha++) {
        Torre1: renderizar_linha_torre(v_torre1[linha], linha, tamTotal);
        Torre2: renderizar_linha_torre(v_torre2[linha], linha, tamTotal);
        Torre3: renderizar_linha_torre(v_torre3[linha], linha, tamTotal);
        putchar('\n');
    }
    puts("---1--- ---2--- ---3---");
}

