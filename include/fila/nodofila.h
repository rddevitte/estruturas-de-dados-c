/**
 * @file nodofila.h
 * @brief Declaração da estrutura e das funções de criação e destruição do
 * nodo da fila.
 */
#ifndef NODOFILA_H
#define NODOFILA_H

#ifdef __cplusplus
extern "C" {
#endif

/** Estrutura do nodo da fila */
struct nodoFila {
    /** Elemento a ser armazenado no nodo da fila */
    void* elem;
    /** Ponteiro para o nodo anterior da fila */
    struct nodoFila* ant;
};

/** Def. de tipo NodoFila */
typedef struct nodoFila* NodoFila;

/**
 * Cria um novo nodo da fila.
 * @param elem O elemento a ser armazenado no nodo
 * @return O endereço para o nodo fila alocado na memória
 */
NodoFila criaNodoFila(void* elem);

/**
 * Destroi (desaloca) o nodo da fila da memória.
 * @param nf O ponteiro para o nodo da fila
 * @param destroiElem O ponteiro para uma função que desaloca o elemento
 * armazenado da memória
 */
void destroiNodoFila(NodoFila* nf, void (*destroiElem)(void**));

#ifdef __cplusplus
}
#endif

#endif // NODOFILA_H
