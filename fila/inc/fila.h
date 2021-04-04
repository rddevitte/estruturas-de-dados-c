/**
 * fila.h - Declaração das funções de criação, operações e destruição da
 * estrutura fila.
 */
#ifndef FILA_H
#define FILA_H

struct fila;

typedef struct fila *Fila;

Fila criaFila(void);

void enfileira(Fila, void *);

void *desenfileira(Fila);

void percorre(Fila, void (*)(void *));

int tamanho(Fila);

void destroiFila(Fila *, void (*)(void **));

#endif // FILA_H