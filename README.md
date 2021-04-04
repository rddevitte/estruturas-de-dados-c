# Estruturas de Dados em C

Este projeto é uma implementação em C de estruturas de dados básicas, genéricas e dinâmicas, podendo ser importadas e utilizadas livremente em outros projetos, com pequenas alterações.

Até o momento, as estruturas implementadas são: pilha, fila e lista duplamente encadeada circular. Planeja-se implementar outras estruturas futuramente, como grafo e árvore binária.

## Estruturas (_containers_) e suas operações

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

No GNU/Linux, após clonar o projeto com `git clone`, executar:

`make`, `make all` ou o alvo (*target*) de teste da estrutura específica (`make teste-fila`, `make teste-lista` ou `make teste-pilha`). (**Obs.:** antes de compilar o alvo específico, execute `make objdirs` na primeira vez, para criar os diretórios *obj/*).

Para executar o binário gerado: `./teste-fila`, `./teste-lista` ou `./teste-pilha`.

### Limpeza (_cleanup_)

Para limpar os arquivos objeto (*.o): `make clean`. Para remover os arquivos objeto bem como os binários: `make mrproper`.