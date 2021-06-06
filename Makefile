CC=gcc
FLAGS=-Wall -Wextra -Werror -Wpedantic -g
RM=rm -vf
SRC_DIR=src
INC_DIR=inc
OBJ_DIR=obj

.PHONY : all objdirs clean mrproper

all: objdirs teste-pilha teste-fila teste-lista

teste-pilha: ./testes/$(OBJ_DIR)/teste-pilha.o \
             ./testes/nums/nums.o \
             ./pilha/$(OBJ_DIR)/pilha.o \
             ./pilha/$(OBJ_DIR)/nodopilha.o
	$(CC) $^ -o $@ $(FLAGS)

teste-fila: ./testes/$(OBJ_DIR)/teste-fila.o \
            ./testes/nums/nums.o \
            ./fila/$(OBJ_DIR)/fila.o \
            ./fila/$(OBJ_DIR)/nodofila.o
	$(CC) $^ -o $@ $(FLAGS)

teste-lista: ./testes/$(OBJ_DIR)/teste-lista.o \
             ./testes/letra/letra.o \
             ./lista/$(OBJ_DIR)/lista.o \
             ./lista/$(OBJ_DIR)/nodolista.o
	$(CC) $^ -o $@ $(FLAGS)

./testes/$(OBJ_DIR)/teste-pilha.o: ./testes/teste-pilha.c \
                                   ./pilha/$(INC_DIR)/pilha.h \
                                   ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./pilha/$(OBJ_DIR)/pilha.o: ./pilha/$(SRC_DIR)/pilha.c \
                            ./pilha/$(INC_DIR)/pilha.h \
                            ./pilha/$(INC_DIR)/nodopilha.h \
                            ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./pilha/$(OBJ_DIR)/nodopilha.o: ./pilha/$(SRC_DIR)/nodopilha.c \
                                ./pilha/$(INC_DIR)/nodopilha.h \
                                ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/$(OBJ_DIR)/teste-fila.o: ./testes/teste-fila.c \
                                  ./fila/$(INC_DIR)/fila.h \
                                  ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./fila/$(OBJ_DIR)/fila.o: ./fila/$(SRC_DIR)/fila.c \
                          ./fila/$(INC_DIR)/fila.h \
                          ./fila/$(INC_DIR)/nodofila.h \
                          ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./fila/$(OBJ_DIR)/nodofila.o: ./fila/$(SRC_DIR)/nodofila.c \
                              ./fila/$(INC_DIR)/nodofila.h \
                              ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/$(OBJ_DIR)/teste-lista.o: ./testes/teste-lista.c \
                                   ./lista/$(INC_DIR)/lista.h \
                                   ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./lista/$(OBJ_DIR)/lista.o: ./lista/$(SRC_DIR)/lista.c \
                            ./lista/$(INC_DIR)/nodolista.h \
                            ./lista/$(INC_DIR)/lista.h \
                            ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./lista/$(OBJ_DIR)/nodolista.o: ./lista/$(SRC_DIR)/nodolista.c \
                                ./lista/$(INC_DIR)/nodolista.h \
                                ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/letra/letra.o: ./testes/letra/letra.c \
                        ./testes/letra/letra.h \
                        ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

./testes/nums/nums.o: ./testes/nums/nums.c \
                      ./testes/nums/nums.h \
                      ./common/macros.h
	$(CC) -c $< -o $@ $(FLAGS)

objdirs:
	@mkdir -p ./fila/$(OBJ_DIR)
	@mkdir -p ./lista/$(OBJ_DIR)
	@mkdir -p ./pilha/$(OBJ_DIR)
	@mkdir -p ./testes/$(OBJ_DIR)

clean:
	$(RM) ./fila/$(OBJ_DIR)/*.o
	$(RM) ./lista/$(OBJ_DIR)/*.o
	$(RM) ./pilha/$(OBJ_DIR)/*.o
	$(RM) ./testes/nums/nums.o
	$(RM) ./testes/letra/letra.o
	$(RM) ./testes/$(OBJ_DIR)/*.o

mrproper: clean
	$(RM) teste-fila teste-lista teste-pilha
