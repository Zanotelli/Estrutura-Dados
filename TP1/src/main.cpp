#include <filesystem>
#include <vector>
#include <iostream>

#include "../include/FileReader.h"
#include "../include/Formula.h"
#include "../include/Solver.h"


int main() {

    FileReader reader = FileReader("./input.txt");
    Solver solver = Solver();

    for(int i = 0; i < reader.GetSize(); i++)
    {
        //printf("%s\n", reader.GetCommand(i));
        solver.Execute(reader.GetCommand(i));
    }
    printf("\n________________________\n");
   


    return 0;
}
