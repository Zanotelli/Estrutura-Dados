#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../include/Huffman.h"

int main(int argc,char *argv[]) {

    if(argc <= 3)
		throw std::runtime_error("ERROR: Invalid arguments\n");

    const char* input = argv[1];
    const char* output = argv[2];
    int op;


    // Define método a ser executado
    if( strcmp(argv[3], "-c") == 0)
        op = 1;
    else if (strcmp(argv[3], "-d") == 0) {
        op = 0;
    } else {
        throw std::runtime_error("ERROR: Invalid operation\n");
    }

    if(op)
        encode(input, output);
    else
        decode(input, output);

    printf("Finished Huffman encoding/decoding execution.\n");
}