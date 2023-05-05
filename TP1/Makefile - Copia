CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/FileReader.o $(OBJ)/Solver.o $(OBJ)/Formula.o $(OBJ)/Stack.o $(OBJ)/Queue.o $(OBJ)/BinaryTree.o $(OBJ)/Node.o $(OBJ)/main.o
HDRS = $(INC)/FileReader.h $(INC)/Solver.h $(INC)/Formula.h $(INC)/Stack.h $(INC)/Queue.h $(INC)/BinaryTree.h $(INC)/Node.h 
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
	
$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp 

$(OBJ)/Queue.o: $(HDRS) $(SRC)/Queue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Queue.o $(SRC)/Queue.cpp 

$(OBJ)/Formula.o: $(HDRS) $(SRC)/Formula.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Formula.o $(SRC)/Formula.cpp 

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp 

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out