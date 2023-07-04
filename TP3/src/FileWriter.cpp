#include "../include/FileWriter.h"

FileWriter::FileWriter(const char * filePath){
    file = fopen(filePath, "w");
    if(file == NULL) 
		throw std::runtime_error("ERROR: File not found");
}

FileWriter::~FileWriter(){
    fclose(file);
}



void FileWriter::writeToFile(char* data){

}