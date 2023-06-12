#ifndef POINT_H
#define POINT_H

#include <stdexcept>
#include <iostream>

class Point{
    public:
        Point();
        Point(int, int);
        Point(char*, char*);
        ~Point();
        int getX();
        int getY();
        void print();
    private:
        int x;
        int y;
};

#endif