#ifndef SOLVER_H
#define SOLVER_H

#include <cstdio>
#include <stdexcept>

#include "./Point.h"

#define MAX_LENGTH 1000

class Solver
{
    public:
        Solver();
        Solver(Point*);
        ~Solver();
        void execute();
    private:
        Point* data;
        int size = 0;
        void printHeader();
};

#endif