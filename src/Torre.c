#include <stdlib.h>
#include "../includes/Torre.h"

// Tipos exportados
struct torre
{
    short qteDiscos;
    Disco* topo;
};

struct disco
{
    short tamanho;
    Disco* prox;
};

// Funções exportadas

//
// Torre
//

// Criar torre
Torre* cria_torre()
{
    Torre* t = malloc(sizeof(Torre));
    t->topo = NULL;
    t->qteDiscos = 0;
    return t;
} 

// Libera a memória alocada pela torre
void libera_torre(Torre* t) 
{
    free(t);
}

// Verifica se a torre está vazia
short esta_vazia(Torre* t)
{
    if (t->qteDiscos == 0)
        return 1;
    else
        return 0;
}

// Insere disco no topo da torre
void push(Torre* t, Disco* d)
{
    if (t->topo == NULL)
    {
        d->prox = NULL;
        t->topo = d;
    } 
    else
    {
        d->prox = t->topo;
        t->topo = d;
    }
    t->qteDiscos += 1;
}

// Retorna e remove o disco do topo da torre
Disco* pop(Torre* t)
{
    Disco* dt = t->topo;
    t->topo = dt->prox;
    dt->prox = NULL;
    t->qteDiscos -= 1;

    return dt;
}

// "Olha" o topo da torre sem remover
short peek(Torre* t)
{
    if (t->qteDiscos == 0)
        return -1;
    
    return t->topo->tamanho;
}

// Retorna um vetor formatado para renderização da torre
short* vetor_torre(Torre* t, short tamVetorFinal)
{
    short* v_torre = malloc(sizeof(short)*(tamVetorFinal));
    Disco* d = t->topo;
    for (short i = 0; i < tamVetorFinal; i++)
    {
        if(tamVetorFinal - i > t->qteDiscos)
            v_torre[i] = 0;
        else
        {
            v_torre[i] = d->tamanho;
            d = d->prox; 
        }
    }
    return v_torre;
}

// 
// Disco
// 

// Cria disco
Disco* cria_disco(short tam)
{
    Disco* d = malloc(sizeof(Disco));
    d->tamanho = tam;
    d->prox = NULL;

    return d;
}

// Libera disco
void libera_disco(Disco* d)
{
    free(d);
}