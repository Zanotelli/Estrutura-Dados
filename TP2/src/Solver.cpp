#include "../include/Solver.h"

Solver::Solver(){
    data = nullptr;
    size = 0;
}

Solver::Solver(Point* inData) {
    /*
        implementar de alguma forma que o
        vetor tenha o tamanho certo no
        final
    */
   data = inData;
}

Solver::~Solver(){
    delete formula;
}


void Solver::execute() {


    printHeader();
}

void Solver::printHeader(){
    
    printf("FECHO CONVEXO:\n");

    for(int i = 0; i < size; i++){
        printf("%d %d\n", data[i][0], data[i][1]);
    }
    printf("\n");
}