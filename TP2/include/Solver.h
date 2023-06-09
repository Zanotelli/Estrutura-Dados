#ifndef SOLVER_H
#define SOLVER_H

#include <cstdio>
#include <stdexcept>

#define MAX_LENGTH 1000

class Solver
{
    public:
        Solver();
        Solver(int[][]);
        ~Solver();
        void execute();
    private:
        int data[MAX_LENGTH][2];
        int size = 0;
        void printHeader();
};

#endif