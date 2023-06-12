#ifndef GRAHAM_H
#define GRAHAM_H

#include <stdlib.h>
#include <iostream>

#include "Stack.h"
#include "Point.h"
#include "SorterDic.h"

enum Sorters {
    MERGE,
    INSERT,
    BUCKET
};

Point* nextToTop(Stack<Point*> &S);
int orientation(Point p, Point q, Point r);
int dist(Point p1, Point p2);
void swap(Point* p1, Point* p2);
int compare(const void *vp1, const void *vp2);
void graham(Point points[], int size, Sorters sort);

#endif