/**
 * @file nodolista.c
 * @brief Definição das funções do nodo da lista.
 */
#include "../inc/nodolista.h"
#include <stdio.h>
#include <stdlib.h>

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
