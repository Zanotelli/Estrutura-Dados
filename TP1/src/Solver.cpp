#include "../include/Solver.h"

Solver::Solver() {
    formula = NULL;
}

Solver::~Solver(){
    delete formula;
}


void Solver::Execute(char * data) {
    if(strlen(data) > MAX_LENGTH)
        throw std::runtime_error("Command is too big\n"); 

    char command[10] = " ";
    
    int i = 0;
    for(; i < MAX_LENGTH; i++)
    {
        if(data[i] != ' ' && data[i] != '\n' && data[i] != '\r'){
            command[i] = data[i];
        } else {
            break;
        }
    }


    if(command[0] == 'L') {

        i++;
        bool isInfix = data[i] == 'I' ? true : false;

        for(; i < MAX_LENGTH; i++) {
            if(data[i] == ' ') break;
        }
        Read(data, isInfix, (i + 1));

    } else if (command[0] == 'P') {

        PrintPosfix();

    } else if (command[0] == 'I') {

        /* code */

    } else if (command[0] == 'R') {

        Solve();

    } else {

        printf("ERROR: Invalid command '%s'.\n", command);

    }
    
}

void Solver::Solve() {

    if(formula == NULL){
        printf("ERROR: No formula on Solver memory!\n");
        return;
    }

    formula->Solve();
}


void Solver::Read(char * data, bool isInfix, int i){

    char form[MAX_LENGTH];

    for(int j = 0; j < MAX_LENGTH; j++) {

        if (data[i+j] == '\n' || data[i+j] == '\r') 
            break;

        form[j] = data[i+j];
        
    }

    Formula * formulaAux = new Formula(form, isInfix);

    if(formulaAux != nullptr)
        formula = formulaAux;
    else
        printf("INVALID FORMULA: '%s'\n", form);

}

void Solver::PrintPosfix(){

     if(formula == NULL){
        printf("ERROR: No formula on Solver memory!\n");
        return;
    }

    formula->printPosFix();
}