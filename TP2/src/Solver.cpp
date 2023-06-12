#include "../include/Solver.h"

Solver::Solver(){
    data = new Queue();
    fecho = new Fecho();
    size = 0;
    grahamMergeTime = 0;
    grahamInsertTime = 0;
    grahamBucketTime = 0;
    jarvisTime = 0;
}

Solver::Solver(Queue<Point*> inData) {
    data = inData;
    fecho = new Fecho();
    size = data.getSize();
    grahamMergeTime = 0;
    grahamInsertTime = 0;
    grahamBucketTime = 0;
    jarvisTime = 0;
}

Solver::~Solver(){
    delete fecho;
    delete data;
}


void Solver::execute() {


    printSolution();
}

void Solver::printSolution(){
    
    printf("FECHO CONVEXO:\n");
   
    fecho.print();
   
    printf("\n");
    printf("GRAHAM+MERGESORT: %.3fs\n", grahamMergeTime/1000);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", grahamInsertTime/1000);
    printf("GRAHAM+BUCKETSORT: %.3fs\n", grahamBucketTime/1000);
    printf("JARVIS: %.3fs\n", jarvisTime/1000);
}