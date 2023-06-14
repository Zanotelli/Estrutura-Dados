#ifndef FECHO_H
#define FECHO_H

#include <stdexcept>

#include "./Line.h"

#define MAX_DATA_LENGTH 1001

class Fecho{
    public:
        Fecho();
        ~Fecho();
        void add(Line*);
        Line* pop();
        void print();
    private:
        Line* fecho_convexo[MAX_DATA_LENGTH];
        int size;
};

#endif