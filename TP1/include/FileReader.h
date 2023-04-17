#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#define MAX_DATA_LENGTH 100
#define MAX_COMMAND_LENGTH 100

class FileReader{
    public:
        FileReader(const char *);
        int GetSize();
        const char * GetCommand(int);
    private:
        char data[MAX_DATA_LENGTH][MAX_COMMAND_LENGTH];
        int size = 0;
};

#endif