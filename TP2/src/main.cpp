#include <filesystem>
#include <vector>
#include <iostream>

#include "../include/FileReader.h"
#include "../include/Solver.h"


int main(int argc, char *argv[]) {

    FileReader reader = FileReader(argv[1]);

    char[][] data = reader.getDataVector();

    Solver solver = Solver(reader.getDataVector());
    solver.execute();

    return 0;
}
