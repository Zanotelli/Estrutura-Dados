#ifndef GRAHAM_H
#define GRAHAM_H

#include <stdlib.h>
#include <iostream>
#include <stdexcept>

#include "Stack.h"
#include "Point.h"
#include "SorterDic.h"


Point nextToTop(Stack<Point>& S);
int orientation(Point p, Point q, Point r);
int dist(Point p1, Point p2);
void swap(Point& p1, Point& p2);
void graham(Point* points, int size, char sort);

#endif