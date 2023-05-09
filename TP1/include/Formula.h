#ifndef FORMULA_H
#define FORMULA_H

#include <ctype.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Node.h"

class Formula
{
    public:
        Formula(char *, bool);
        ~Formula();
        void Solve();
        void buildFromInFix (char *);
        void buildFromPosFix(char *);
        void printPosFix();
    private:
        BinaryTree tree;
        double solveQueue(Queue<char*>*);
};

#endif