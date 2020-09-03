#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/RenderizarTorres.h"
#include "../includes/Torre.h"

void exibir_titulo();
void exibir_instrucoes();
void exibir_creditos();

char menu();
void game();
void game_over();

// Função principal de controle do jogo
int main()
{
    system("clear");
    switch (menu())
    {
    case '0':
        exit(0);
        break;
    
    case '1':
        game();
        break;
    
    case '2':
        exibir_instrucoes();
        break;

    case '3':
        exibir_creditos();
        break;

    default:
        puts("Erro nas opções de menu!!");
        exit(0);
        break;
    }

    return 0;   
}

// Função que exibe o titulo/ logo do jogo
void exibir_titulo()
{
    // AsciiHanoi
    puts("\n\
 /\\   _  _ o o |_|  _. ._   _  o\n\
/--\\ _> (_ | | | | (_| | | (_) |\n\
    ");
}

// Função que exibe a tela de instruções do jogo
void exibir_instrucoes()
{
    system("clear");
    exibir_titulo();
    printf("\
->Instruções:\n\n\
O objetivo do jogo é mover os discos da torre <1> para a torre <3>.\n\
Você não pode colocar um disco maior em cima de um menor.\n\
Você só pode mover um disco por vez.\n\
    \nAperte [ENTER] para voltar.");
    while ((getchar()) != '\n');
    main();
}

// Função que exibe a tela de creditos do jogo
void exibir_creditos()
{
    system("clear");
    exibir_titulo();
    printf("\
->Créditos:\n\n\
Trabalho final apresentado à disciplina de Estrutura de Dados.\n\
Professor: Fontes\n\
Aluno: Gustavo C. Lacerda\n\n\
Código fonte disponível em: https://github.com/GustavoCunhaLacerda/AsciiHanoi\n\
    \nAperte [ENTER] para voltar.");
    while ((getchar()) != '\n');
    main();
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

// Função que executa as mecanicas do jogo
void game() 
{
    //
    // Declaração das variáveis gerais do jogo
    //
    
    short qteTotalDeDiscos, jogadas = 0;

    // Scan da quantidade total de discos
    char qteTotalDeDiscosChar = '\n';
    while (!((int)qteTotalDeDiscosChar >= 49 && (int)qteTotalDeDiscosChar <= 57))
    {
        printf("Informe a quantidade de discos [1-9]: ");
        qteTotalDeDiscosChar = getchar();
        while ((getchar()) != '\n');
    }
    qteTotalDeDiscos = (int)qteTotalDeDiscosChar - 48;

    // Declaração e criação do vetor de torres
    Torre** torres = malloc(sizeof(Torre*) * 3);
    for (short i = 0; i < 3; i++)
        torres[i] = cria_torre();

    // Declaração e criação dos discos
    Disco** discos = malloc(sizeof(Disco*) * qteTotalDeDiscos);
    for (short i = 0; i < qteTotalDeDiscos; i++)
        discos[i] = cria_disco( (2*i) + 1 );
    // Empilhamento dos discos na torre 1 (torres[0])
    for (short i = qteTotalDeDiscos - 1; i >= 0; i--)
        push(torres[0], discos[i]);

    //
    // Loop principal do game
    //
    while (esta_vazia(torres[0]) == 0 || esta_vazia(torres[1]) == 0) 
    {
        system("clear");
        printf("Número de jogadas: %hd\n", jogadas);
        
        // Renderização das torres
        renderizar_torres(qteTotalDeDiscos, vetor_torre(torres[0], qteTotalDeDiscos), vetor_torre(torres[1], qteTotalDeDiscos), vetor_torre(torres[2], qteTotalDeDiscos));
        putchar('\n');

        // Scan da torre fonte do disco
        char fonteChar = '\0', destinoChar = '\0';
        while (!((int)fonteChar >= 49 && (int)fonteChar <= 52))
        {
            printf("Mover de [1-3]: ");
            fonteChar = getchar();
            while ((getchar()) != '\n');
        }

        // Scan da torre destino do disco
        while (!((int)destinoChar >= 49 && (int)destinoChar <= 52))
        {
            printf("Para [1-3]: ");
            destinoChar = getchar();
            while ((getchar()) != '\n');
        }
        
        // Conversão do número das torres fonte e destino de <char> para <short>
        short fonte = (int)fonteChar - 48, destino = (int)destinoChar - 48;
        
        // Verificação da jogada
        // Verifica se a torre fonte está vazia
        if ( !esta_vazia(torres[fonte-1]) )  
        {
            // Verifica se o disco será empilhado em um disco maior ou torre vazia
            if ( (peek(torres[fonte-1]) <= peek(torres[destino-1]) || peek(torres[destino-1]) == -1) )
            {
                push(torres[destino-1], pop(torres[fonte-1]));
                jogadas++;
            }
            else
            {
                printf("Movimento inválido! Não se pode colocar um disco maior em cima de um menor.\nPressione [ENTER] para fazer outra jogada.");
                while ((getchar()) != '\n');
            }
        }
        else
        {
            printf("Movimento inválido! Torre fonte vazia.\nPressione [ENTER] para fazer outra jogada.");
            while ((getchar()) != '\n');
        }
    }

    //
    // Fim de jogo
    //
    system("clear");
    printf("Parabéns, você conseguiu com %d jogadas!\n", jogadas);
    renderizar_torres(qteTotalDeDiscos, vetor_torre(torres[0], qteTotalDeDiscos), vetor_torre(torres[1], qteTotalDeDiscos), vetor_torre(torres[2], qteTotalDeDiscos));
    

    //
    // Liberação das alocações
    //
    for (short i = 0; i < 3; i++)
        libera_torre(torres[i]);
    free(torres);
    for (short i = 0; i < qteTotalDeDiscos; i++)
        libera_disco(discos[i]);
    free(discos);


    //
    // Retorno ao menu principal
    //
    printf("Pressione [ENTER] para voltar para o menu inicial.");
    while ((getchar()) != '\n');
    main();
}



