/**
 * @file nums.c
 * @brief Definição das funções auxiliares para criação, impressão e
 * desalocação dinâmica de inteiros. Usado nos testes da pilha e da fila.
 */
#include "nums.h"
#include <stdio.h>
#include <stdlib.h>

int* criaNum(int n)
{
    int* num;
    num = (int*)malloc(sizeof(int));

    if (num)
        *num = n;

    return num;
}

void imprimeNum(void* num)
{
    if (num)
        printf("num = %p, *num = %d\n", num, *(int*)num);

    return;
}

void destroiNum(void** num)
{
    if (*num) {
        free(*num);
        *num = 0;
    }

    return;
}
