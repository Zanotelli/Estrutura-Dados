CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/FileReader.o $(OBJ)/Solver.o $(OBJ)/Point.o $(OBJ)/Line.o $(OBJ)/Fecho.o $(OBJ)/main.o
HDRS = $(INC)/FileReader.h $(INC)/Solver.h $(INC)/Point.h $(INC)/Line.h $(INC)/Fecho.h
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

$(OBJ)/Point.o: $(HDRS) $(SRC)/Point.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Point.o $(SRC)/Point.cpp 

$(OBJ)/Line.o: $(HDRS) $(SRC)/Line.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Line.o $(SRC)/Line.cpp 

$(OBJ)/Fecho.o: $(HDRS) $(SRC)/Fecho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fecho.o $(SRC)/Fecho.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out