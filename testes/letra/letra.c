/**
 * @file letra.c
 * @brief Definição das funções auxiliares para criação, impressão e
 * desalocação dinâmica de caracteres. Usado no teste da lista.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../../common/macros.h"
#include "letra.h"

void* criaLetra(char c)
{
    char* pc;

    pc = (char*)malloc(sizeof(char));

    if (pc) {
        *pc = c;
    }

    return pc;
}

void imprimeLetra(void* c)
{
    if (!c) {
        PRINT_ERR("letra nula!");
        return;
    }

    PRINT_DBG("c = %p, *c = '%c'", c, *(char*)c);

    return;
}

void destroiLetra(void** c)
{
    if (!c) {
        PRINT_ERR("ponteiro p/ letra nulo!");
        return;
    }

    if (!(*c)) {
        PRINT_ERR("letra nula");
        return;
    }

    free(*c);
    *c = NULL;

    return;
}

int comparaLetras(void* a, void* b)
{
    char *la, *lb;
    int c;

    if (!a || !b) {
        PRINT_ERR("ponteiro para letra a ou b nulo(s)!");
        return 2;
    }

    la = (char*)a;
    lb = (char*)b;

    if (*la > *lb)
        c = 1;
    else if (*la < *lb)
        c = -1;
    else // if (*la == *lb)
        c = 0;

    return c;
}

int condLetraEntreDeF(void* l)
{
    char* cl;

    if (!l) {
        PRINT_ERR("ponteiro para letra nulo!");
        return -1;
    }

    cl = (char*)l;

    return (*cl >= 'D' && *cl <= 'F' ? 1 : 0);
}

int condLetraA(void* l)
{
    char* cl;

    if (!l) {
        PRINT_ERR("ponteiro p/ letra nulo!");
        return -1;
    }

    cl = (char*)l;

    return (*cl == 'A' ? 1 : 0);
}

int condLetraJ(void* l)
{
    char* cl;

    if (!l) {
        PRINT_ERR("ponteiro p/ letra nulo!");
        return -1;
    }

    cl = (char*)l;

    return (*cl == 'J' ? 1 : 0);
}
