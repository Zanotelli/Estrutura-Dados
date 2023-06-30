#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../include/FileReader.h"


int main(int argc,char *argv[]) {

    if(argc <= 3)
		throw std::runtime_error("ERROR: Invalid arguments\n");

    const char* inpFileName = argv[1];
    const char* outFileName = argv[2];
    int op;


    // Define método a ser executado
    if( strcmp(argv[3], "-c") )
        op = 1;
    else if (strcmp(argv[3], "-d")) {
        op = 0;
    } else {
        throw std::runtime_error("ERROR: Invalid operation\n");
    }

    printf("%d\n", op);
    
    FileReader reader = FileReader(inpFileName);
    
}