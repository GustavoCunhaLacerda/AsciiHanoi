#include <stdio.h>
#include "./RenderizarTorres.h"

int main () {
    
    int tamTotal = 4;

    int v_torre1[] = {0, 3, 5, 7}; 
    int v_torre2[] = {0, 0, 0, 3}; 
    int v_torre3[] = {0, 0, 0, 1}; 

    printf("TORRE DE HANOI !!\n");

    renderizar_torres(tamTotal, v_torre1, v_torre2, v_torre3);
    return 0;
}