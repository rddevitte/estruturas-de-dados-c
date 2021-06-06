/**
 * @file nodopilha.c
 * @brief Definição das funções de criação e destruição do nodo da pilha.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../../common/macros.h"
#include "../inc/nodopilha.h"

NodoPilha criaNodoPilha(void* elem, NodoPilha abaixo)
{
    NodoPilha np;

    np = (NodoPilha)malloc(sizeof(struct nodoPilha));

    if (np) {
        np->elem = elem;
        np->abaixo = abaixo;
    } else {
        PRINT_ERR("erro ao alocar espaço de memória para o nodo da pilha");
    }

    return np;
}

void destroiNodoPilha(NodoPilha* np, void (*destroiElem)(void**))
{
    if (!np) {
        PRINT_ERR("ponteiro p/ o nodo da pilha nulo!");
        return;
    }

    if (!(*np)) {
        PRINT_ERR("nodo da pilha nulo!");
        return;
    }

    if (destroiElem)
        destroiElem(&((*np)->elem));

    free(*np);
    *np = NULL;

    return;
}
