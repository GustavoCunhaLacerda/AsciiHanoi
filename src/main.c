#include <stdio.h>
#include "../includes/RenderizarTorres.h"
#include "../includes/Torre.h"

int main () {
    printf("Torre de Hanoi\n");

    short tamTotal = 4;

    Disco* d1 = cria_disco(1);
    Disco* d3 = cria_disco(3);
    Disco* d5 = cria_disco(5);
    Disco* d7 = cria_disco(7);

    Torre* t1 = cria_torre();
    Torre* t2 = cria_torre();
    Torre* t3 = cria_torre();

    push(t1, d7);
    push(t1, d5);
    push(t1, d3);
    push(t1, d1);

    Torre* torres[] = {t1, t2, t3};

    while ( esta_vazia(torres[0]) == 1 || esta_vazia(torres[1]) == 1) {
        renderizar_torres(tamTotal, vetor_torre(torres[0], tamTotal), vetor_torre(torres[1], tamTotal), vetor_torre(torres[2], tamTotal));

        short fonte, destino;
        printf("Mover de: ");
        scanf("%hi", &fonte);
        printf("Para: ");
        scanf("%hi", &destino);

        push(torres[destino-1], pop(torres[fonte-1]));
    }
    printf("Parabéns, você conseguiu !\n\n");
    renderizar_torres(tamTotal, vetor_torre(torres[0], tamTotal), vetor_torre(torres[1], tamTotal), vetor_torre(torres[2], tamTotal));
    


    libera_torre(t1);
    libera_torre(t2);
    libera_torre(t3);
    libera_disco(d1);
    libera_disco(d3);
    libera_disco(d5);
    libera_disco(d7);
}