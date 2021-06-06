/**
 * @file nodofila.c
 * @brief Definição das funções de criação e "destruição" (desalocação) do
 * nodo da fila.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../../common/macros.h"
#include "../inc/nodofila.h"

NodoFila criaNodoFila(void* elem)
{
    NodoFila nf;

    nf = (NodoFila)malloc(sizeof(struct nodoFila));

    if (nf) {
        nf->elem = elem;
        nf->ant = NULL;
    } else {
        PRINT_ERR("não foi possível alocar memória para o nodo da fila!");
    }

    return nf;
}

void destroiNodoFila(NodoFila* nf, void (*destroiElem)(void**))
{
    if (!nf) {
        PRINT_ERR("ponteiro p/ o nodo da fila nulo!");
        return;
    }

    if (!(*nf)) {
        PRINT_ERR("nodo da fila nulo!");
    }

    if (destroiElem)
        destroiElem(&((*nf)->elem));

    free(*nf);
    *nf = NULL;

    return;
}
