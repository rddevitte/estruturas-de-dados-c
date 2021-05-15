/**
 * @file letra.h
 * @brief Declaração das funções auxiliares para criação, impressão e
 * desalocação dinâmica de caracteres. Usado no teste da lista.
 */
#ifndef LETRA_H
#define LETRA_H

void* criaLetra(char);
void imprimeLetra(void*);
void destroiLetra(void**);
int comparaLetras(void*, void*);
int condLetraEntreDeF(void*);
int condLetraA(void*);
int condLetraJ(void*);

#endif // LETRA_H
