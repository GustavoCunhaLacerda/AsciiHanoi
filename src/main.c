#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/ShowTowers.h"
#include "../includes/TowerAndDisc.h"

typedef enum bool { true = 1, false = 0 } Bool;

/** 
 * Estrutura para armazenar os dados do jogo/partida
 */
typedef struct gameStatusStruct
{
    /*@{*/
    Tower** towers; /**< Torres da partida */
    Disc** discs; /**< Discos da partida */
    short totalDiscs; /**< Número total de discos na partida  */
    short movesCount; /**< Quantidade de jogadas realizadas na partida */
    Bool gameOver; /**< Verificação de game over */
    /*@}*/

} GameStatus;


// Prototipos
void clean_screen();
void clean_buffer();
void title();

char menu();
void instructions();
void credits();

GameStatus* setup_game();
void update_game(GameStatus* gameStatus);
void end_game(GameStatus* gameStatus);

int main()
{
    char menuOp;

    Start:
        clean_screen();
        menuOp = menu();
        if(menuOp == '1')
        {
            GameStatus* gameStatus = setup_game();
            update_game(gameStatus);
            end_game(gameStatus);
        }
        else if (menuOp == '2')
        {
            instructions();
        }
        else if (menuOp == '3')
        {
            credits();
        }
        else
        {
            return 0;
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
void title()
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
    title();

    // Escolhas possíveis do menu - ligado ao switch case da func main()
    puts("1 - Jogar");
    puts("2 - Instrucoes");
    puts("3 - Creditos");
    puts("0 - Sair");

    // Scan da scolha do usuário
    char menuOption = '\0';
    while (!((int)menuOption >= 48 && (int)menuOption <= 51))
    {
        printf("\nSelecione uma opcao: ");
        menuOption = getchar();
        clean_buffer();
    }

    // putchar(menuOption);
    return menuOption;
}

// Função que exibe a tela de instruções do jogo
void instructions()
{
    clean_screen();
    title();
    printf("\
->Instruções:\n\n\
O objetivo do jogo e mover os discos da torre <1> para a torre <3>.\n\
O jogador nao pode colocar um disco maior em cima de um menor.\n\
O jogador so pode mover um disco por vez.\n\
    \nAperte [ENTER] para voltar.");
    clean_buffer();
}

// Função que exibe a tela de creditos do jogo
void credits()
{
    clean_screen();
    title();
    printf("\
->Créditos:\n\n\
Trabalho final apresentado a disciplina de Estrutura de Dados.\n\
Professor: Fontes\n\
Aluno: Gustavo C. Lacerda\n\n\
Codigo font disponivel em: https://github.com/GustavoCunhaLacerda/AsciiHanoi\n\
    \nAperte [ENTER] para voltar.");
    clean_buffer();
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
    gameStatus->towers = malloc(sizeof(Tower*) * 3);
    for (short i = 0; i < 3; i++)
        gameStatus->towers[i] = create_tower();

    // Declaração e criação dos discos
    gameStatus->discs = malloc(sizeof(Disc*) * gameStatus->totalDiscs);
    for (short i = 0; i < gameStatus->totalDiscs; i++)
        gameStatus->discs[i] = create_disc( (2*i) + 1 );

    // Empilhamento dos discos na torre 1 (torres[0])
    for (short i = gameStatus->totalDiscs - 1; i >= 0; i--)
        push(gameStatus->towers[0], gameStatus->discs[i]);


    return gameStatus;
}

// Função que controla as atualizações e mecânicas do jogo
void update_game(GameStatus* gameStatus)
{
    while (!gameStatus->gameOver) 
    {
        clean_screen();
        printf("Numero de jogadas: %hd\n", gameStatus->movesCount);
        
        // Renderização das torres
        show_tower(gameStatus->totalDiscs, formatted_tower_vector(gameStatus->towers[0], gameStatus->totalDiscs), formatted_tower_vector(gameStatus->towers[1], gameStatus->totalDiscs), formatted_tower_vector(gameStatus->towers[2], gameStatus->totalDiscs));
        putchar('\n');

        // Scan da torre font do disco
        char fontChar = '\0', targetChar = '\0';
        while (!((int)fontChar >= 49 && (int)fontChar <= 51))
        {
            printf("Mover de [1-3]: ");
            fontChar = getchar();
            clean_buffer();
        }

        // Scan da torre destiny do disco
        while (!((int)targetChar >= 49 && (int)targetChar <= 51))
        {
            printf("Para [1-3]: ");
            targetChar = getchar();
            clean_buffer();
        }

        // Conversão do número das torres font e destiny de <char> para <short>
        short font = (int)fontChar - 48, destiny = (int)targetChar - 48;
        
        // Verificação da jogada
        // Verifica se a torre font está vazia
        if ( !is_empty(gameStatus->towers[font-1]) )  
        {
            // Verifica se o disco será empilhado em um disco maior ou torre vazia
            if ( (peek(gameStatus->towers[font-1]) <= peek(gameStatus->towers[destiny-1]) || peek(gameStatus->towers[destiny-1]) == -1) )
            {
                push(gameStatus->towers[destiny-1], pop(gameStatus->towers[font-1]));
                gameStatus->movesCount++;
            }
            else
            {
                printf("Movimento invalido! Nao se pode colocar um disco maior em cima de um menor.\nPressione [ENTER] para fazer outra jogada.");
                clean_buffer();
            }
        }
        else
        {
            printf("Movimento invalido! Torre fonte vazia.\nPressione [ENTER] para fazer outra jogada.");
            clean_buffer();
        }

        if (is_empty(gameStatus->towers[0]) && is_empty(gameStatus->towers[1]))
            gameStatus->gameOver = true;
    }
}

// Função de finalização da partida
void end_game(GameStatus* gameStatus)
{
    system("clear || cls");
    printf("Parabens, voce conseguiu com %d jogadas!\n", gameStatus->movesCount);
    show_tower(gameStatus->totalDiscs, formatted_tower_vector(gameStatus->towers[0], gameStatus->totalDiscs), formatted_tower_vector(gameStatus->towers[1], gameStatus->totalDiscs), formatted_tower_vector(gameStatus->towers[2], gameStatus->totalDiscs));
        putchar('\n');
    
    //
    // Liberação das alocações
    //
    for (short i = 0; i < 3; i++)
        free_tower(gameStatus->towers[i]);
    free(gameStatus->towers);
    for (short i = 0; i < gameStatus->totalDiscs; i++)
        free_disc(gameStatus->discs[i]);
    free(gameStatus->discs);
    free(gameStatus);

    //
    // Retorno ao menu principal
    //
    printf("Pressione [ENTER] para voltar para o menu inicial.");
    while ((getchar()) != '\n');
}