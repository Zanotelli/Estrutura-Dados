#ifndef SOLVER_H
#define SOLVER_H

#include <cstdio>
#include <stdexcept>

#include "Formula.h"

#define MAX_LENGTH 1000

class Solver
{
    public:
        Solver();
        ~Solver();
        void Execute(char *);
        void ClearMemory();
    private:
        Formula * formula;
        void Read(char *, int);
        void PostFix();
        void InFix();
        void Solve();

};

#endif