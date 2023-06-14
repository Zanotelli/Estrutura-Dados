#ifndef SOLVER_H
#define SOLVER_H

#include <cstdio>
#include <stdexcept>
#include <ctime>

#include "Queue.h"
#include "Point.h"
#include "Line.h"
#include "Fecho.h"
#include "Graham.h"
#include "Jarvis.h"

#define MAX_LENGTH 1000

class Solver
{
    public:
        Solver();
        Solver(Point*);
        ~Solver();
        void execute();
        void printData();
    private:
        Point* data;
        Fecho fecho;
        int size = 0;
        double grahamMergeTime;
        double grahamInsertTime;
        double jarvisTime;
        void printSolution();
        Point* createAuxData();
};

#endif