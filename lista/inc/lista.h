/**
 * lista.h - Declaração da estrutura e das funções (criação, operações e
 * destruição) da lista. Trata-se de uma lista duplamente encadeada circular.
 */
#ifndef LISTA_H
#define LISTA_H

struct lista;

typedef struct lista* Lista;

Lista criaLista(void);

void insereInicio(Lista, void*);
void insereFim(Lista, void*);
void inserePos(Lista, int, void*);
void insereOrd(Lista, void*, int (*)(void*, void*));

int tamanho(Lista);

void* elemInicio(Lista);
void* elemFim(Lista);
void* elemPos(Lista, int);

void percorre(Lista, void (*)(void*));
void percorreInv(Lista, void (*)(void*));

void removeInicio(Lista, void (*)(void**));
void removeFim(Lista, void (*)(void**));
void removePos(Lista, int, void (*)(void**));
int removeCond(Lista, int (*)(void*), void (*)(void**));

void destroiLista(Lista*, void (*)(void**));

#endif // LISTA_H