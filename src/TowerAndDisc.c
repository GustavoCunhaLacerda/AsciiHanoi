#include <stdlib.h>
#include "../includes/TowerAndDisc.h"

// Tipos exportados
struct tower
{
    short countDiscs;
    Disc* top;
};

struct disc
{
    short size;
    Disc* next;
};

// Funções exportadas

//
// Torre
//

// Criar torre
Tower* create_tower()
{
    Tower* t = malloc(sizeof(Tower));
    t->top = NULL;
    t->countDiscs = 0;
    return t;
} 

// Libera a memória alocada pela torre
void free_tower(Tower* t) 
{
    free(t);
}

// Verifica se a torre está vazia
short is_empty(Tower* t)
{
    if (t->countDiscs == 0)
        return 1;
    else
        return 0;
}

// Insere disco no top da torre
void push(Tower* t, Disc* d)
{
    if (t->top == NULL)
    {
        d->next = NULL;
        t->top = d;
    } 
    else
    {
        d->next = t->top;
        t->top = d;
    }
    t->countDiscs += 1;
}

// Retorna e remove o disco do top da torre
Disc* pop(Tower* t)
{
    Disc* dt = t->top;
    t->top = dt->next;
    dt->next = NULL;
    t->countDiscs -= 1;

    return dt;
}

// "Olha" o top da torre sem remover
short peek(Tower* t)
{
    if (t->countDiscs == 0)
        return -1;
    
    return t->top->size;
}

// Retorna um vetor formatado para renderização da torre
short* formatted_tower_vector(Tower* t, short finalVectorSize)
{
    short* v_torre = malloc(sizeof(short)*(finalVectorSize));
    Disc* d = t->top;
    for (short i = 0; i < finalVectorSize; i++)
    {
        if(finalVectorSize - i > t->countDiscs)
            v_torre[i] = 0;
        else
        {
            v_torre[i] = d->size;
            d = d->next; 
        }
    }
    return v_torre;
}

// 
// Disc
// 

// Cria disco
Disc* create_disc(short size)
{
    Disc* d = malloc(sizeof(Disc));
    d->size = size;
    d->next = NULL;

    return d;
}

// Libera disco
void free_disc(Disc* d)
{
    free(d);
}