/**
 * nodolista.c - Definição das funções do nodo da lista.
 */
#include "../inc/nodolista.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Cria (aloca) um nodo da lista.
 * @param elem O elemento a ser armazenado no nodo
 * @param ant Ponteiro para o nodo anterior
 * @param prox Ponteiro para o próx. nodo
 */
NodoLista criaNodoLista(void* elem, NodoLista ant, NodoLista prox)
{
    NodoLista nl;

    nl = malloc(sizeof(struct nodoLista));

    if (nl) {
        nl->elem = elem;
        nl->ant = ant;
        nl->prox = prox;
    } else {
        fprintf(
            stderr,
            "%s:%d: não foi possível alocar memória para o nodo da lista!\n",
            __func__, __LINE__);
    }

    return nl;
}

/**
 * "Destroi" (desaloca) um nodo da lista.
 * @param lista O ponteiro para o nodo da lista
 * @param destroiElem O ponteiro para uma função que desaloca o elemento
 * armazenado no nodo
 */
void destroiNodoLista(NodoLista* nl, void (*destroiElem)(void**))
{
    if (!nl) {
        fprintf(stderr, "%s:%d: ponteiro p/ o nodo da lista nulo!\n", __func__,
            __LINE__);
        return;
    }

    if (!(*nl)) {
        fprintf(stderr, "%s:%d: nodo da lista nulo!\n", __func__, __LINE__);
        return;
    }

    if (destroiElem)
        destroiElem(&((*nl)->elem));

    free(*nl);
    *nl = NULL;

    return;
}
