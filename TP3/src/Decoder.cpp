#include "../include/Huffman.h"

FILE* fileIn;
FILE* fileOut;

int numChars;
char padding;
CodeType* codeTList;

/* Métodos */

void decode(const char* inFileName, const char* outFileName){
    
    char reader;
    CodeType* codeTList;

    // Abre o arquivo de entrada
    fileIn = fopen(inFileName, "r");
    if(fileIn == NULL) throw std::runtime_error("ERROR: Input file could not be oppened");

    
    // Armazena o número de caracteres distintos
    if(fread(&reader, sizeof(unsigned char), 1, fileIn) == 0)
        throw std::runtime_error("ERROR: Could not read the number N of distinct characters");    
    numChars = (reader == 0) ? DISTINC_CHAR_MAX : reader;
    printf("Number of distinct characters: %u\n", numChars);


    // Lê os dados codificados para todos os caracteres
    codeTList = (CodeType*) malloc(sizeof(CodeType) * numChars);
    if(fread(codeTList, sizeof(CodeType) , numChars, fileIn) == 0)
        throw std::runtime_error("ERROR: Counld not read the code table");


    // Número de 0's a esquerda utilizados para codificação
    if(fread(&reader, sizeof(char), 1, fileIn) == 0) 
        throw std::runtime_error("ERROR: Invalid padding size");
    padding = reader;


    // Abre o aquivo de saída
    fileOut = fopen(outFileName, "w");
    if(fileOut == NULL) throw std::runtime_error("ERROR: Output file could not be oppened");


    // Decodifica e escreve (um char por vez)
    try{
        while(fread(&reader, sizeof(char), 1, fileIn) != 0) {

            char* decoded = decodeData(reader);
            
            int i=0;
            while(decoded[i] != '\0'){i++;};

            fwrite(decoded, sizeof(char), i-1, fileOut);
        }
    } catch (std::exception& e) {
        throw std::runtime_error("ERROR: Corrupted file");
    }
    

    fclose(fileIn);
    fclose(fileOut);
}

char* decodeData(char b){

    int j=0,t;
    static int k;
    static int buffer;
    char* decoded = (char*) malloc(CODE_SIZE * sizeof(char));


    t=(int)b;
    t=t & 0x00FF;
    t=t<<8-k;
    buffer=buffer | t;
    k=k+8;

    if(padding!=0){
        buffer=buffer<<padding;
        k=8-padding;
        padding=0;
    }

    int i = 0;
    while(i < numChars)
    {
        if(!checkIfEquals(codeTList[i].code, convertToStr(buffer),k))
        {	
            decoded[j++] = codeTList[i].c;
            t=strlen(codeTList[i].code);
            buffer=buffer<<t;
            k=k-t;
            i=0;
            if(k==0) break;
            continue;
        }
    i++;
    }

    decoded[j]='\0';
    return decoded;
}

int checkIfEquals(char* a,char b[],int size) {
	b[strlen(a)] = '\0';
	b[size] = '\0';
	return strcmp(a,b);
}

char* convertToStr(int n) {
    
    int comparator, aux, count = 0;

    char* temp=(char*) malloc(CODE_SIZE * sizeof(char));

    for(int i = CODE_SIZE-1; i >= 0; i--){

        comparator = 1<<i;
        aux = (n & comparator);
        if(aux==0) temp[count++]='0'; else temp[count++]='1';
    }
    temp[count]='\0';
    return temp;
}