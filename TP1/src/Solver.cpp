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

    char command[10];

    int i = 0;
    for(; i < 10; i++)
    {
        if(data[i] != ' ' && data[i] != '\n' && data[i] != '\r')
        {
            command[i] = data[i];
        }
        else
        {
            break;
        }
    }


    if(command[0] == 'L') {
    printf("Comand: %s\n", command);
        Read(data, i);
    } else if (command[0] == 'P')
    {
        /* code */
    } else if (command[0] == 'I')
    {
        /* code */
    } else if (command[0] == 'R')
    {
        /* code */
    } else {
        printf("ERROR: Invalid command '%s'.\n", command);
    }
    
}


void Solver::Read(char * data, int i){

    char form[MAX_LENGTH];

    int j = 0;
    for(; j < MAX_LENGTH; j++) {
        if (data[i+j] == '\n' || data[i+j] == '\r') 
            break;
        if(data[i+j] != ' ') {
            form[j] = data[i+j];
        }
    }

    formula = new Formula(form);
}