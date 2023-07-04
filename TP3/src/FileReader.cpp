#include "../include/FileReader.h"

FileReader::FileReader(const char * filePath)
{
    FILE *file;
    file = fopen(filePath, "r");

    char line[2000];
    int count = 0;

    if(file == NULL) 
		throw std::runtime_error("File not found");

    while ( fgets(line, sizeof(line), file))
    {
        strcpy(data[count], line);
        count++;
    }

    size = count;

    fclose(file);
}

int FileReader::getSize()
{
    return size;
}

char * FileReader::getLine(int i)
{
    if(i > size) 
		  throw std::runtime_error("Command does not exist\n");
    return data[i];
}

char * FileReader::getDataStr() {

    int n = 0;
    char str[MAX_LINES * MAX_LINE_LENGHT];


    return str;
}