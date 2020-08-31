#include <stdio.h>
#include "../includes/RenderizarTorres.h"
#include "../includes/Torre.h"

int main () {
    printf("Torre de Hanoi\n");

    short tamTotal = 4;

    Torre* t1 = cria_torre();
    for (short i = tamTotal; i > 0; i--)
        push(t1, (i << 1)-1);
    Torre* t2 = cria_torre();
    Torre* t3 = cria_torre();

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
    


    liberar_torre(t1);
    liberar_torre(t2);
    liberar_torre(t3);
}