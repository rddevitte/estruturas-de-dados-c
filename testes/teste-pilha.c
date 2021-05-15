/**
 * @file teste-pilha.c
 * @brief Testa a estrutura de pilha e suas operações.
 */
#include "../pilha/inc/pilha.h"
#include "./nums/nums.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

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
    printf("Tam. pilha: %d\n", tamanho(nums));
    destroiPilha(NULL, NULL);
    destroiPilha(&nums, NULL);

    putchar('\n');

    // Parte 2: pilha vazia
    nums = criaPilha();

    if (!nums) {
        fprintf(stderr, "Erro ao criar pilha!\n");
        return 1;
    }

    pop(nums);
    percorre(nums, NULL);
    printf("Tam. pilha: %d\n", tamanho(nums));
    destroiPilha(&nums, NULL);

    putchar('\n');

    // Parte 3: empilha, desempilha e imprime
    nums = criaPilha();

    if (!nums) {
        fprintf(stderr, "Erro ao criar pilha!\n");
        return 1;
    }

    push(nums, criaNum(1));
    puts("Pilha:");
    percorre(nums, imprimeNum);
    printf("Tam. pilha: %d\n", tamanho(nums));
    num = (int*)pop(nums);
    printf("Núm. desempilhado: %d\n", *num);
    free(num);
    printf("Tam. pilha: %d\n", tamanho(nums));

    push(nums, criaNum(2));
    push(nums, criaNum(3));
    push(nums, criaNum(4));
    puts("Pilha:");
    percorre(nums, imprimeNum);
    printf("Tam. pilha: %d\n", tamanho(nums));
    num = (int*)pop(nums);
    printf("Núm. desempilhado: %d\n", *num);
    free(num);
    puts("Pilha:");
    percorre(nums, imprimeNum);
    printf("Tam. pilha: %d\n", tamanho(nums));

    putchar('\n');

    // Parte 4: desalocação
    destroiPilha(&nums, destroiNum);

    if (!nums)
        puts("Pilha destruída.");

    return 0;
}
