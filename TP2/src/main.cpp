#include <filesystem>
#include <vector>
#include <iostream>

#include "../include/FileReader.h"
#include "../include/Solver.h"


int main(int argc, char *argv[]) {

    FileReader reader = FileReader(argv[1]);
    Solver solver = Solver(reader.getPointVector());
    //solver.printData();
    solver.execute();

    return 0;
}
