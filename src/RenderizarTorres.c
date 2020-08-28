#include <stdio.h>

void exibe_torres() {
    int tamTotal, linha, espaco, simbolo;
    tamTotal = 4;

    for (linha = 0; linha <= tamTotal; linha++) {

        Torre1:
            // exibindo espaços
            for (espaco = 0; espaco < tamTotal - linha; espaco++)
                putchar(' ');
            // exibindo simbolos
            for (simbolo = 0; simbolo < (2*linha) - 1; simbolo++)
                putchar('*');
            // exibindo espaços
            for (espaco = 0; espaco < tamTotal - linha; espaco++)
                putchar(' ');
        
        putchar(' ');
        Torre2:
            // exibindo espaços
            for (espaco = 0; espaco < tamTotal - linha; espaco++)
                putchar(' ');
            // exibindo simbolos
            for (simbolo = 0; simbolo < (2*linha) - 1; simbolo++)
                putchar('*');
            // exibindo espaços
            for (espaco = 0; espaco < tamTotal - linha; espaco++)
                putchar(' ');
        
        putchar(' ');
        Torre3:
            // exibindo espaços
            for (espaco = 0; espaco < tamTotal - linha; espaco++)
                putchar(' ');
            // exibindo simbolos
            for (simbolo = 0; simbolo < (2*linha) - 1; simbolo++)
                putchar('*');
            // exibindo espaços
            for (espaco = 0; espaco < tamTotal - linha; espaco++)
                putchar(' ');

        putchar('\n');
    }
    puts("---1--- ---2--- ---3---");
}

int main () {

    exibe_torres();

    return 0;
}
