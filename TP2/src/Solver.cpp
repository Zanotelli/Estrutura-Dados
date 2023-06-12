#include "../include/Solver.h"

Solver::Solver(){
    data = nullptr;
    fecho = new Fecho();
    size = 0;
    grahamMergeTime = 0;
    grahamInsertTime = 0;
    grahamBucketTime = 0;
    jarvisTime = 0;
}

Solver::Solver(Point* inData) {
    
    fecho = new Fecho();
    size = 0;
    while (size < MAX_LENGTH && inData[size].isValid()) {
        ++size;
    }

    data = new Point[size];
    for (int i = 0; i < size; ++i) {
        data[i].set(inData[i].getX(), inData[i].getY());
    }
}

Solver::~Solver(){
    delete fecho;
    delete data;
}


void Solver::printData(){
    
    printf("Tamanho: %d\n", size);
    printf("Imprime todos os dados:\n");

    for(int i = 0; i < size; i++){
        printf("%d %d\n", data[i].getX(), data[i].getY());
    }
    printf("\n");
}

void Solver::execute() {

    clock_t start = clock();
    graham(data, size, MERGE);
    clock_t end = clock();
    grahamMergeTime = start - end;

    printSolution();
}

void Solver::printSolution(){
    
    printf("FECHO CONVEXO:\n");
   
    fecho->print();
   
    printf("\n");
    printf("GRAHAM+MERGESORT: %.3fs\n", grahamMergeTime/1000);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", grahamInsertTime/1000);
    printf("GRAHAM+BUCKETSORT: %.3fs\n", grahamBucketTime/1000);
    printf("JARVIS: %.3fs\n", jarvisTime/1000);
}