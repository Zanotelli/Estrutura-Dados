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
        void set(int, int);
        bool isValid();
    private:
        int x;
        int y;
};

#endif