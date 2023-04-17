#ifndef FORMULA_H
#define FORMULA_H

#include <string.h>

#include "Fila.h"
#include "Pilha.h"

class Formula
{
    public:
        Formula(const char *);
        const char * GetPost();
        const char * GetIn();
    private:
        const char * inFix;
        const char * postFix;
        bool isPostFix();
        bool isInFix();
        Pilha stack;
        Fila queue;
};

#endif
