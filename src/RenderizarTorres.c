#include <stdio.h>
#include <stdlib.h>

// Função que printa determinada linha da torre
void renderizar_linha_torre(short tamDisco, short linha, short tamTotal) {
    // exibindo espaços
    if (tamDisco == 0) putchar(' ');
    for (short espaco = 0; espaco < tamTotal - (1 + (tamDisco >> 1)); espaco++)
        putchar(' ');
    // exibindo simbolos
    for (short simbolo = 0; simbolo < tamDisco; simbolo++)
        putchar('*');
    // exibindo espaços
    for (short espaco = 0; espaco < tamTotal - (1 + (tamDisco >> 1)); espaco++)
        putchar(' ');
    putchar(' ');
}

// Função que printa a label da torre de acrdo com o tamanho total
// A label deve ter apenas um caractere descritivo ('1', '2' ou 'A', 'B')
void renderizar_label(short tamTotal, char labelTorre) {
    for (short i = 0; i < tamTotal-1; i++)
        putchar('-');
    putchar(labelTorre);
    for (short i = 0; i < tamTotal-1; i++)
        putchar('-');
    putchar(' ');
} 

// Função que printa o tabuleiro levando em conta o tamanho total das torres.
// Cada torre é renderizada com base em um vetor de tamanho igual ao tamTotal (espaços vazios de torres devem possuir zero para manter o padrão)
// Abaixo da torre é costruído a label de forma dinâmica
void renderizar_torres(short tamTotal, short* v_torre1, short* v_torre2, short* v_torre3) {
    
    // Torres
    for (short linha = 0; linha < tamTotal; linha++) {
        Torre1: renderizar_linha_torre(v_torre1[linha], linha, tamTotal);
        Torre2: renderizar_linha_torre(v_torre2[linha], linha, tamTotal);
        Torre3: renderizar_linha_torre(v_torre3[linha], linha, tamTotal);
        putchar('\n');
    }

    // Labels
    renderizar_label(tamTotal, '1');
    renderizar_label(tamTotal, '2');
    renderizar_label(tamTotal, '3');
    putchar('\n');

    // Liberação dos vetores
    free(v_torre1);
    free(v_torre2);
    free(v_torre3);
}



