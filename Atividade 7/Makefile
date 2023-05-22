CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/geraarvbin.o
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/geraarvbin

run:  $(EXE)
	$(EXE) -n 10 -o teste

$(BIN)/geraarvbin: $(OBJS)
	$(CC) -pg -o $(BIN)/geraarvbin $(OBJS) $(LIBS)

$(OBJ)/geraarvbin.o: $(HDRS) $(SRC)/geraarvbin.c
	$(CC) $(CFLAGS) -o $(OBJ)/geraarvbin.o $(SRC)/geraarvbin.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out