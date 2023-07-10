CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Node.o $(OBJ)/Encoder.o $(OBJ)/Decoder.o $(OBJ)/main.o
HDRS = $(INC)/Node.h $(INC)/Huffman.h
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) input.txt output.bin -c

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp 

$(OBJ)/Encoder.o: $(HDRS) $(SRC)/Encoder.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Encoder.o $(SRC)/Encoder.cpp 

$(OBJ)/Decoder.o: $(HDRS) $(SRC)/Decoder.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Decoder.o $(SRC)/Decoder.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out