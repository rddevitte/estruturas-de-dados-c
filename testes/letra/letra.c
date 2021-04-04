/**
 * letra.c - Definição das funções auxiliares para criação, impressão e
 * desalocação dinâmica de caracteres. Usado no teste da lista.
 */
#include "letra.h"
#include <stdio.h>
#include <stdlib.h>

void *criaLetra(char c)
{
    char *pc;

    pc = malloc(sizeof(char));

    if (pc) {
        *pc = c;
    }

    return pc;
}

void imprimeLetra(void *c)
{
    if (!c) {
        fprintf(stderr, "%s:%d: letra nula!\n", __func__, __LINE__);
        return;
    }

    printf("c = %p, *c = '%c'\n", c, *(char *)c);

    return;
}

void destroiLetra(void **c)
{
    if (!c) {
        fprintf(stderr, "%s:%d: ponteiro p/ letra nulo!\n", __func__, __LINE__);
        return;
    }

    if (!(*c)) {
        fprintf(stderr, "%s:%d: letra nula\n", __func__, __LINE__);
        return;
    }

    free(*c);
    *c = NULL;

    return;
}

int comparaLetras(void *a, void *b)
{
    char *la, *lb;
    int c;

    if (!a || !b) {
        fprintf(stderr, "%s:%d: ponteiro para letra a ou b nulo(s)!\n",
                __func__, __LINE__);
        return 2;
    }

    la = (char *)a;
    lb = (char *)b;

    if (*la > *lb)
        c = 1;
    else if (*la < *lb)
        c = -1;
    else // if (*la == *lb)
        c = 0;

    return c;
}

int condLetraEntreDeF(void *l)
{
    char *cl;

    if (!l) {
        fprintf(stderr, "%s:%d: ponteiro para letra nulo!\n", __func__,
                __LINE__);
        return -1;
    }

    cl = (char *)l;

    return (*cl >= 'D' && *cl <= 'F' ? 1 : 0);
}

int condLetraA(void *l)
{
    char *cl;

    if (!l) {
        fprintf(stderr, "%s:%d: ponteiro p/ letra nulo!\n", __func__, __LINE__);
        return -1;
    }

    cl = (char *)l;

    return (*cl == 'A' ? 1 : 0);
}

int condLetraJ(void *l)
{
    char *cl;

    if (!l) {
        fprintf(stderr, "%s:%d: ponteiro p/ letra nulo!\n", __func__, __LINE__);
        return -1;
    }

    cl = (char *)l;

    return (*cl == 'J' ? 1 : 0);
}