#include "../include/Solver.h"

Solver::Solver()
{
}

void Solver::SetCommand(const char * data)
{
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

    printf("Comand: %s\n", command);

    if(command[0] == 'L') {
        char formula[MAX_LENGTH];

        int j = 0;
        for(; j < MAX_LENGTH; j++) {
            if (data[i+j] == '\n' || data[i+j] == '\r') 
                break;
            if(data[i+j] != ' ') {
                formula[j] = data[i+j];
            }
        }

        Formula f = Formula(formula);
    }
}