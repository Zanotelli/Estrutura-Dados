#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#define MAX_DATA_LENGTH 1001
#define MAX_COMMAND_LENGTH 100

class FileReader{
    public:
        FileReader(const char *);
        int getSize();
        char* getLine(int);
        int[][] getDataVector();
    private:
        char data[MAX_DATA_LENGTH][MAX_COMMAND_LENGTH];
        int size = 0;
};

#endif