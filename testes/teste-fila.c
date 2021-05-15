/**
 * @file teste-fila.c
 * @brief Testa a estrutura de fila e suas operações.
 */
#include "../fila/inc/fila.h"
#include "./nums/nums.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Fila nums;
    int* num;

    setlocale(LC_ALL, "pt_BR.utf8");

    // Parte 1: fila nula
    nums = NULL;

    enfileira(nums, NULL);
    desenfileira(nums);
    percorre(nums, NULL);
    printf("Tam. fila: %d\n", tamanho(nums));
    destroiFila(NULL, NULL);
    destroiFila(&nums, NULL);

    putchar('\n');

    // Parte 2: fila vazia
    nums = criaFila();

    if (!nums) {
        fprintf(stderr, "Erro ao criar fila!\n");
        return 1;
    }

    desenfileira(nums);
    percorre(nums, NULL);
    printf("Tam. fila: %d\n", tamanho(nums));
    destroiFila(&nums, NULL);

    putchar('\n');

    // Parte 3: enfileira, desenfileira e imprime
    nums = criaFila();

    if (!nums) {
        fprintf(stderr, "Erro ao criar fila!\n");
        return 1;
    }

    enfileira(nums, criaNum(1));
    puts("Fila:");
    percorre(nums, imprimeNum);
    printf("Tam. fila: %d\n", tamanho(nums));
    num = (int*)desenfileira(nums);
    printf("Núm. desenfileirado: %d\n", *num);
    free(num);
    printf("Tam. fila: %d\n", tamanho(nums));

    enfileira(nums, criaNum(2));
    enfileira(nums, criaNum(3));
    enfileira(nums, criaNum(4));
    puts("Fila:");
    percorre(nums, imprimeNum);
    printf("Tam. fila: %d\n", tamanho(nums));
    num = (int*)desenfileira(nums);
    printf("Núm. desenfileirado: %d\n", *num);
    free(num);
    puts("Fila:");
    percorre(nums, imprimeNum);
    printf("Tam. fila: %d\n", tamanho(nums));

    putchar('\n');

    // Parte 4: desalocação
    destroiFila(&nums, destroiNum);

    if (!nums)
        puts("Fila destruída.");

    return 0;
}
