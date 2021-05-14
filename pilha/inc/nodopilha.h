/**
 * nodopilha.h - Declaração da estrutura e das funções de alocação e
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

typedef struct nodoPilha* NodoPilha;

NodoPilha criaNodoPilha(void*, NodoPilha);

void destroiNodoPilha(NodoPilha*, void (*)(void**));

#endif // NODOPILHA_H