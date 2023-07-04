#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#define MAX_DATA_LENGTH 1001
#define MAX_COMMAND_LENGTH 100

class FileWriter{
    public:
        FileWriter(const char *);
        void writeToFile(char*);
    private:
        char data[MAX_DATA_LENGTH][MAX_COMMAND_LENGTH];
        int size = 0;
};

#endif