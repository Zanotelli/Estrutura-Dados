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
        bool isPostFix(const char *);
        bool isInFix(const char *);
        const char * convert2PostFix(const char *);
        const char * convert2InFix(const char *);
        Pilha stack;
        Fila queue;
};

#endif
