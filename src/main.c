#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/RenderizarTorres.h"
#include "../includes/Torre.h"

void exibir_titulo();
void game();
char menu();

int main()
{
    system("clear");
    // menu();
    switch (menu())
    {
    case '0':
        exit(0);
        break;
    
    case '1':
        game();

    default:
        puts("Erro nas opções de menu!!");
        exit(0);
        break;
    }

    return 0;   
}

void exibir_titulo()
{
    // AsciiHanoi
    puts("\n\
 /\\   _  _ o o |_|  _. ._   _  o\n\
/--\\ _> (_ | | | | (_| | | (_) |\n\
    ");
}

// Exibição de opções e retorno da seleção do menu
char menu()
{
    exibir_titulo();

    // Escolhas possíveis do menu - ligado ao switch case da func main()
    puts("1 - Jogar");
    puts("2 - Instruções");
    puts("3 - Créditos");
    puts("0 - Sair");

    // Scan da scolha do usuário
    char opcaoMenu = '\0';
    while (!((int)opcaoMenu >= 48 && (int)opcaoMenu <= 52))
    {
        printf("\nSelecione uma opção: ");
        opcaoMenu = getchar();
        //(MEDIDA ANTI-USUÁRIO) loop para limpar buffer caso o usuário digite uma string 
        while ((getchar()) != '\n');
    }

    // putchar(opcaoMenu);
    return opcaoMenu;
}

void game() 
{
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

    while (esta_vazia(torres[0]) == 1 || esta_vazia(torres[1]) == 1) {
        system("clear");
        printf("Número de jogadas: 999\n");
        // exibir_titulo();
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

    return;
}



