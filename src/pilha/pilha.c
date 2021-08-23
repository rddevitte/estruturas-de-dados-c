/**
 * @file pilha.c
 * @brief Definição das funções de criação, operações e destruição da
 * estrutura pilha.
 */
#include <stdio.h>
#include <stdlib.h>

#include "common/macros.h"
#include "pilha/nodopilha.h"
#include "pilha/pilha.h"

/** Estrutura da pilha */
struct pilha {
    /** Ponteiro para o nodo do topo da pilha */
    NodoPilha topo;
    /** Tamanho (núm. elems.) da pílha */
    int tam;
};

Pilha criaPilha(void)
{
    Pilha p;

    p = (Pilha)malloc(sizeof(struct pilha));

    if (p) {
        p->topo = NULL;
        p->tam = 0;
    } else {
        PRINT_ERR("erro ao alocar espaço de memória para a pilha");
    }

    return p;
}

void push(Pilha p, void* elem)
{
    NodoPilha np;

    if (!p) {
        PRINT_ERR("pilha nula");
        return;
    }

    np = criaNodoPilha(elem, p->topo);

    if (np) {
        p->topo = np;
        p->tam++;
    }

    return;
}

void* pop(Pilha p)
{
    void* elem;
    NodoPilha novoTopo;

    if (!p) {
        PRINT_ERR("pilha nula");
        return NULL;
    }

    if (p->tam < 1) {
        PRINT_ERR("pilha vazia");
        return NULL;
    }

    elem = p->topo->elem;
    novoTopo = p->topo->abaixo;
    destroiNodoPilha(&(p->topo), NULL);
    p->topo = novoTopo;
    p->tam--;

    return elem;
}

void percorre(Pilha p, void (*acessaElem)(void*))
{
    NodoPilha aux;

    if (!p) {
        PRINT_ERR("pilha nula");
        return;
    }

    if (p->tam < 1) {
        PRINT_ERR("pilha vazia");
        return;
    }

    if (!acessaElem) {
        PRINT_ERR("ponteiro p/ a função acessaElem() nulo!");
        return;
    }

    for (aux = p->topo; aux != NULL; aux = aux->abaixo)
        acessaElem(aux->elem);

    return;
}

int tamanho(Pilha p)
{
    if (!p) {
        PRINT_ERR("pilha nula");
        return -1;
    }

    return p->tam;
}

void destroiPilha(Pilha* p, void (*destroiElem)(void**))
{
    NodoPilha aux;

    if (!p) {
        PRINT_ERR("ponteiro p/ pilha nulo!");
        return;
    }

    if (!(*p)) {
        PRINT_ERR("pilha nula");
        return;
    }

    if ((*p)->tam > 0) {
        while ((*p)->topo != NULL) {
            aux = (*p)->topo->abaixo;
            destroiNodoPilha(&((*p)->topo), destroiElem);
            (*p)->topo = aux;
            (*p)->tam--;
        }
    } else {
        PRINT_DBG("pilha vazia");
    }

    free(*p);
    *p = NULL;

    return;
}
