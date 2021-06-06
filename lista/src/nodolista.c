/**
 * @file nodolista.c
 * @brief Definição das funções do nodo da lista.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../../common/macros.h"
#include "../inc/nodolista.h"

NodoLista criaNodoLista(void* elem, NodoLista ant, NodoLista prox)
{
    NodoLista nl;

    nl = (NodoLista)malloc(sizeof(struct nodoLista));

    if (nl) {
        nl->elem = elem;
        nl->ant = ant;
        nl->prox = prox;
    } else {
        PRINT_ERR("não foi possível alocar memória para o nodo da lista!");
    }

    return nl;
}

void destroiNodoLista(NodoLista* nl, void (*destroiElem)(void**))
{
    if (!nl) {
        PRINT_ERR("ponteiro p/ o nodo da lista nulo!");
        return;
    }

    if (!(*nl)) {
        PRINT_ERR("nodo da lista nulo!");
        return;
    }

    if (destroiElem)
        destroiElem(&((*nl)->elem));

    free(*nl);
    *nl = NULL;

    return;
}
