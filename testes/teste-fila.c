/**
 * @file teste-fila.c
 * @brief Testa a estrutura de fila e suas operações.
 */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "../common/macros.h"
#include "../fila/inc/fila.h"
#include "./nums/nums.h"

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
    PRINT_DBG("Tam. fila: %d", tamanho(nums));
    destroiFila(NULL, NULL);
    destroiFila(&nums, NULL);

    putchar('\n');

    // Parte 2: fila vazia
    nums = criaFila();

    if (!nums) {
        PRINT_ERR("Erro ao criar fila!");
        return 1;
    }

    desenfileira(nums);
    percorre(nums, NULL);
    PRINT_DBG("Tam. fila: %d", tamanho(nums));
    destroiFila(&nums, NULL);

    putchar('\n');

    // Parte 3: enfileira, desenfileira e imprime
    nums = criaFila();

    if (!nums) {
        PRINT_ERR("Erro ao criar fila!");
        return 1;
    }

    enfileira(nums, criaNum(1));
    PRINT_DBG("Fila:");
    percorre(nums, imprimeNum);
    PRINT_DBG("Tam. fila: %d", tamanho(nums));
    num = (int*)desenfileira(nums);
    PRINT_DBG("Núm. desenfileirado: %d", *num);
    free(num);
    PRINT_DBG("Tam. fila: %d", tamanho(nums));

    enfileira(nums, criaNum(2));
    enfileira(nums, criaNum(3));
    enfileira(nums, criaNum(4));
    PRINT_DBG("Fila:");
    percorre(nums, imprimeNum);
    PRINT_DBG("Tam. fila: %d", tamanho(nums));
    num = (int*)desenfileira(nums);
    PRINT_DBG("Núm. desenfileirado: %d", *num);
    free(num);
    PRINT_DBG("Fila:");
    percorre(nums, imprimeNum);
    PRINT_DBG("Tam. fila: %d", tamanho(nums));

    putchar('\n');

    // Parte 4: desalocação
    destroiFila(&nums, destroiNum);

    if (!nums)
        PRINT_DBG("Fila destruída.");

    return 0;
}
