#include <filesystem>
#include <vector>
#include <iostream>

#include "../include/FileReader.h"
#include "../include/Formula.h"
#include "../include/Solver.h"


const char* getPath(const char* filename){

    const char* basepath = "./inputs/";
    char* result = new char[strlen(basepath) + strlen(filename) + 1];

    strcpy(result, basepath);
    strcat(result, filename);

    return result;
}


int main() {

    //const char * directory_path = "./inputs";

    // Lê todos os arquivos na pasta de inputs
    /* for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            file_names.push_back(entry.path().filename().c_str());
        }
    } */


    //for (const auto& file_name : file_names) {
    //}


    FileReader reader = FileReader("./entdouble.s2.n5.p.in");
    Solver solver = Solver();

    for(int i = 0; i < reader.GetSize(); i++)
    {
        solver.Execute(reader.GetCommand(i));
    }
    printf("\n________________________\n");
   


    return 0;
}
