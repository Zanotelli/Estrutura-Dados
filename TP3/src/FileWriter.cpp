#include "../include/FileWriter.h"

FileWriter::FileWriter(const char * filePath){
    file = fopen(filePath, "w");
    if(file == NULL) 
		throw std::runtime_error("ERROR: File not found");
}

FileWriter::~FileWriter(){
    fclose(file);
}


void FileWriter::encodeHeader(){
    
    Node *p;
    int temp=0,i=0;
    p=HEAD;
    while(p!=NULL)	//determine number of unique symbols and padding of bits
    {
        temp+=(strlen(p->code)) * (p->freq);		//temp stores padding
        if(strlen(p->code) > MAX) printf("\n[!] Codewords are longer than usual.");	//TODO: Solve this case
        temp%=8;
        i++;
        p=p->next;
    }

    if(i==256)
        N=0;	//if 256 diff bit combinations exist, then alias 256 as 0
    else 
        N=i;

    fwrite(&N,sizeof(unsigned char),1,f);	//read these many structures while reading
    printf("\nN=%u",i);

    p=HEAD;
    while(p!=NULL)	//start from HEAD, write each char & its code
    {
        record.x=p->x;
        strcpy(record.code,p->code);
        fwrite(&record,sizeof(symCode),1,f);
    //	printf("\n%c|%s",record.x,record.code);
        p=p->next;
    }
    //discard 'padding' bits before data, while reading
    padding=8-(char)temp;	//int to char & padding = 8-bitsExtra
    fwrite(&padding,sizeof(char),1,f);
    printf("\nPadding=%d",padding);
    //do actual padding
    for(i=0;i<padding;i++)
        writeBit(0,f);

}


void FileWriter::writeToFile(char* data){

}