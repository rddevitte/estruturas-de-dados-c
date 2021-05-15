/**
 * @file nodolista.h
 * @brief Declaração da estrutura e das funções de criação e "destruição"
 * (desalocação) no nodo da lista encadeada circular.
 */
#ifndef NODOLISTA_H
#define NODOLISTA_H

/** Estrutura do nodo da lista */
struct nodoLista {
    /** Ponteiro para o elemento armazenado no nodo */
    void* elem;
    /** Ponteiro para os nodos próximo e anterior a ele */
    struct nodoLista *ant, *prox;
};

/** Def. de tipo NodoLista */
typedef struct nodoLista* NodoLista;

/**
 * Cria (aloca) um nodo da lista.
 * @param elem O elemento a ser armazenado no nodo
 * @param ant Ponteiro para o nodo anterior
 * @param prox Ponteiro para o próx. nodo
 */
NodoLista criaNodoLista(void* elem, NodoLista ant, NodoLista prox);

/**
 * "Destroi" (desaloca) um nodo da lista.
 * @param nl O ponteiro para o nodo da lista
 * @param destroiElem O ponteiro para uma função que desaloca o elemento
 * armazenado no nodo
 */
void destroiNodoLista(NodoLista* nl, void (*destroiElem)(void**));

#endif // NODOLISTA_H
