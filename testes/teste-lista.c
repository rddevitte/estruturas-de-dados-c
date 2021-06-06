/**
 * @file teste-lista.c
 * @brief Testa a estrutura da lista e suas operações.
 */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "../common/macros.h"
#include "../lista/inc/lista.h"
#include "./letra/letra.h"

int main(void)
{
    Lista letras;
    char* letra;
    int rem;

    setlocale(LC_ALL, "pt_BR.utf8");

    // Parte 1: lista nula
    letras = NULL;

    insereInicio(letras, NULL);
    insereFim(letras, NULL);
    inserePos(letras, 0, NULL);
    insereOrd(letras, NULL, NULL);
    PRINT_DBG("Tam. lista: %d", tamanho(letras));
    PRINT_DBG("Elem. início: %p", elemInicio(letras));
    PRINT_DBG("Elem. fim: %p", elemFim(letras));
    PRINT_DBG("Elem. pos. 0: %p", elemPos(letras, 0));
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
        PRINT_ERR("Erro ao criar lista!");
        return 1;
    }

    PRINT_DBG("Tam. lista: %d", tamanho(letras));
    PRINT_DBG("Elem. início: %p", elemInicio(letras));
    PRINT_DBG("Elem. fim: %p", elemFim(letras));
    PRINT_DBG("Elem. pos. 0: %p", elemPos(letras, 0));
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
        PRINT_ERR("Erro ao criar lista!");
        return 1;
    }

    insereFim(letras, criaLetra('E'));
    insereInicio(letras, criaLetra('C'));
    inserePos(letras, 1, criaLetra('D'));
    inserePos(letras, 0, criaLetra('B'));
    inserePos(letras, 4, criaLetra('G'));
    insereFim(letras, criaLetra('H'));

    inserePos(letras, 99, criaLetra('%')); // pos. inválida
    insereOrd(letras, criaLetra('A'), comparaLetras); // deve inserir no início
    insereOrd(letras, criaLetra('J'), comparaLetras); // deve inserir no final
    // deve ins. entre 'E' e 'G'
    insereOrd(letras, criaLetra('F'), comparaLetras);
    // deve ins. entre 'H' e 'J'
    insereOrd(letras, criaLetra('I'), comparaLetras);

    PRINT_DBG("Lista de letras:");
    percorre(letras, imprimeLetra);
    PRINT_DBG("Lista de letras (inv.):");
    percorreInv(letras, imprimeLetra);

    PRINT_DBG("Tam. lista: %d", tamanho(letras));

    putchar('\n');

    // Parte 4: buscando elementos
    letra = (char*)elemInicio(letras);
    PRINT_DBG("Elem. início: %p", letra);
    imprimeLetra(letra);

    letra = (char*)elemFim(letras);
    PRINT_DBG("Elem. fim: %p", letra);
    imprimeLetra(letra);

    letra = (char*)elemPos(letras, 5);
    PRINT_DBG("Elem. pos. 5: %p", letra);
    imprimeLetra(letra);

    letra = (char*)elemPos(letras, 99); // buscando elem. de uma pos. inválida
    PRINT_DBG("Elem. pos. 99: %p", letra);
    imprimeLetra(letra);

    putchar('\n');

    // Parte 5: remove (início, fim, pos., cond.)
    rem = removeCond(letras, condLetraA, destroiLetra);
    PRINT_DBG("%d elem(s). removido(s)", rem);
    rem = removeCond(letras, condLetraJ, destroiLetra);
    PRINT_DBG("%d elem(s). removido(s)", rem);
    rem = removeCond(letras, condLetraEntreDeF, destroiLetra);
    PRINT_DBG("%d elem(s). removido(s)", rem);

    // não deve conter as letras removidas A, D, E, F e J
    PRINT_DBG("Lista de letras:");
    percorre(letras, imprimeLetra);
    PRINT_DBG("Lista de letras (inv.):");
    percorreInv(letras, imprimeLetra);

    PRINT_DBG("Tam. lista: %d", tamanho(letras));

    removePos(letras, 2, destroiLetra); // remove 'G'
    removeInicio(letras, destroiLetra); // remove 'B'
    removeFim(letras, destroiLetra); // remove 'I'

    PRINT_DBG("Lista de letras:");
    percorre(letras, imprimeLetra);
    PRINT_DBG("Lista de letras (inv.):");
    percorreInv(letras, imprimeLetra);

    PRINT_DBG("Tam. lista: %d", tamanho(letras));

    putchar('\n');

    // Parte 6: desalocação
    destroiLista(&letras, destroiLetra);

    if (!letras)
        PRINT_DBG("Lista destruída.");

    return 0;
}
