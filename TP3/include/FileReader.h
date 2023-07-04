#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#define MAX_LINES 1000
#define MAX_LINE_LENGHT 100

class FileReader{
    public:
        FileReader(const char *);
        int getSize();
        char* getLine(int);
        char* getDataStr();
    private:
        char data[MAX_LINES][MAX_LINE_LENGHT];
        int size = 0;
};

#endif