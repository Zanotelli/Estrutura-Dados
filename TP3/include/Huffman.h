#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#include "Node.h"

/* Objetos */
typedef struct CodeType { 
    char c;
    char code[16];
}CodeType;

/* Métodos */
void encode(const char*, const char*);

/* Auxiliares */
void insert(Node*, Node*);
void addNode(char);
void makeTree();
void codefy(Node*, char*);
void writeBit(int b);
void writeCode(char ch);
char *getCode(char ch);

void outPutHeader();


#endif