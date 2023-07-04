#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#include "Node.h"
#include "FileReader.h"

struct Huffman {
    public:
        Huffman(FileReader reader);
        char * getData();
    private:
        Node* head;
        Node* root;
        void dencode(char*);
        void encode(Node*, char*);
        void addNode(char);
        void insert(Node*, Node*);
        void makeTree();
};

#endif