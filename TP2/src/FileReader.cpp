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

int[][] FileReader::getDataVector(){

    int vector[size][2];

    try{

        for(int i = 0; i < size; i++){

            char * word = strtok(formula, " ");
            int j = 0;

            while(word != NULL){
                vector[i][j] = atof(word);
                j++;
                word = strtok(NULL, " ");
            }
        }

    }catch(const std::exception & e){

        throw std::runtime_error("ERROR: Wrong data format on input file.");

	}

    return vector;
}