/**
 * teste-lista.c - Testa a estrutura da lista e suas operações.
 */
#include "../lista/inc/lista.h"
#include "./letra/letra.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

// Funções para teste

int main(void)
{
    Lista letras;
    char *letra;
    int rem;

    setlocale(LC_ALL, "pt_BR.utf8");

    // Parte 1: lista nula
    letras = NULL;

    insereInicio(letras, NULL);
    insereFim(letras, NULL);
    inserePos(letras, 0, NULL);
    insereOrd(letras, NULL, NULL);
    printf("Tam. lista: %d\n", tamanho(letras));
    printf("Elem. início: %p\n", elemInicio(letras));
    printf("Elem. fim: %p\n", elemFim(letras));
    printf("Elem. pos. 0: %p\n", elemPos(letras, 0));
    percorre(letras, NULL);
    percorreInv(letras, NULL);
    removeInicio(letras, NULL);
    removeFim(letras, NULL);
    removePos(letras, 0, NULL);
    removeCond(letras, NULL, NULL);
    destroiLista(NULL, NULL);
    destroiLista(&letras, NULL);

    putchar('\n');

    // Parte 2: lista vazia
    letras = criaLista();

    if (!letras) {
        fprintf(stderr, "Erro ao criar lista!\n");
        return 1;
    }

    printf("Tam. lista: %d\n", tamanho(letras));
    printf("Elem. início: %p\n", elemInicio(letras));
    printf("Elem. fim: %p\n", elemFim(letras));
    printf("Elem. pos. 0: %p\n", elemPos(letras, 0));
    percorre(letras, NULL);
    percorreInv(letras, NULL);
    removeInicio(letras, NULL);
    removeFim(letras, NULL);
    removePos(letras, 0, NULL);
    removeCond(letras, NULL, NULL);

    destroiLista(&letras, NULL);

    putchar('\n');

    // Parte 3: insere (início, fim, pos., ord.) e imprime
    letras = criaLista();

    if (!letras) {
        fprintf(stderr, "Erro ao criar lista!\n");
        return 1;
    }

    insereFim(letras, criaLetra('E'));
    insereInicio(letras, criaLetra('C'));
    inserePos(letras, 1, criaLetra('D'));
    inserePos(letras, 0, criaLetra('B'));
    inserePos(letras, 4, criaLetra('G'));
    insereFim(letras, criaLetra('H'));

    inserePos(letras, 99, criaLetra('%'));            // pos. inválida
    insereOrd(letras, criaLetra('A'), comparaLetras); // deve inserir no início
    insereOrd(letras, criaLetra('J'), comparaLetras); // deve inserir no final
    // deve ins. entre 'E' e 'G'
    insereOrd(letras, criaLetra('F'), comparaLetras);
    // deve ins. entre 'H' e 'J'
    insereOrd(letras, criaLetra('I'), comparaLetras);

    puts("\nLista de letras:");
    percorre(letras, imprimeLetra);
    puts("\nLista de letras (inv.):");
    percorreInv(letras, imprimeLetra);

    printf("Tam. lista: %d\n", tamanho(letras));

    putchar('\n');

    // Parte 4: buscando elementos
    letra = (char *)elemInicio(letras);
    printf("Elem. início: %p\n", letra);
    imprimeLetra(letra);

    letra = (char *)elemFim(letras);
    printf("Elem. fim: %p\n", letra);
    imprimeLetra(letra);

    letra = (char *)elemPos(letras, 5);
    printf("Elem. pos. 5: %p\n", letra);
    imprimeLetra(letra);

    letra = (char *)elemPos(letras, 99); // buscando elem. de uma pos. inválida
    printf("Elem. pos. 99: %p\n", letra);
    imprimeLetra(letra);

    putchar('\n');

    // Parte 5: remove (início, fim, pos., cond.)
    rem = removeCond(letras, condLetraA, destroiLetra);
    printf("%d elem(s). removido(s)\n", rem);
    rem = removeCond(letras, condLetraJ, destroiLetra);
    printf("%d elem(s). removido(s)\n", rem);
    rem = removeCond(letras, condLetraEntreDeF, destroiLetra);
    printf("%d elem(s). removido(s)\n", rem);

    // não deve conter as letras removidas A, D, E, F e J
    puts("\nLista de letras:");
    percorre(letras, imprimeLetra);
    puts("\nLista de letras (inv.):");
    percorreInv(letras, imprimeLetra);

    printf("Tam. lista: %d\n", tamanho(letras));

    removePos(letras, 2, destroiLetra); // remove 'G'
    removeInicio(letras, destroiLetra); // remove 'B'
    removeFim(letras, destroiLetra);    // remove 'I'

    puts("\nLista de letras:");
    percorre(letras, imprimeLetra);
    puts("\nLista de letras (inv.):");
    percorreInv(letras, imprimeLetra);

    printf("Tam. lista: %d\n", tamanho(letras));

    putchar('\n');

    // Parte 6: desalocação
    destroiLista(&letras, destroiLetra);

    if (!letras)
        puts("Lista destruída.");

    return 0;
}