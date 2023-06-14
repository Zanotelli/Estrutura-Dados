#include "../include/Solver.h"

Solver::Solver(){
    data = nullptr;
    size = 0;
    grahamMergeTime = 0;
    grahamInsertTime = 0;
    jarvisTime = 0;
}

Solver::Solver(Point* inData) {
    
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
    delete[] data;
}


void Solver::printData(){
    
    printf("Tamanho: %d\n", size);
    printf("Imprime todos os dados:\n");

    for(int i = 0; i < size; i++){
        printf("%d %d\n", data[i].getX(), data[i].getY());
    }
    printf("\n");
}

Point* Solver::createAuxData() {

    Point* auxData = new Point[size];
    for(int i = 0; i < size; i++){
        auxData[i] = Point(data[i].getX(), data[i].getY());
    }
    return auxData;
}

void Solver::execute() {
 
    Point* auxData = createAuxData();

    // Mergesort
    clock_t start = clock();
    fecho = graham(auxData, size, 'M');
    clock_t end = clock();
    grahamMergeTime = end - start; 

    // Insertionsort
    auxData = createAuxData();
    start = clock();
    graham(auxData, size, 'I');
    end = clock();
    grahamMergeTime = end - start;

    // Jarvis
    printf("\n");
    auxData = createAuxData();
    start = clock();
    jarvis(auxData, size);
    end = clock();
    jarvisTime = end - start;

    printSolution();

}

void Solver::printSolution(){
    
    printf("FECHO CONVEXO:\n");
   
    fecho.print();
   
    printf("\n");
    printf("GRAHAM+MERGESORT: %.3fs\n", grahamMergeTime/1000);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", grahamInsertTime/1000);
    printf("JARVIS: %.3fs\n", jarvisTime/1000);
}