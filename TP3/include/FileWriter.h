#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdexcept>

#include "Node.h"


class FileWriter{
    public:
        FileWriter(const char *);
        ~FileWriter();
        void writeToFile(char*);
    private:
        FILE *file;
        void encodeHeader();
        char x;
        char code[16];
};

#endif