#ifndef POINT_H
#define POINT_H

#include <stdexcept>

#define MAX_DATA_LENGTH 1001
#define MAX_COMMAND_LENGTH 100

class Point{
    public:
        Point();
        Point(int, int);
        Point(char*, char*);
        ~Point();
        int getX();
        int getY();
    private:
        int x;
        int y;
};

#endif