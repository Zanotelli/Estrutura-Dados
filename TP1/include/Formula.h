#ifndef FORMULA_H
#define FORMULA_H

#include <ctype.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>     /* atoi */
#include <stdexcept>

#include "Stack.h"
#include "BinaryTree.h"
#include "Node.h"

class Formula
{
    public:
        Formula(char *);
        ~Formula();
        void Solve();
        void buildFromInFix (char *);
        void buildFromPosFix(char *);
    private:
        BinaryTree tree;
        bool isValid();
};

#endif