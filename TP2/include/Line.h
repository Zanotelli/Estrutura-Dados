#ifndef LINE_H
#define LINE_H

#include <stdexcept>

#include "./Point.h"

class Line{
    public:
        Line();
        Line(Point*, Point*);
        ~Line();
        Point* getInit();
        Point* getEnd();
        void print();
    private:
        Point* init;
        Point* end;
};

#endif