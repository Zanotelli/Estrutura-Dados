#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

class FileReader{
    public:
        FileReader(const char *);
        ~FileReader();
        char* getNextLine();
        char getNextChar();
        bool getIsOver();
    private:
        int count = 0;
        FILE *file;
        bool isOver;
};

#endif