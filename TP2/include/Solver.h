#ifndef SOLVER_H
#define SOLVER_H

#include <cstdio>
#include <stdexcept>

#include "Queue.h"
#include "Point.h"
#include "Line.h"
#include "Fecho.h"

#define MAX_LENGTH 1000

class Solver
{
    public:
        Solver();
        Solver(Queue<Point*>);
        ~Solver();
        void execute();
    private:
        Queue<Point*> data;
        Fecho fecho;
        int size = 0;
        int grahamMergeTime;
        int grahamInsertTime;
        int grahamBucketTime;
        int jarvisTime;
        void printSolution();
};

#endif