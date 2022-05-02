# Data Structures in C

This project is an implementation in C language of basic data structures, which are data type
generic and dynamically allocated, that can be imported and freely used in other projects, with
minor modifications.

At the moment, the implemented data structures are: stack, queue and circular doubly linked list
(in portuguese, *pilha*, *fila* and *lista duplamente encadeada circular* respectively). It is
planned to be implemented other data structures in the future, such as graph and binary tree.

## Containers and supported operations

* Stack
    - Creation and destruction
    - Push and pop elements
    - Traverse
    - Get stack size
* Queue
    - Creation and destruction
    - Enqueue and dequeue elements
    - Traverse
    - Get queue size
* Circular doubly linked list
    - Creation and destruction
    - Insertion: at beginning, end, given position or in order
    - Deletion: at beginning, end, given position or matching specific criteria
    - Traverse
    - Get list size

## Building and running

On GNU/Linux, after cloning the project with `git clone`, run the desired target:

* Either `make lista`, `make fila` or `make pilha` to compile the static lib of the corresponding
  data structure;

* Either `make teste-lista`, `make teste-fila` or `make teste-pilha` to compile the static lib as
  well as run the test executable of the corresponding data structure;

* Just `make` or `make all` to run all the targets above mentioned.

### Cleanup

To remove the object files (\*.o): `make clean`. To remove them and the binaries as well:
`make mrproper`.
