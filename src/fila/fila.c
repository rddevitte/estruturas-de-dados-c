/**
 * @file fila.c
 * @brief Definição das funções para criação, operações e destruição da fila.
 */
#include <stdio.h>
#include <stdlib.h>

#include "common/macros.h"
#include "fila/fila.h"
#include "fila/nodofila.h"

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
        PRINT_ERR("não foi possível alocar memória para o nodo da fila!");
    }

    return f;
}

void enfileira(Fila f, void* elem)
{
    NodoFila nf;

    if (!f) {
        PRINT_ERR("fila nula!");
        return;
    }

    nf = criaNodoFila(elem);

    if (!nf) {
        PRINT_ERR("não foi possível alocar memória para o nodo da fila!");
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
        PRINT_ERR("fila nula!");
        return NULL;
    }

    // Caso 1: fila vazia
    if (f->tam == 0) { // ou (f->frente == f->atras && f->frente == NULL) {
        PRINT_ERR("fila vazia");
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
        PRINT_ERR("fila nula!");
        return;
    }

    if (f->tam == 0) {
        PRINT_ERR("fila vazia");
        return;
    }

    if (acessaElem == NULL) {
        PRINT_ERR("parâmetro acessaElem nulo");
        return;
    }

    for (aux = f->frente; aux != NULL; aux = aux->ant)
        acessaElem(aux->elem);

    return;
}

int tamanho(Fila f)
{
    if (!f) {
        PRINT_ERR("fila nula!");
        return -1;
    }

    return f->tam;
}

void destroiFila(Fila* f, void (*destroiElem)(void**))
{
    NodoFila aux;

    if (!f) {
        PRINT_ERR("ponteiro p/ fila nulo!");
        return;
    }

    if (!(*f)) {
        PRINT_ERR("fila nula!");
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
