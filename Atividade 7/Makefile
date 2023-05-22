CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Shellsort.o $(OBJ)/Heapsort.o $(OBJ)/main.o
HDRS = $(INC)/Shellsort.h  $(INC)/Heapsort.h
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Shellsort.o: $(HDRS) $(SRC)/Shellsort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Shellsort.o $(SRC)/Shellsort.cpp 

$(OBJ)/Heapsort.o: $(HDRS) $(SRC)/Heapsort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Heapsort.o $(SRC)/Heapsort.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out