CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Pilha.o $(OBJ)/Fila.o $(OBJ)/Teste.o $(OBJ)/main.o
HDRS = $(INC)/Pilha.h  $(INC)/Fila.h $(INC)/Teste.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Pilha.o: $(HDRS) $(SRC)/Pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Pilha.o $(SRC)/Pilha.cpp 

$(OBJ)/Fila.o: $(HDRS) $(SRC)/Fila.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fila.o $(SRC)/Fila.cpp 
	
$(OBJ)/Teste.o: $(HDRS) $(SRC)/Teste.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Teste.o $(SRC)/Teste.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out