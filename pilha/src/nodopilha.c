/**
 * nodopilha.c - Definição das funções de criação e destruição do nodo da pilha.
 */
#include "../inc/nodopilha.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Aloca (cria) um novo nodo da pilha.
 * @param elem O elemento a ser empilhado
 * @param abaixo O nodo do topo da pilha que estará abaixo dele após o novo nodo
 * ser o topo
 * @return O endereço alocado para o nodo da pilha
 */
NodoPilha criaNodoPilha(void *elem, NodoPilha abaixo)
{
    NodoPilha np;

    np = malloc(sizeof(struct nodoPilha));

    if (!np) {
        np->elem = elem;
        np->abaixo = abaixo;
    }
    else {
        fprintf(stderr,
                "%s:%d: erro ao alocar espaço de memória para o nodo da pilha",
                __func__, __LINE__);
    }

    return np;
}

/**
 * Desaloca ("destroi") o nodo da pilha.
 * @param np O endereço do nodo da pilha na memória
 * @param destroiElem O ponteiro para uma função que desaloca o elemento
 * da memória armazenado no nodo da pilha
 */
void destroiNodoPilha(NodoPilha *np, void (*destroiElem)(void **))
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
