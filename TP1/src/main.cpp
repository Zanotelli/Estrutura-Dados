#include "../include/FileReader.h"
#include "../include/Formula.h"
#include "../include/Solver.h"

int main()
{
    FileReader reader = FileReader("input.txt");
    Solver solver = Solver();

    for(int i = 0; i < reader.GetSize(); i++)
    {
        solver.Execute(reader.GetCommand(i));
    }

    return 0;
}