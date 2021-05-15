/**
 * @file nodopilha.c
 * @brief Definição das funções de criação e destruição do nodo da pilha.
 */
#include "../inc/nodopilha.h"
#include <stdio.h>
#include <stdlib.h>

NodoPilha criaNodoPilha(void* elem, NodoPilha abaixo)
{
    NodoPilha np;

    np = malloc(sizeof(struct nodoPilha));

    if (!np) {
        np->elem = elem;
        np->abaixo = abaixo;
    } else {
        fprintf(stderr,
            "%s:%d: erro ao alocar espaço de memória para o nodo da pilha",
            __func__, __LINE__);
    }

    return np;
}

void destroiNodoPilha(NodoPilha* np, void (*destroiElem)(void**))
{
    if (!np) {
        fprintf(stderr, "%s:%d: ponteiro p/ o nodo da pilha nulo!\n", __func__,
            __LINE__);
        return;
    }

    if (!(*np)) {
        fprintf(stderr, "%s:%d: nodo da pilha nulo!\n", __func__, __LINE__);
        return;
    }

    if (destroiElem)
        destroiElem(&((*np)->elem));

    free(*np);
    *np = NULL;

    return;
}
