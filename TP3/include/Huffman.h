#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#include "Node.h"

/* Variáveis auxiliares */
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


/* Auxiliares Codificação */
void insert(Node*, Node*);
void add2NodeQueue(char);
void makeHuffmanTree();
void codefy(Node*, char*);
void writeBit(int);
void writeCode(char);
char *getCode(char);
void writeHeader();


/* Auxiliares Decodificação */
char* decodeData(char);
int checkIfEquals(char[], char[], int);
char *convertToStr(int n);

#endif