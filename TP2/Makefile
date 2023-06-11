CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/FileReader.o $(OBJ)/Solver.o $(OBJ)/main.o
HDRS = $(INC)/FileReader.h $(INC)/Solver.h
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/FileReader.o: $(HDRS) $(SRC)/FileReader.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FileReader.o $(SRC)/FileReader.cpp 

$(OBJ)/Solver.o: $(HDRS) $(SRC)/Solver.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Solver.o $(SRC)/Solver.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out