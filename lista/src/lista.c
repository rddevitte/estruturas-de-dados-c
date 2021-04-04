/**
 * lista.c - Definição da estrutura e das funções da lista duplamente encadeada
 * circular.
 */

#include "../inc/lista.h"
#include "../inc/nodolista.h"
#include <stdio.h>
#include <stdlib.h>

/** Estrutura da lista */
struct lista {
    /** Ponteiro para o início da lista */
    NodoLista inicio;
    /** Ponteiro para o fim da lista */
    NodoLista fim;
    /** Tamanho (núm. de elementos) da lista */
    int tam;
};

/**
 * Cria (aloca) uma lista vazia, sem nenhum nodo.
 * @return ponteiro para a lista alocada
 */
Lista criaLista(void)
{
    Lista l;

    l = malloc(sizeof(struct lista));

    if (!l) {
        fprintf(stderr,
                "%s:%d: não foi possível alocar memória para a lista!\n",
                __func__, __LINE__);
        return NULL;
    }

    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;

    return l;
}

/**
 * Insere um elemento no início da lista.
 * @param l A lista
 * @param elem O elemento a ser inserido
 */
void insereInicio(Lista l, void *elem)
{
    NodoLista nl;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    nl = criaNodoLista(elem, NULL, NULL);

    if (!nl) {
        fprintf(stderr,
                "%s:%d: não foi possível alocar memória para o novo nodo da \
                lista!\n",
                __func__, __LINE__);
        return;
    }

    // Caso 1: lista vazia
    // - o único nodo aponta para ele mesmo
    // - ponteiros inicio, fim e atual apontam para o mesmo nodo
    if (l->tam == 0) {
        nl->ant = nl;
        nl->prox = nl;
        l->inicio = nl;
        l->fim = nl;
    }

    // Caso 2: lista com um ou mais elementos
    // - novo nodo->prox aponta para o início
    // - novo nodo->ant aponta para o fim
    // - fim->prox aponta para novo
    // - início->ant aponta para novo
    // - novo nodo se torna o início
    else if (l->tam > 0) {
        nl->prox = l->inicio;
        nl->ant = l->fim;

        l->inicio->ant = nl;
        l->fim->prox = nl;

        l->inicio = nl;
    }

    l->tam++;

    return;
}

/**
 * Insere um elemento no final da lista.
 * @param l A lista
 * @param elem O elemento a ser inserido
 */
void insereFim(Lista l, void *elem)
{
    NodoLista nl;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    nl = criaNodoLista(elem, NULL, NULL);

    if (!nl) {
        fprintf(stderr,
                "%s:%d: não foi possível alocar memória para o novo nodo da \
                lista!\n",
                __func__, __LINE__);
        return;
    }

    // Caso 1: lista vazia
    // - o único nodo aponta para ele mesmo
    // - ponteiros inicio, fim e atual apontam para o mesmo nodo
    if (l->tam == 0) {
        nl->ant = nl;
        nl->prox = nl;
        l->inicio = nl;
        l->fim = nl;
    }

    // Caso 2: lista com um ou mais elementos
    // - novo nodo->prox aponta para o inicio
    // - novo nodo->ant aponta para o fim
    // - fim->prox aponta para o novo nodo
    // - inicio->ant aponta para o novo nodo
    // - novo nodo se torna o fim
    else if (l->tam > 0) {
        nl->prox = l->inicio;
        nl->ant = l->fim;

        l->fim->prox = nl;
        l->inicio->ant = nl;

        l->fim = nl;
    }

    l->tam++;

    return;
}

/**
 * Insere um elemento no início da lista.
 * @param l A lista
 * @param pos A posição da lista onde o elemento será inserido
 * @param elem O elemento a ser inserido
 */
