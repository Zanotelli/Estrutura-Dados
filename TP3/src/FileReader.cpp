#include "../include/FileReader.h"

FileReader::FileReader(const char * filePath)
{
    
    file = fopen(filePath, "r");

    if(file == NULL) 
		throw std::runtime_error("ERROR: File not found");

    isOver = false;
}

FileReader::~FileReader(){
    fclose(file);
}


char* FileReader::getNextLine()
{
    char* line;

    if(fgets(line, sizeof(line), file) == NULL){
        isOver = true;
        return "";
    }

    return line;
}

char FileReader::getNextChar()
{
    char c;

    if(fread(&c, sizeof(char), 1, file) != 0){
        printf("%c", c);
        return c;
    }

    isOver = true;
    return '\0';
}

bool FileReader::getIsOver(){
    return isOver;
}