// tipo exportados
typedef struct disco Disco;
typedef struct torre Torre;

// Funções exportadas

//
// Torre
//

// Criar torre
Torre* cria_torre();

// Libera a memória alocada pela torre
void libera_torre(Torre* t);

// Verifica se a torre está vazia
short esta_vazia(Torre* t);

// Insere disco no topo da torre
void push(Torre* t, Disco* disco);

// Retorna e remove o disco do topo da torre
Disco* pop(Torre* t);

// Retorna o topo da torre sem remover
short peek(Torre* t);

// Retorna um vetor formatado para renderização da torre
short* vetor_torre(Torre* t, short tamVetorFinal);

// 
// Disco
// 

// Cria disco
Disco* cria_disco(short tam);

// Libera disco
void libera_disco(Disco* d);
