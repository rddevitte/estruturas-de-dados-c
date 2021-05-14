/**
 * pilha.h - Declaração das funções para a pilha (criação, operações e
 * destruição).
 */
#ifndef PILHA_H
#define PILHA_H

struct pilha;

typedef struct pilha* Pilha;

Pilha criaPilha(void);

void push(Pilha, void*);

void* pop(Pilha);

void percorre(Pilha, void (*)(void*));

int tamanho(Pilha);

void destroiPilha(Pilha*, void (*)(void**));

#endif // PILHA_H