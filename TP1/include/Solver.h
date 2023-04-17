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
        void SetCommand(const char *);
        float Solve();
        void ClearMemory();
    private:
        Formula * formula;
        char * SetFormula(Formula *);

};

#endif