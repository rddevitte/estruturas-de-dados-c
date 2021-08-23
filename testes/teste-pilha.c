/**
 * @file teste-pilha.c
 * @brief Testa a estrutura de pilha e suas operações.
 */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/macros.h"
#include "pilha/pilha.h"
#include "nums/nums.h"

int main(void)
{
    Pilha nums;
    int* num;

    setlocale(LC_ALL, "pt_BR.utf8");

    // Parte 1: pilha nula
    nums = NULL;

    push(nums, NULL);
    pop(nums);
    percorre(nums, NULL);
    PRINT_DBG("Tam. pilha: %d", tamanho(nums));
    destroiPilha(NULL, NULL);
    destroiPilha(&nums, NULL);

    putchar('\n');

    // Parte 2: pilha vazia
    nums = criaPilha();

    if (!nums) {
        PRINT_ERR("Erro ao criar pilha!");
        return 1;
    }

    pop(nums);
    percorre(nums, NULL);
    PRINT_DBG("Tam. pilha: %d", tamanho(nums));
    destroiPilha(&nums, NULL);

    putchar('\n');

    // Parte 3: empilha, desempilha e imprime
    nums = criaPilha();

    if (!nums) {
        PRINT_ERR("Erro ao criar pilha!");
        return 1;
    }

    push(nums, criaNum(1));
    PRINT_DBG("Pilha:");
    percorre(nums, imprimeNum);
    PRINT_DBG("Tam. pilha: %d", tamanho(nums));
    num = (int*)pop(nums);
    PRINT_DBG("Núm. desempilhado: %d", *num);
    free(num);
    PRINT_DBG("Tam. pilha: %d", tamanho(nums));

    push(nums, criaNum(2));
    push(nums, criaNum(3));
    push(nums, criaNum(4));
    PRINT_DBG("Pilha:");
    percorre(nums, imprimeNum);
    PRINT_DBG("Tam. pilha: %d", tamanho(nums));
    num = (int*)pop(nums);
    PRINT_DBG("Núm. desempilhado: %d", *num);
    free(num);
    PRINT_DBG("Pilha:");
    percorre(nums, imprimeNum);
    PRINT_DBG("Tam. pilha: %d", tamanho(nums));

    putchar('\n');

    // Parte 4: desalocação
    destroiPilha(&nums, destroiNum);

    if (!nums)
        PRINT_DBG("Pilha destruída.");

    return 0;
}
