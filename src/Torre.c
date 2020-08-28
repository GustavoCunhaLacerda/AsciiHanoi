#include <stdlib.h>
#include <stdio.h>
#include "./Torre.h"

// Tipos exportados
struct torre {
    short qte_discos;
    Disco* topo;
};

struct disco {
    short tamanho;
    Disco* prox;
};

// Funções exportadas
Torre* cria_torre() {
    Torre* t = malloc(sizeof(Torre));
    t->topo = NULL;
    t->qte_discos = 0;
    return t;
} 

void liberar_torre(Torre* t) {
    Disco* disco_tmp = t->topo;
    while (disco_tmp != NULL) {
        Disco* aux = disco_tmp->prox;
        free(disco_tmp);
        disco_tmp = aux;
    }
    free(t);
}

short esta_vazia(Torre* t) {
    if (t->qte_discos == 0)
        return 0;
    else
        return 1;
}

void push(Torre* t, short qte_discos) {
    Disco* nova = malloc(sizeof(Disco));
    nova->tamanho = qte_discos;
    if (t->topo == NULL) {
        nova->prox = NULL;
        t->topo = nova;
    } else {
        nova->prox = t->topo;
        t->topo = nova;
    }
    t->qte_discos += 1;
}

short pop(Torre* t) {
    Disco* dt = t->topo;
    short qte_discos = dt->tamanho;
    t->topo = dt->prox;
    free(dt);
    t->qte_discos -= 1;
    return qte_discos;
}

short peek(Torre* t) {
    return t->topo->tamanho;
}

void print_torre(Torre* t) {
    Disco* d = t->topo;
    while (d != NULL) {
       printf("%i ", d->tamanho);
       d = d->prox;
    }
    putchar('\n');
}

short* vetor_torre(Torre* t, short tam_total) {
    short* v_torre = malloc(sizeof(short)*(tam_total));
    Disco* d = t->topo;
    for (short i = 0; i < tam_total; i++) {
        if(tam_total - i > t->qte_discos)
            v_torre[i] = 0;
        else {
            v_torre[i] = d->tamanho;
            d = d->prox; 
        }
    }

    return v_torre;
}
