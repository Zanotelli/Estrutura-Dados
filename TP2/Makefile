CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/FileReader.o $(OBJ)/SorterDic.o $(OBJ)/Solver.o $(OBJ)/Queue.o $(OBJ)/Stack.o $(OBJ)/Point.o $(OBJ)/Line.o $(OBJ)/Fecho.o $(OBJ)/Graham.o $(OBJ)/Jarvis.o $(OBJ)/main.o
HDRS = $(INC)/FileReader.h $(INC)/SorterDic.h $(INC)/Solver.h $(INC)/Queue.h $(INC)/Stack.h $(INC)/Point.h $(INC)/Line.h $(INC)/Fecho.h $(INC)/Graham.h $(INC)/Jarvis.h
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) ./ENTRADA1000.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/FileReader.o: $(HDRS) $(SRC)/FileReader.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FileReader.o $(SRC)/FileReader.cpp 

$(OBJ)/Solver.o: $(HDRS) $(SRC)/Solver.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Solver.o $(SRC)/Solver.cpp 

$(OBJ)/Queue.o: $(HDRS) $(SRC)/Queue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Queue.o $(SRC)/Queue.cpp 

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp 

$(OBJ)/Point.o: $(HDRS) $(SRC)/Point.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Point.o $(SRC)/Point.cpp 

$(OBJ)/Line.o: $(HDRS) $(SRC)/Line.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Line.o $(SRC)/Line.cpp 

$(OBJ)/Fecho.o: $(HDRS) $(SRC)/Fecho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fecho.o $(SRC)/Fecho.cpp 

$(OBJ)/Graham.o: $(HDRS) $(SRC)/Graham.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Graham.o $(SRC)/Graham.cpp 

$(OBJ)/Jarvis.o: $(HDRS) $(SRC)/Jarvis.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Jarvis.o $(SRC)/Jarvis.cpp 

$(OBJ)/SorterDic.o: $(HDRS) $(SRC)/SorterDic.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/SorterDic.o $(SRC)/SorterDic.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out