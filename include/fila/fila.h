/**
 * @file fila.h
 * @brief Declaração das funções de criação, operações e destruição da
 * estrutura fila.
 */
#ifndef FILA_H
#define FILA_H

#ifdef __cplusplus
extern "C" {
#endif

/** Declaração da estrutura da fila */
struct fila;

/** Def. de tipo Fila */
typedef struct fila* Fila;

/**
 * Cria uma fila vazia.
 * @return o endereço de memória alocado para a fila
 */
Fila criaFila(void);

/**
 * Inclui (enfileira) um elemento no final da fila.
 * @param f A fila
 * @param elem O elemento a ser enfileirado
 */
void enfileira(Fila f, void* elem);

/**
 * Retira (desenfileira) um elemento do início da fila.
 * @param f A fila
 * @return O elemento desenfileirado
 */
void* desenfileira(Fila f);

/**
 * Percorre (traverse) os nodos da fila, do início ao fim, aplicando a função
 * acessaElem a cada elemento.
 * @param f A fila
 * @param acessaElem Ponteiro para uma função de acesso e manipulação do
 * elemento
 */
void percorre(Fila f, void (*acessaElem)(void*));

/**
 * Retorna o tamanho da fila (núm. de elementos enfileirados).
 * @param f A fila
 * @return Tamanho da fila
 */
int tamanho(Fila f);

/**
 * Desaloca ("destroi") a fila e seus elementos.
 * @param f O ponteiro para a fila
 * @param destroiElem O ponteiro para a função que desaloca o elemento da fila
 */
void destroiFila(Fila* f, void (*destroiElem)(void**));

#ifdef __cplusplus
}
#endif

#endif // FILA_H
