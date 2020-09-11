#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/RenderizarTorres.h"
#include "../includes/Torre.h"

typedef enum bool { true = 1, false = 0 } Bool;

typedef struct gameStatusStruct
{
    Torre* towers[3];
    Disco** discs;
    short totalDiscs;
    short movesCount;
    Bool gameOver;

} GameStatus;


// Prototipos
void clean_screen();
void clean_buffer();
void titulo();

char menu();
void instructions();
void credits();

GameStatus* setup_game();
void update_game(GameStatus* gameStatus);
void end_game(GameStatus* gameStatus);

// Função principal de controle do jogo
int main()
{
    Start:

    switch (menu())
    {
        case '1':
            GameStatus* gameStatus = setup_game();
            update_game(gameStatus);
            end_game(gameStatus);
        break;
        
        case '2':
            instructions();
        break;

        case '3':
            credits();
        break;

        case '0':
            exit(EXIT_SUCCESS);
        break;

        default:
            puts("Erro nas opcoes de menu!!");
            exit(EXIT_FAILURE);
        break;
    }
    
    goto Start;   
}

// Função que limpa o buffer do teclado
void clean_buffer()
{
    while ((getchar()) != '\n');
}

// Função que limpa a tela
void clean_screen() 
{
    system("clear || cls");
}

// Função que exibe o titulo/logo do jogo
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
    puts("2 - Instrucoes");
    puts("3 - Creditos");
    puts("0 - Sair");

    // Scan da scolha do usuário
    char opcaoMenu = '\0';
    while (!((int)opcaoMenu >= 48 && (int)opcaoMenu <= 51))
    {
        printf("\nSelecione uma opcao: ");
        opcaoMenu = getchar();
        clean_buffer();
    }

    // putchar(opcaoMenu);
    return opcaoMenu;
}

// Função que exibe a tela de instruções do jogo
void exibir_instrucoes()
{
    exibir_titulo();
    printf("\
->Instruções:\n\n\
O objetivo do jogo e mover os discos da torre <1> para a torre <3>.\n\
O jogador nao pode colocar um disco maior em cima de um menor.\n\
O jogador so pode mover um disco por vez.\n\
    \nAperte [ENTER] para voltar.");
    while ((getchar()) != '\n');
    main();
}

// Função que exibe a tela de creditos do jogo
void credits()
{
    clean_screen();
    exibir_titulo();
    printf("\
->Créditos:\n\n\
Trabalho final apresentado a disciplina de Estrutura de Dados.\n\
Professor: Fontes\n\
Aluno: Gustavo C. Lacerda\n\n\
Codigo fonte disponivel em: https://github.com/GustavoCunhaLacerda/AsciiHanoi\n\
    \nAperte [ENTER] para voltar.");
    while ((getchar()) != '\n');
    main();
}

//Função que realiza o setup inicial do game
GameStatus* setup_game() {
    GameStatus* gameStatus = malloc(sizeof(GameStatus));

    // Scan da quantidade total de discos
    char totalDiscsChar = '\n';
    while (!((int)totalDiscsChar >= 49 && (int)totalDiscsChar <= 57))
    {
        printf("Informe a quantidade de discos [1-9]: ");
        totalDiscsChar = getchar();
        clean_buffer();
    }
    
    // Declaração das variáveis gerais do jogo
    gameStatus->movesCount = 0;
    gameStatus->gameOver = false;
    gameStatus->totalDiscs = (int)totalDiscsChar - 48;

    // Criação do vetor de torres
    // Torre** torres = malloc(sizeof(Torre*) * 3);
    for (short i = 0; i < 3; i++)
        gameStatus->towers[i] = cria_torre();

    // Declaração e criação dos discos
    gameStatus->discs = malloc(sizeof(Disco*) * gameStatus->totalDiscs);
    for (short i = 0; i < gameStatus->totalDiscs; i++)
        gameStatus->discs[i] = cria_disco( (2*i) + 1 );

    // Empilhamento dos discos na torre 1 (torres[0])
    for (short i = gameStatus->totalDiscs - 1; i >= 0; i--)
        push(gameStatus->towers[0], gameStatus->discs[i]);


    return gameStatus;
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
        system("clear || cls");
        printf("Numero de jogadas: %hd\n", jogadas);
        
        // Renderização das torres
        renderizar_torres(qteTotalDeDiscos, vetor_torre(torres[0], qteTotalDeDiscos), vetor_torre(torres[1], qteTotalDeDiscos), vetor_torre(torres[2], qteTotalDeDiscos));
        putchar('\n');

        // Scan da torre fonte do disco
        char fonteChar = '\0', destinoChar = '\0';
        while (!((int)fonteChar >= 49 && (int)fonteChar <= 51))
        {
            printf("Mover de [1-3]: ");
            fonteChar = getchar();
            while ((getchar()) != '\n');
        }

        // Scan da torre destino do disco
        while (!((int)destinoChar >= 49 && (int)destinoChar <= 51))
        {
            printf("Para [1-3]: ");
            destinoChar = getchar();
            while ((getchar()) != '\n');
        }

        // fflush(stdin);
        
        
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
                printf("Movimento invalido! Nao se pode colocar um disco maior em cima de um menor.\nPressione [ENTER] para fazer outra jogada.");
                while ((getchar()) != '\n');
            }
        }
        else
        {
            printf("Movimento invalido! Torre fonte vazia.\nPressione [ENTER] para fazer outra jogada.");
            while ((getchar()) != '\n');
        }
    }

    //
    // Fim de jogo
    //
    system("clear || cls");
    printf("Parabens, voce conseguiu com %d jogadas!\n", jogadas);
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



