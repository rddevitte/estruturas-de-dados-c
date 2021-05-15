/**
 * @file pilha.h
 * @brief Declaração das funções para a pilha (criação, operações e
 * destruição).
 */
#ifndef PILHA_H
#define PILHA_H

/** Declaração da estrutura da pilha */
struct pilha;

/** Def. de tipo Pilha */
typedef struct pilha* Pilha;

/**
 * Cria (aloca) nova pilha.
 * @return O endereço de memória alocado para a nova pilha
 */
Pilha criaPilha(void);

/**
 * Empilha (push) um elemento na pilha.
 * @param p Ponteiro para a pilha
 * @param elem Elemento a ser empilhado
 */
void push(Pilha p, void* elem);

/**
 * Desempilha (pop) um elemento da pilha.
 * @param p A pilha
 * @return o elemento do topo da pilha, desempilhado
 */
void* pop(Pilha p);

/**
 * Percorre ("traverse") os nodos da pilha, do topo para a base,
 * e aplica a função acessaElem a cada elemento do nodo da pilha.
 * @param p A pilha
 * @param acessaElem O ponteiro para uma função a ser aplicada ao elemento do
 * nodo empilhado
 */
void percorre(Pilha p, void (*acessaElem)(void*));

/**
 * Retorna o tamanho da pilha (núm. de elementos empilhados).
 * @param p A pilha
 * @return Tamanho da pilha
 */
int tamanho(Pilha p);

/**
 * Desaloca ("destroi") os elementos da pilha e a pilha em si.
 * @param p Ponteiro para a pilha
 * @param destroiElem Ponteiro para a função que desaloca o elemento do
 * nodo
 */
void destroiPilha(Pilha* p, void (*destroiElem)(void**));

#endif // PILHA_H
