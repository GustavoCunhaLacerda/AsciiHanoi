#pragma once

// tipo exportados
typedef struct disc Disc;
typedef struct tower Tower;

// Funções exportadas

//
// Torre
//

// Criar torre
Tower* create_tower();

// Libera a memória alocada pela torre
void free_tower(Tower* t);

// Verifica se a torre está vazia
short is_empty(Tower* t);

// Insere disco no topo da torre
void push(Tower* t, Disc* dics);

// Retorna e remove o disco do topo da torre
Disc* pop(Tower* t);

// Retorna o topo da torre sem remover
short peek(Tower* t);

// Retorna um vetor formatado para renderização da torre
short* formatted_tower_vector(Tower* t, short finalVectorSize);

// 
// Dicso
// 

// Cria disco
Disc* create_disc(short size);

// Libera disco
void free_disc(Disc* d);
