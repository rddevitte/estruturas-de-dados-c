/**
 * @file nodofila.c
 * @brief Definição das funções de criação e "destruição" (desalocação) do
 * nodo da fila.
 */
#include "../inc/nodofila.h"
#include <stdio.h>
#include <stdlib.h>

NodoFila criaNodoFila(void* elem)
{
    NodoFila nf;

    nf = malloc(sizeof(struct nodoFila));

    if (nf) {
        nf->elem = elem;
        nf->ant = NULL;
    } else {
        fprintf(stderr,
            "%s:%c: não foi possível alocar memória para o nodo da fila!\n",
            __func__, __LINE__);
    }

    return nf;
}

void destroiNodoFila(NodoFila* nf, void (*destroiElem)(void**))
{
    if (!nf) {
        fprintf(stderr, "%s:%c: ponteiro p/ o nodo da fila nulo!\n", __func__,
            __LINE__);
        return;
    }

    if (!(*nf)) {
        fprintf(stderr, "%s:%c: nodo da fila nulo!\n", __func__, __LINE__);
        return;
    }

    if (destroiElem)
        destroiElem(&((*nf)->elem));

    free(*nf);
    *nf = NULL;

    return;
}
