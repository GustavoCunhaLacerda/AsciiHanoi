#include <stdio.h>
#include <stdlib.h>
#include "../includes/ShowTowers.h"

// Função que printa determinada line da torre
void show_tower_line(short discSize, short line, short totalDiscs) {
    // exibindo espaços
    if (discSize == 0) putchar(' ');
    for (short space = 0; space < totalDiscs - (1 + (discSize >> 1)); space++)
        putchar(' ');
    // exibindo simbolos
    for (short symbol = 0; symbol < discSize; symbol++)
        putchar('-');
    // exibindo espaços
    for (short space = 0; space < totalDiscs - (1 + (discSize >> 1)); space++)
        putchar(' ');
    putchar(' ');
}

// Função que printa a label da torre de acrdo com o tamanho total
// A label deve ter apenas um caractere descritivo ('1', '2' ou 'A', 'B')
void show_tower_label(short totalDiscs, char labelTorre) {
    for (short i = 0; i < totalDiscs-1; i++)
        putchar('<');
    putchar(labelTorre);
    for (short i = 0; i < totalDiscs-1; i++)
        putchar('>');
    putchar(' ');
} 

// Função que printa o tabuleiro levando em conta o tamanho total das torres.
// Cada torre é renderizada com base em um vetor de tamanho igual ao totalDiscs (espaços vazios de torres devem possuir zero para manter o padrão)
// Abaixo da torre é costruído a label de forma dinâmica
void show_tower(short totalDiscs, short* v_tower1, short* v_tower2, short* v_tower3) {
    
    // Torres
    for (short line = 0; line < totalDiscs; line++) {
        Tower1: show_tower_line(v_tower1[line], line, totalDiscs);
        Tower2: show_tower_line(v_tower2[line], line, totalDiscs);
        Tower3: show_tower_line(v_tower3[line], line, totalDiscs);
        putchar('\n');
    }

    // Labels
    show_tower_label(totalDiscs, '1');
    show_tower_label(totalDiscs, '2');
    show_tower_label(totalDiscs, '3');
    putchar('\n');

    // Liberação dos vetores
    free(v_tower1);
    free(v_tower2);
    free(v_tower3);
}


