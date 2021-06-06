/**
 * @file lista.h
 * @brief Declaração da estrutura e das funções (criação, operações e
 * destruição) da lista. Trata-se de uma lista duplamente encadeada circular.
 */
#ifndef LISTA_H
#define LISTA_H

#ifdef __cplusplus
extern "C" {
#endif

/** Declaração da estrutura da lista */
struct lista;

/** Def. de tipo Lista */
typedef struct lista* Lista;

/**
 * Cria (aloca) uma lista vazia, sem nenhum nodo.
 * @return ponteiro para a lista alocada
 */
Lista criaLista(void);

/**
 * Insere um elemento no início da lista.
 * @param l A lista
 * @param elem O elemento a ser inserido
 */
void insereInicio(Lista l, void* elem);

/**
 * Insere um elemento no final da lista.
 * @param l A lista
 * @param elem O elemento a ser inserido
 */
void insereFim(Lista l, void* elem);

/**
 * Insere um elemento no início da lista.
 * @param l A lista
 * @param pos A posição da lista onde o elemento será inserido
 * @param elem O elemento a ser inserido
 */
void inserePos(Lista l, int pos, void* elem);

/**
 * Insere um elemento na lista de forma ordenada, obedecendo à saída da função
 * comparaElems. comparaElems() deve retornar -1 se o 1º elem é menor que o 2º,
 * 1 se é maior, ou 0 se ambos são iguais.
 * @param l A lista
 * @param elem O elemento a ser inserido
 * @param comparaElems Ponteiro para a função que compara o elem. a ser inserido
 * com o elem. do nodo seguinte ao atual (aux)
 */
void insereOrd(Lista l, void* elem, int (*comparaElems)(void*, void*));

/**
 * Retorna o tamanho da lista (núm. de elementos).
 * @param l A lista
 * @return o tamanho da lista
 */
int tamanho(Lista l);

/**
 * Retorna o (endereço do) elemento do nodo do início da lista.
 * @param l A lista
 * @return o (endereço do) elemento do nodo do início da lista
 */
void* elemInicio(Lista l);

/**
 * Retorna o (endereço do) elemento do nodo do fim da lista.
 * @param l A lista
 * @return o (endereço do) elemento do nodo do fim da lista
 */
void* elemFim(Lista l);

/**
 * Retorna o (endereço do) elemento do nodo da posição 'pos' da lista.
 * @param l A lista
 * @param pos A posição do nodo da lista
 * @return o (endereço do) elemento do nodo da dada posição da lista
 */
void* elemPos(Lista l, int pos);

/**
 * Percorre (traverse) os nodos do início ao fim da lista, aplicando a função
 * acessaElem() nos elems. de cada nodo.
 * @param l A lista
 * @param acessaElem O ponteiro para a função a ser aplicada no elem. do nodo da
 * lista
 */
void percorre(Lista l, void (*acessaElem)(void*));

/**
 * Percorre (traverse) os nodos em ordem inversa, do fim ao início da lista,
 * aplicando a função acessaElem() nos elems. de cada nodo.
 * @param l A lista
 * @param acessaElem O ponteiro para a função a ser aplicada no elem. do nodo da
 * lista
 */
void percorreInv(Lista l, void (*acessaElem)(void*));

/**
 * Remove o nodo do início da lista.
 * @param l A lista
 * @param removeElem O ponteiro para a função que desaloca o elemento
 * do nodo a ser removido
 */
void removeInicio(Lista l, void (*removeElem)(void**));

/**
 * Remove o nodo do fim da lista.
 * @param l A lista
 * @param removeElem O ponteiro para a função que desaloca o elemento
 * do nodo a ser removido
 */
void removeFim(Lista l, void (*removeElem)(void**));

/**
 * Remove o nodo da posição 'pos' da lista.
 * @param l A lista
 * @param pos A posição do nodo a ser removido da lista
 * @param removeElem O ponteiro para a função que desaloca o elemento
 * do nodo a ser removido
 */
void removePos(Lista l, int pos, void (*removeElem)(void**));

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
int removeCond(Lista l, int (*acessaElem)(void*), void (*removeElem)(void**));

/**
 * "Destroi" (desaloca) a lista e seus elementos.
 * @param l Ponteiro para a lista
 * @param destroiElem O ponteiro para uma função que desaloca
 * os elementos dos nodos da lista
 */
void destroiLista(Lista* l, void (*destroiElem)(void**));

#ifdef __cplusplus
}
#endif

#endif // LISTA_H
