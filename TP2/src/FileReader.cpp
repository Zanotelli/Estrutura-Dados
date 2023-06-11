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

Point* FileReader::getPointVector(){

    Point vec[size];

    try{

        for(int i = 0; i < size; i++){

            char* x = strtok(data[i], " ");
            char* y = strtok(NULL, " ");

            Point point = new Point(x, y);
            vec[i] = point;
        }

    } catch(const std::exception & e) {

        throw std::runtime_error("ERROR: Wrong data format on input file.");

	}

    return vec;
}