/**
 * @file fila.c
 * @brief Definição das funções para criação, operações e destruição da fila.
 */
#include "../inc/fila.h"
#include "../inc/nodofila.h"
#include <stdio.h>
#include <stdlib.h>

/** Estrutura da fila*/
struct fila {
    /** Ponteiros para os nodos primeiro e último da fila */
    NodoFila frente, atras;
    /** Tamanho da fila (qtde. de elems. enfileirados) */
    int tam;
};

Fila criaFila(void)
{
    Fila f;

    f = (Fila)malloc(sizeof(struct fila));

    if (f) {
        f->frente = f->atras = NULL;
        f->tam = 0;
    } else {
        fprintf(stderr,
            "%s:%d: não foi possível alocar memória para o nodo da fila!\n",
            __func__, __LINE__);
    }

    return f;
}

void enfileira(Fila f, void* elem)
{
    NodoFila nf;

    if (!f) {
        fprintf(stderr, "%s:%d: fila nula!\n", __func__, __LINE__);
        return;
    }

    nf = criaNodoFila(elem);

    if (!nf) {
        fprintf(stderr,
            "%s:%d: não foi possível alocar memória para o nodo da fila!\n",
            __func__, __LINE__);
        return;
    }

    // Caso 1: fila vazia
    if (f->tam == 0) {
        f->frente = f->atras = nf;
    }
    // Caso 2: um ou mais elementos na fila
    else if (f->tam > 0) {
        f->atras->ant = nf;
        f->atras = nf;
    }

    f->tam++;

    return;
}

void* desenfileira(Fila f)
{
    NodoFila aux;
    void* elem;

    if (!f) {
        fprintf(stderr, "%s:%d: fila nula!\n", __func__, __LINE__);
        return NULL;
    }

    // Caso 1: fila vazia
    if (f->tam == 0) { // ou (f->frente == f->atras && f->frente == NULL) {
        fprintf(stderr, "%s:%d: fila vazia\n", __func__, __LINE__);
        return NULL;
    }

    elem = f->frente->elem;

    // Caso 2: único elemento na fila
    if (f->tam == 1) { // ou if (f->frente == f->atras) {
        destroiNodoFila(&(f->frente), NULL);
        f->frente = f->atras = NULL;
    }

    // Caso 3: mais de um elemento na fila
    else if (f->tam > 1) { // ou if (f->frente != f->atras) {
        aux = f->frente->ant;
        destroiNodoFila(&(f->frente), NULL);
        f->frente = aux;
    }

    f->tam--;

    return elem;
}

void percorre(Fila f, void (*acessaElem)(void*))
{
    NodoFila aux;

    if (!f) {
        fprintf(stderr, "%s:%d: fila nula!\n", __func__, __LINE__);
        return;
    }

    if (f->tam == 0) {
        fprintf(stderr, "%s:%d: fila vazia\n", __func__, __LINE__);
        return;
    }

    if (acessaElem == NULL) {
        fprintf(stderr, "%s:%d: parâmetro acessaElem nulo\n", __func__,
            __LINE__);
        return;
    }

    for (aux = f->frente; aux != NULL; aux = aux->ant)
        acessaElem(aux->elem);

    return;
}

int tamanho(Fila f)
{
    if (!f) {
        fprintf(stderr, "%s:%d: fila nula!\n", __func__, __LINE__);
        return -1;
    }

    return f->tam;
}

void destroiFila(Fila* f, void (*destroiElem)(void**))
{
    NodoFila aux;

    if (!f) {
        fprintf(stderr, "%s:%d: ponteiro p/ fila nulo!\n", __func__, __LINE__);
        return;
    }

    if (!(*f)) {
        fprintf(stderr, "%s:%d: fila nula!\n", __func__, __LINE__);
        return;
    }

    if ((*f)->tam > 0) {
        while ((*f)->frente != NULL) {
            aux = (*f)->frente->ant;
            destroiNodoFila(&((*f)->frente), destroiElem);
            (*f)->frente = aux;
            (*f)->tam--;
        }
    }

    free(*f);
    *f = NULL;

    return;
}
