#include "../include/Point.h"

// Construtores

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int a, int b){
    x = a;
    y = b;
}

Point::Point(char* a, char* b){
    x = atof(a);
    y = atof(b);
}

Point::~Point(){}

// Gets

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::print(){
    printf("%d %d\n", x, y);
}