void inserePos(Lista l, int pos, void *elem)
{
    NodoLista nl, aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (pos < 0 || pos > l->tam) {
        fprintf(stderr, "%s:%d: posição %d inválida!\n", __func__, __LINE__,
                pos);

        if (elem)
            free(elem);

        return;
    }

    if (pos == 0) {
        insereInicio(l, elem);
        return;
    }
    if (pos > 0 && pos == l->tam) {
        insereFim(l, elem);
        return;
    }

    aux = l->inicio;

    while (pos-- > 1)
        aux = aux->prox;

    nl = criaNodoLista(elem, aux, aux->prox);

    if (!nl) {
        fprintf(stderr,
                "%s:%d: não foi possível alocar memória para o novo nodo da \
                lista!\n",
                __func__, __LINE__);
        return;
    }

    aux->prox->ant = nl;
    aux->prox = nl;

    l->tam++;

    return;
}

/**
 * Insere um elemento na lista de forma ordenada, obedecendo à saída da função
 * comparaElems. comparaElems() deve retornar -1 se o 1º elem é menor que o 2º,
 * 1 se é maior, ou 0 se ambos são iguais.
 * @param l A lista
 * @param elem O elemento a ser inserido
 * @param comparaElems Ponteiro para a função que compara o elem. a ser inserido
 * com o elem. do nodo seguinte ao atual (aux)
 */
void insereOrd(Lista l, void *elem, int (*comparaElems)(void *, void *))
{
    NodoLista nl, aux;
    int c, c2;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (!comparaElems) {
        fprintf(stderr, "%s:%d: ponteiro p/ função comparaElems nulo!\n",
                __func__, __LINE__);
        return;
    }

    // Se a lista estiver vazia, insere no início da lista
    // (Sem precisar usar a função comparaElems())
    if (l->tam == 0) {
        insereInicio(l, elem);
        return;
    }
    // Compara primeiro com o elem. do início da lista.
    // Se elem. do início é igual ou maior que o elem. a ser inserido,
    // insere no início da lista
    c = comparaElems(l->inicio->elem, elem);

    if (c == 0 || c == 1) {
        insereInicio(l, elem);
        return;
    } else if (c == -1) {
        // Se for menor, examina o elemento do fim da lista.
        // Se o elemento for igual ou maior ao último nodo da lista,
        // insere no final
        c = comparaElems(elem, l->fim->elem);

        if (c == 0 || c == 1) {
            insereFim(l, elem);
            return;
        }

        // Senão, percorre os nodos da lista desde o início
        else if (c == -1) {
            aux = l->inicio;

            while (aux != l->fim) {
                c = comparaElems(elem, aux->elem);
                c2 = comparaElems(aux->prox->elem, elem);

                // Se o elem. a ser inserido é igual ou maior que o elem. de aux
                // e o elem. de aux->prox é igual ou maior que o elem. a ser
                // inserido, sai do loop while
                if ((c == 0 || c == 1) && (c2 == 0 || c2 == 1))
                    break;

                aux = aux->prox;
            }

            // Se chegou ao fim da lista e não inseriu o novo elemento,
            // sai da função
            if (aux == l->fim) {
                fprintf(stderr,
                        "%s:%d: não foi possível inserir o elemento na lista.",
                        __func__, __LINE__);
                return;
            }

            // Senão, insere o novo elem. entre aux e aux->prox
            nl = criaNodoLista(elem, aux, aux->prox);
            aux->prox->ant = nl;
            aux->prox = nl;

            l->tam++;
        }
        // Se a função comparaElems() não retornou nem -1, nem 0 e nem 1,
        // considera valor inválido!
        else {
            fprintf(stderr,
                    "%s:%d: valor retornado de comparaElems() inválido! \
(Deve ser -1, 0 ou 1.)\n",
                    __func__, __LINE__);
            return;
        }
    }
    // Se a função comparaElems() não retornou nem -1, nem 0 e nem 1,
    // considera valor inválido!
    else {
        fprintf(stderr, "%s:%d: valor retornado de comparaElems() inválido! \
(Deve ser -1, 0 ou 1.)\n",
                __func__, __LINE__);
        return;
    }

    return;
}

/**
 * Retorna o tamanho da lista (núm. de elementos).
 * @return o tamanho da lista
 */
int tamanho(Lista l)
{
    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return -1;
    }

    return l->tam;
}

