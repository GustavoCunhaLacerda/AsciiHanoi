#include <stdio.h>
#include <stdlib.h>
#include "../includes/ShowTowers.h"

/**
 * Função que printa determinada linha de uma torre.
 * @param discSize Tamanho do disco da linha.
 * @param line Numero da linha.
 * @param totalDiscs Numero total de discos em jogo.
 */
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

/**
 * Função que printa a label da torre de acordo com o tamanho de discos total.
 * @param totalDiscs Numero total de discos em jogo.
 * @param towerLabel Caractere que define a label da torre. Deve ter apenas um caractere descritivo ('1', '2', 'A', 'B', ...).
 */
void show_tower_label(short totalDiscs, char towerLabel) {
    for (short i = 0; i < totalDiscs-1; i++)
        putchar('<');
    putchar(towerLabel);
    for (short i = 0; i < totalDiscs-1; i++)
        putchar('>');
    putchar(' ');
} 

/**
 * Função que printa o tabuleiro levando em conta a quantidade total de discos.
 * Cada torre é renderizada com base em um vetor de tamanho igual ao totalDiscs.
 * Espaços vazios dos vetores torres devem possuir zero para manter o padrão.
 * Abaixo da torre é costruído a label de forma dinâmica.
 * @param totalDiscs Numero total de discos em jogo.
 * @param v_tower1 Vetor formatado formado a partir do estado atual da torre 1.
 * @param v_tower2 Vetor formatado formado a partir do estado atual da torre 2.
 * @param v_tower3 Vetor formatado formado a partir do estado atual da torre 3.
 */
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



