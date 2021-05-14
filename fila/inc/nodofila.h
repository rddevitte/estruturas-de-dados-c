/**
 * nodofila.h - Declaração da estrutura e das funções de criação e destruição do
 * nodo da fila.
 */
#ifndef NODOFILA_H
#define NODOFILA_H

/** Estrutura do nodo da fila */
struct nodoFila {
    /** Elemento a ser armazenado no nodo da fila */
    void* elem;
    /** Ponteiro para o nodo anterior da fila */
    struct nodoFila* ant;
};

typedef struct nodoFila* NodoFila;

NodoFila criaNodoFila(void*);

void destroiNodoFila(NodoFila*, void (*)(void**));

#endif // NODOFILA_H