/**
 * Retorna o (endereço do) elemento do nodo do início da lista.
 * @param l A lista
 * @return o (endereço do) elemento do nodo do início da lista
 */
void *elemInicio(Lista l)
{
    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return NULL;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return NULL;
    }

    return l->inicio->elem;
}

/**
 * Retorna o (endereço do) elemento do nodo do fim da lista.
 * @param l A lista
 * @return o (endereço do) elemento do nodo do fim da lista
 */
void *elemFim(Lista l)
{
    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return NULL;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return NULL;
    }

    return l->fim->elem;
}

/**
 * Retorna o (endereço do) elemento do nodo da posição 'pos' da lista.
 * @param l A lista
 * @param pos A posição do nodo da lista
 * @return o (endereço do) elemento do nodo da dada posição da lista
 */
void *elemPos(Lista l, int pos)
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return NULL;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return NULL;
    }

    if (pos < 0 || pos > l->tam - 1) {
        fprintf(stderr, "%s:%d: posição %d inválida!\n", __func__, __LINE__,
                pos);
        return NULL;
    }

    if (pos == 0)
        return elemInicio(l);
    else if (pos == l->tam - 1)
        return elemFim(l);

    aux = l->inicio;

    while (pos-- > 0)
        aux = aux->prox;

    return aux->elem;
}

/**
 * Percorre (traverse) os nodos do início ao fim da lista, aplicando a função
 * acessaElem() nos elems. de cada nodo.
 * @param l A lista
 * @param acessaElem O ponteiro para a função a ser aplicada no elem. do nodo da
 * lista
 */
void percorre(Lista l, void (*acessaElem)(void *))
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return;
    }

    if (!acessaElem) {
        fprintf(stderr, "%s:%d: ponteiro p/ função acessaElem() nulo!\n",
                __func__, __LINE__);
        return;
    }

    aux = l->inicio;

    do {
        acessaElem(aux->elem);
        aux = aux->prox;
    } while (aux != l->fim);

    if (l->tam > 1)
        acessaElem(aux->elem); // o mesmo que acessaElem(l->fim->elem)

    return;
}

/**
 * Percorre (traverse) os nodos em ordem inversa, do fim ao início da lista,
 * aplicando a função acessaElem() nos elems. de cada nodo.
 * @param l A lista
 * @param acessaElem O ponteiro para a função a ser aplicada no elem. do nodo da
 * lista
 */
void percorreInv(Lista l, void (*acessaElem)(void *))
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return;
    }

    if (!acessaElem) {
        fprintf(stderr, "%s:%d: ponteiro p/ função acessaElem() nulo!\n",
                __func__, __LINE__);
        return;
    }

    aux = l->fim;

    do {
        acessaElem(aux->elem);
        aux = aux->ant;
    } while (aux != l->inicio);

    if (l->tam > 1)
        acessaElem(aux->elem); // o mesmo que acessaElem(l->inicio->elem)

    return;
}

/**
 * Remove o nodo do início da lista.
 * @param l A lista
 * @param removeElem O ponteiro para a função que desaloca o elemento
 * do nodo a ser removido
 */
void removeInicio(Lista l, void (*removeElem)(void **))
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 1) {
        destroiNodoLista(&(l->inicio), removeElem);
        l->inicio = l->fim = NULL;
    } else {
        aux = l->inicio->prox;
        destroiNodoLista(&(l->inicio), removeElem);
        l->inicio = aux;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
    }

    l->tam--;

    return;
}

/**
 * Remove o nodo do fim da lista.
 * @param l A lista
 * @param removeElem O ponteiro para a função que desaloca o elemento
 * do nodo a ser removido
 */
void removeFim(Lista l, void (*removeElem)(void **))
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 1) {
        destroiNodoLista(&(l->fim), removeElem);
        l->inicio = l->fim = NULL;
    } else {
        /* ... resto do algoritmo aqui ... */
        aux = l->fim->ant;
        destroiNodoLista(&(l->fim), removeElem);
        l->fim = aux;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
    }

    l->tam--;

    return;
}

