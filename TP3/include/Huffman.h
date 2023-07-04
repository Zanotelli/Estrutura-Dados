#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#include "Node.h"

struct Huffman {
    public:
        Huffman();
        void encode(char*);
        void dencode(char*);
        char * getData();
    private:
        Node* head;
        Node* root;
};

#endif