#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 20

int main(int argc, char ** argv){

    FILE *fp;
    char commands[MAX_LINES];


    fp = fopen("../input.txt", "r"); 


    if(fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while(fgets(commands, MAX_LINES, fp) != NULL) {
        printf("%s", commands); // do something with each line in the file
    }

    fclose(fp);
    return 0;
}