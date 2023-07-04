CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Node.o $(OBJ)/FileReader.o $(OBJ)/FileWriter.o $(OBJ)/Huffman.o $(OBJ)/main.o
HDRS = $(INC)/Node.h $(INC)/FileReader.h $(INC)/FileWriter.h $(INC)/Huffman.h
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) input.txt output.txt -c

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp 

$(OBJ)/FileReader.o: $(HDRS) $(SRC)/FileReader.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FileReader.o $(SRC)/FileReader.cpp 

$(OBJ)/FileWriter.o: $(HDRS) $(SRC)/FileWriter.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FileWriter.o $(SRC)/FileWriter.cpp 

$(OBJ)/Huffman.o: $(HDRS) $(SRC)/Huffman.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Huffman.o $(SRC)/Huffman.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out