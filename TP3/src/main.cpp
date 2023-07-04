#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../include/FileReader.h"
#include "../include/FileWriter.h"
#include "../include/Huffman.h"


int main(int argc,char *argv[]) {

    if(argc <= 3)
		throw std::runtime_error("ERROR: Invalid arguments\n");

    const char* inpFileName = argv[1];
    const char* outFileName = argv[2];
    int op;


    // Define método a ser executado
    if( strcmp(argv[3], "-c") == 0)
        op = 1;
    else if (strcmp(argv[3], "-d") == 0) {
        op = 0;
    } else {
        throw std::runtime_error("ERROR: Invalid operation\n");
    }

    // Lê o raquivo
    FileReader reader = FileReader(inpFileName);

    Huffman huffman = Huffman();

    // Codifica / Decodifica
    if(op){
        huffman.encode( reader.getDataStr());
    } else {
        huffman.dencode(reader.getDataStr());
    }

    // Escreve no raquivo
    FileWriter writer = FileWriter(outFileName);
    writer.writeToFile(huffman.getData());
    
    printf("Success!!\n");
}