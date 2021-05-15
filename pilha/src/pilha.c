/**
 * @file pilha.c
 * @brief Definição das funções de criação, operações e destruição da
 * estrutura pilha.
 */
#include "../inc/pilha.h"
#include "../inc/nodopilha.h"
#include <stdio.h>
#include <stdlib.h>

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

    p = malloc(sizeof(struct pilha));

    if (p) {
        p->topo = NULL;
        p->tam = 0;
    } else {
        fprintf(stderr,
            "%s:%d: erro ao alocar espaço de memória para a pilha\n",
            __func__, __LINE__);
    }

    return p;
}

void push(Pilha p, void* elem)
{
    NodoPilha np;

    if (!p) {
        fprintf(stderr, "%s:%d: pilha nula\n", __func__, __LINE__);
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
        fprintf(stderr, "%s:%d: pilha nula\n", __func__, __LINE__);
        return NULL;
    }

    if (p->tam < 1) {
        fprintf(stderr, "%s:%d: pilha vazia\n", __func__, __LINE__);
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
        fprintf(stderr, "%s:%d: pilha nula\n", __func__, __LINE__);
        return;
    }

    if (p->tam < 1) {
        fprintf(stderr, "%s:%d: pilha vazia\n", __func__, __LINE__);
        return;
    }

    if (!acessaElem) {
        fprintf(stderr, "%s:%d: ponteiro p/ a função acessaElem() nulo!\n",
            __func__, __LINE__);
        return;
    }

    for (aux = p->topo; aux != NULL; aux = aux->abaixo)
        acessaElem(aux->elem);

    return;
}

int tamanho(Pilha p)
{
    if (!p) {
        fprintf(stderr, "%s:%d: pilha nula\n", __func__, __LINE__);
        return -1;
    }

    return p->tam;
}

void destroiPilha(Pilha* p, void (*destroiElem)(void**))
{
    NodoPilha aux;

    if (!p) {
        fprintf(stderr, "%s:%d: ponteiro p/ pilha nulo!\n", __func__, __LINE__);
        return;
    }

    if (!(*p)) {
        fprintf(stderr, "%s:%d: pilha nula\n", __func__, __LINE__);
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
        printf("%s:%d: pilha vazia\n", __func__, __LINE__);
    }

    free(*p);
    *p = NULL;

    return;
}
