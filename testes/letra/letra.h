/**
 * @file letra.h
 * @brief Declaração das funções auxiliares para criação, impressão e
 * desalocação dinâmica de caracteres. Usado no teste da lista.
 */
#ifndef LETRA_H
#define LETRA_H

#ifdef __cplusplus
extern "C" {
#endif

void* criaLetra(char);
void imprimeLetra(void*);
void destroiLetra(void**);
int comparaLetras(void*, void*);
int condLetraEntreDeF(void*);
int condLetraA(void*);
int condLetraJ(void*);

#ifdef __cplusplus
}
#endif

#endif // LETRA_H
