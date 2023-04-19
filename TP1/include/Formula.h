#ifndef FORMULA_H
#define FORMULA_H

#include <ctype.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>     /* atoi */
#include <stdexcept>

#include "Queue.h"
#include "Stack.h"

class Formula
{
    public:
        Formula(char *);
    private:
        Queue<char *> inFix;
        Queue<char *> postFix;
        Queue<char *> formQueue;
        bool isPostFix(const char *);
        bool isInFix(const char *);
        Queue<char *> buildPostFix();
        Queue<char *> buildInFix();
};

#endif
