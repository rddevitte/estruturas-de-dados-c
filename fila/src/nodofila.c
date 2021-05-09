/**
 * nodofila.c - Definição das funções de criação e "destruição" (desalocação) do
 * nodo da fila.
 */
#include "../inc/nodofila.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Cria um novo nodo da fila.
 * @param elem O elemento a ser armazenado no nodo
 * @return O endereço para o nodo fila alocado na memória
 */
NodoFila criaNodoFila(void *elem)
{
    NodoFila nf;

    nf = malloc(sizeof(struct nodoFila));

    if (nf) {
        nf->elem = elem;
        nf->ant = NULL;
    }
    else {
        fprintf(stderr,
                "%s:%c: não foi possível alocar memória para o nodo da fila!\n",
                __func__, __LINE__);
    }

    return nf;
}

/**
 * Destroi (desaloca) o nodo da fila da memória.
 * @param nf O ponteiro para o nodo da fila
 * @param destroiElem O ponteiro para uma função que desaloca o elemento
 * armazenado da memória
 */
void destroiNodoFila(NodoFila *nf, void (*destroiElem)(void **))
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
