#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#include "Node.h"

#define DISTINC_CHAR_MAX 256
#define CODE_SIZE 16

/* Objetos */
typedef struct CodeType { 
    char c;
    char code[CODE_SIZE];
}CodeType;

/* Métodos */
void encode(const char*, const char*);
void decode(const char*, const char*);
void outPutHeader();

/* Auxiliares Codificação */
void insert(Node*, Node*);
void addNode(char);
void makeTree();
void codefy(Node*, char*);
void writeBit(int);
void writeCode(char);
char *getCode(char);

/* Auxiliares Decodificação */
char* decodeData(char, char, CodeType*);
int match(char[], char[], int);
char *int2string(int n);





#endif