/**
 * nodolista.h - Declaração da estrutura e das funções de criação e "destruição"
 * (desalocação) no nodo da lista encadeada circular.
 */
#ifndef NODOLISTA_H
#define NODOLISTA_H

/** Estrutura do nodo da lista */
struct nodoLista {
    /** Ponteiro para o elemento armazenado no nodo */
    void *elem;
    /** Ponteiro para os nodos próximo e anterior a ele */
    struct nodoLista *ant, *prox;
};

typedef struct nodoLista *NodoLista;

NodoLista criaNodoLista(void *, NodoLista, NodoLista);

void destroiNodoLista(NodoLista *, void (*)(void **));

#endif // NODOLISTA_H