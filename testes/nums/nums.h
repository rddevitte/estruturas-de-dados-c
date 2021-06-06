/**
 * @file nums.h
 * @brief Declaração das funções auxiliares para criação, impressão e
 * desalocação dinâmica de inteiros. Usado nos testes da pilha e da fila.
 */
#ifndef NUMS_H
#define NUMS_H

#ifdef __cplusplus
extern "C" {
#endif

int* criaNum(int);
void imprimeNum(void*);
void destroiNum(void**);

#ifdef __cplusplus
}
#endif

#endif // NUMS_H
