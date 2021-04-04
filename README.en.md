# Data Structures in C

This project is an implementation in C language of basic data structures, which are data type generic and dynamically allocated, that can be imported and freely used in other projects, with minor modifications.

At the moment, the implemented data structures are: stack, queue and circular doubly linked list (in portuguese, *pilha*, *fila* and *lista duplamente encadeada circular* respectively). It is planned to be implemented other data structures in the future, such as graph and binary tree.

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

On GNU/Linux, after cloning the project with `git clone`, run:

`make`, `make all` or the test target of the given structure (`make teste-fila` (queue), `make teste-lista` (list) or `make teste-pilha` (stack)). (**Note:** before compiling the specific target, please run at the first time `make objdirs`, to create the *obj/* directories).

To run the compiled binary: `./teste-fila`, `./teste-lista` or `./teste-pilha`.

### Cleanup

To remove the object files (*.o): `make clean`. To remove them and the binaries as well: `make mrproper`.