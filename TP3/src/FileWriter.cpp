#include "../include/FileWriter.h"

FileWriter::FileWriter(const char * filePath){

    FILE *file;
    file = fopen(filePath, "w");

    char line[2000];
    int count = 0;





    fclose(file);
}


void FileWriter::writeToFile(char* data){

}