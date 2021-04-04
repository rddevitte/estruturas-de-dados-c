/**
 * pilha.c - Definição das funções de criação, operações e destruição da
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

/**
 * Cria (aloca) nova pilha.
 * @return O endereço de memória alocado para a nova pilha
 */
Pilha criaPilha(void)
{
    Pilha p;

    p = malloc(sizeof(struct pilha));

    if (!p) {
        fprintf(stderr,
                "%s:%d: erro ao alocar espaço de memória para a pilha\n",
                __func__, __LINE__);
        return NULL;
    }

    p->topo = NULL;
    p->tam = 0;

    return p;
}

/**
 * Empilha (push) um elemento na pilha.
 * @param p Ponteiro para a pilha
 * @param elem Elemento a ser empilhado
 */
void push(Pilha p, void *elem)
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

/**
 * Desempilha (pop) um elemento da pilha.
 * @param p A pilha
 * @return o elemento do topo da pilha, desempilhado
 */
void *pop(Pilha p)
{
    void *elem;
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

/**
 * Percorre ("traverse") os nodos da pilha, do topo para a base,
 * e aplica a função acessaElem a cada elemento do nodo da pilha.
 * @param p A pilha
 * @param acessaElem O ponteiro para uma função a ser aplicada ao elemento do
 * nodo empilhado
 */
void percorre(Pilha p, void (*acessaElem)(void *))
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

/**
 * Retorna o tamanho da pilha (núm. de elementos empilhados).
 * @return Tamanho da pilha
 */
int tamanho(Pilha p)
{
    if (!p) {
        fprintf(stderr, "%s:%d: pilha nula\n", __func__, __LINE__);
        return -1;
    }

    return p->tam;
}

/**
 * Desaloca ("destroi") os elementos da pilha e a pilha em si.
 * @param p Ponteiro para a pilha
 * @param destroiElem Ponteiro para a função que desaloca o elemento do
 * nodo
 */
void destroiPilha(Pilha *p, void (*destroiElem)(void **))
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