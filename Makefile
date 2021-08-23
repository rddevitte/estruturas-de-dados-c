SHELL=/usr/bin/bash
CC=gcc
FLAGS=-Wall         \
      -Wextra       \
      -Werror       \
      -Wpedantic    \
      -I $(INC_DIR) \
      -g
RM=rm -vf
SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj

.PHONY : all objdirs clean mrproper

all: objdirs teste-pilha teste-fila teste-lista

teste-pilha: ./testes/$(OBJ_DIR)/teste-pilha.o \
             ./testes/nums/nums.o              \
             ./$(OBJ_DIR)/pilha/pilha.o        \
             ./$(OBJ_DIR)/pilha/nodopilha.o
	$(CC) $^ -o $@ $(FLAGS)

teste-fila: ./testes/$(OBJ_DIR)/teste-fila.o \
            ./testes/nums/nums.o             \
            ./$(OBJ_DIR)/fila/fila.o         \
            ./$(OBJ_DIR)/fila/nodofila.o
	$(CC) $^ -o $@ $(FLAGS)

teste-lista: ./testes/$(OBJ_DIR)/teste-lista.o \
             ./testes/letra/letra.o            \
             ./$(OBJ_DIR)/lista/lista.o        \
             ./$(OBJ_DIR)/lista/nodolista.o
	$(CC) $^ -o $@ $(FLAGS)

./testes/$(OBJ_DIR)/teste-pilha.o: ./testes/teste-pilha.c     \
                                   ./$(INC_DIR)/pilha/pilha.h \
                                   ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./$(OBJ_DIR)/pilha/pilha.o: ./$(SRC_DIR)/pilha/pilha.c     \
                            ./$(INC_DIR)/pilha/pilha.h     \
                            ./$(INC_DIR)/pilha/nodopilha.h \
                            ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./$(OBJ_DIR)/pilha/nodopilha.o: ./$(SRC_DIR)/pilha/nodopilha.c \
                                ./$(INC_DIR)/pilha/nodopilha.h \
                                ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/$(OBJ_DIR)/teste-fila.o: ./testes/teste-fila.c    \
                                  ./$(INC_DIR)/fila/fila.h \
                                  ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./$(OBJ_DIR)/fila/fila.o: ./$(SRC_DIR)/fila/fila.c     \
                          ./$(INC_DIR)/fila/fila.h     \
                          ./$(INC_DIR)/fila/nodofila.h \
                          ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./$(OBJ_DIR)/fila/nodofila.o: ./$(SRC_DIR)/fila/nodofila.c \
                              ./$(INC_DIR)/fila/nodofila.h \
                              ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/$(OBJ_DIR)/teste-lista.o: ./testes/teste-lista.c     \
                                   ./$(INC_DIR)/lista/lista.h \
                                   ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./$(OBJ_DIR)/lista/lista.o: ./$(SRC_DIR)/lista/lista.c     \
                            ./$(INC_DIR)/lista/nodolista.h \
                            ./$(INC_DIR)/lista/lista.h     \
                            ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./$(OBJ_DIR)/lista/nodolista.o: ./$(SRC_DIR)/lista/nodolista.c \
                                ./$(INC_DIR)/lista/nodolista.h \
                                ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/letra/letra.o: ./testes/letra/letra.c \
                        ./testes/letra/letra.h \
                        ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/nums/nums.o: ./testes/nums/nums.c \
                      ./testes/nums/nums.h \
                      ./$(INC_DIR)/common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

objdirs:
	@mkdir -p ./$(OBJ_DIR)/{fila,lista,pilha}
	@mkdir -p ./testes/$(OBJ_DIR)

clean:
	$(RM) ./$(OBJ_DIR)/{fila,lista,pilha}/*.o
	$(RM) ./testes/{nums/nums,letra/letra}.o
	$(RM) ./testes/$(OBJ_DIR)/*.o

mrproper: clean
	$(RM) teste-{fila,lista,pilha}
