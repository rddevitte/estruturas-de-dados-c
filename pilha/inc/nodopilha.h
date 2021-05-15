/**
 * @file nodopilha.h
 * @brief Declaração da estrutura e das funções de alocação e
 * "destruição" (desalocação) do nodo da pilha.
 */
#ifndef NODOPILHA_H
#define NODOPILHA_H

/** Estrutura do nodo pilha */
struct nodoPilha {
    /** Elemento a ser armazenado no topo da pilha */
    void* elem;
    /** Ponteiro para o nodo abaixo dele */
    struct nodoPilha* abaixo;
};

/** Def. de tipo NodoPilha */
typedef struct nodoPilha* NodoPilha;

/**
 * Aloca (cria) um novo nodo da pilha.
 * @param elem O elemento a ser empilhado
 * @param abaixo O nodo do topo da pilha que estará abaixo dele após o novo nodo
 * ser o topo
 * @return O endereço alocado para o nodo da pilha
 */
NodoPilha criaNodoPilha(void* elem, NodoPilha abaixo);

/**
 * Desaloca ("destroi") o nodo da pilha.
 * @param np O endereço do nodo da pilha na memória
 * @param destroiElem O ponteiro para uma função que desaloca o elemento
 * da memória armazenado no nodo da pilha
 */
void destroiNodoPilha(NodoPilha* np, void (*destroiElem)(void**));

#endif // NODOPILHA_H
