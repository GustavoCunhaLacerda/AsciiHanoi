#pragma once

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
void show_tower(short totalDiscs, short v_tower1[], short v_tower2[], short v_tower3[]);