/**
 * Remove o nodo da posição 'pos' da lista.
 * @param l A lista
 * @param removeElem O ponteiro para a função que desaloca o elemento
 * do nodo a ser removido
 */
void removePos(Lista l, int pos, void (*removeElem)(void **))
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return;
    }

    if (pos < 0 || pos > l->tam - 1) {
        fprintf(stderr, "%s:%d: posição inválida!\n", __func__, __LINE__);
        return;
    }

    if (pos == 0) {
        removeInicio(l, removeElem);
    } else if (l->tam > 1 && pos == l->tam - 1) {
        removeFim(l, removeElem);
    } else {
        aux = l->inicio;

        while (pos-- > 0)
            aux = aux->prox;

        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;

        destroiNodoLista(&aux, removeElem);

        l->tam--;
    }

    return;
}

/**
 * Remove um ou mais nodos da lista e seus elementos, dependendo da saída
 * da função verifElem().
 * Se a função verifElem(elem) retorna 1, o elemento e seu nodo é removido;
 * se retorna 0 ou qualquer outro valor, mantém o elemento na lista.
 * @param l A lista
 * @param acessaElem O elemento a ser verificada a condição
 * @param removeElem Desaloca o elemento se obedece à condição
 * @return A quantidade de nodos removidos
 */
int removeCond(Lista l, int (*verifElem)(void *), void (*removeElem)(void **))
{
    NodoLista aux, del;
    int r;

    if (!l) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return -1;
    }

    if (l->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
        return 0;
    }

    if (!verifElem) {
        fprintf(stderr, "%s:%d: ponteiro p/ função verifElem() nulo!\n",
                __func__, __LINE__);
        return -1;
    }

    // Caso 1: lista com 1 nodo
    if (l->tam == 1 && verifElem(l->inicio->elem) == 1) {
        removeInicio(l, removeElem);
        return 1;
    }

    // Caso 2: lista com 2 ou mais nodos

    r = 0;
    aux = l->inicio;

    // Percorre a lista até parar no último nodo
    while (aux != l->fim) {
        if (verifElem(aux->elem) == 1) {
            // Caso 2.1: cond. aceita no primeiro elem. (l->inicio)
            if (aux == l->inicio) {
                aux = aux->prox;
                removeInicio(l, removeElem);
                r++;
            }
            // Caso 2.2: cond. aceita em qualquer outro elem. entre o início e o
            // fim (caso típico)
            else {
                if (l->tam == 1)
                    removeInicio(l, removeElem);
                else {
                    del = aux;
                    aux = aux->prox;
                    aux->ant = del->ant;
                    aux->ant->prox = aux;
                    destroiNodoLista(&del, removeElem);
                    l->tam--;
                }

                r++;
            }
        } else
            aux = aux->prox;
    }

    // Caso 2.3: cond. aceita no últ. elem. (l->fim)
    if (l->tam > 1 && aux == l->fim && verifElem(aux->elem) == 1) {
        removeFim(l, removeElem);
        r++;
    }

    return r;
}

/**
 * "Destroi" (desaloca) a lista e seus elementos.
 * @param l A lista
 * @param destroiElem O ponteiro para uma função que desaloca
 * o elemento do nodo da lista
 */
void destroiLista(Lista *l, void (*destroiElem)(void **))
{
    NodoLista aux;

    if (!l) {
        fprintf(stderr, "%s:%d: ponteiro p/ a lista nulo!\n", __func__,
                __LINE__);
        return;
    }

    if (!(*l)) {
        fprintf(stderr, "%s:%d: lista nula!\n", __func__, __LINE__);
        return;
    }

    if ((*l)->tam == 0) {
        fprintf(stderr, "%s:%d: lista vazia\n", __func__, __LINE__);
    } else {
        // Vai removendo os nodos até restar um único nodo
        while ((*l)->tam > 1) {
            aux = (*l)->inicio->prox;
            destroiNodoLista(&((*l)->inicio), destroiElem);
            (*l)->inicio = aux;
            (*l)->tam--;
        }

        destroiNodoLista(&((*l)->inicio), destroiElem);
    }

    free(*l);
    *l = NULL;

    return;
}