# Estruturas de Dados em C

Este projeto é uma implementação em C de estruturas de dados básicas, genéricas e dinâmicas, podendo
ser importadas e utilizadas livremente em outros projetos, com pequenas alterações.

Até o momento, as estruturas implementadas são: pilha, fila e lista duplamente encadeada circular.
Planeja-se implementar outras estruturas futuramente, como grafo e árvore binária.

## Estruturas (*containers*) e suas operações

* Pilha
    - Criação e destruição da pilha
    - Empilhar (*push*) e desempilhar (*pop*) elementos
    - Percorrer (*traverse*) os nodos
    - Obter o tamanho da pilha
* Fila
    - Criação e destruição da fila
    - Enfileirar (*enqueue*) e desenfileirar (*dequeue*) elementos
    - Percorrer (*traverse*) os nodos
    - Obter o tamanho da fila
* Lista ligada dupla circular
    - Criação e destruição da lista
    - Inserção de elementos: no início, no fim, na posição ou em ordem
    - Remoção de elementos: no início, no fim, na posição ou segundo critério específico
    - Percorrer (*traverse*) os nodos
    - Obter o tamanho da lista

## Compilação

No GNU/Linux, após clonar o projeto com `git clone`, executar o alvo (*target*) desejado:

* `make lista`, `make fila` ou `make pilha` para compilar a lib. estática da estrutura
  correspondente;

* `make teste-lista`, `make teste-fila` ou `make teste-pilha` para compilar a lib. estática, bem
  como executar o binário de teste, da estrutura correspondente;

* Apenas `make` ou `make all` para executar todos os alvos mencionados acima.

### Limpeza (*cleanup*)

Para limpar os arquivos objeto (\*.o): `make clean`. Para remover os arquivos objeto bem como os
binários: `make mrproper`.
