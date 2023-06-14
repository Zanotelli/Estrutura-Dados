#include "../include/Line.h"

// Construtores

Line::Line(){
    init = nullptr;
    end = nullptr;
}

Line::Line(Point* i, Point* e){
    init = i;
    end = e;
}

Line::~Line(){
    delete init;
    delete end;
}

// Gets

Point* Line::getInit(){
    return init;
}

Point* Line::getEnd(){
    return end;
}


// Outro 

void Line::print(){
    init->print();
    end->print();
}