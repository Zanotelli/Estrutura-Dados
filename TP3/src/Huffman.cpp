#include "../include/Huffman.h"


/* Variáveis auxiliares */
Node* head = nullptr;
Node* root;
FILE* fileIn;
FILE* fileOut;
unsigned char N;
int numChars;

/* Métodos */

void encode(const char* inFileName, const char* outFileName){

    fileIn = fopen(inFileName, "r");
    if(fileIn == NULL) throw std::runtime_error("ERROR: Input file could not be oppened");

    head = nullptr;
    root = nullptr;
    char c;

    while(fread(&c,sizeof(char),1, fileIn)!=0)
        addNode(c);

    makeTree();
    codefy(root, "\0");

    fileIn = fopen(inFileName, "r");
    fileOut = fopen(outFileName, "w");
    if(fileOut == NULL) throw std::runtime_error("ERROR: Output file could not be oppened");

    outPutHeader();

    while(fread(&c,sizeof(char),1, fileIn)!=0)
        writeCode(c);
    
    fclose(fileIn);
    fclose(fileOut);
}

void decode(const char* inFileName, const char* outFileName){

    head = nullptr;
    root = nullptr;
    char padding;
    char reader;
    CodeType* codeTList;

    // Abre o arquivo de entrada
    fileIn = fopen(inFileName, "r");
    if(fileIn == NULL) throw std::runtime_error("ERROR: Input file could not be oppened");

    // Armazena o número de caracteres distintos
    if(fread(&reader,sizeof(char),1, fileIn) == 0)
        throw std::runtime_error("ERROR: Could not read the number N of distinct characters");    
    numChars = (reader == 0) ? DISTINC_CHAR_MAX : reader;
    printf("Detected: %d different characters\n", numChars);

    // Lê os dados codificados para todos os caracteres
    codeTList = (CodeType*) malloc(sizeof(CodeType) * numChars);
    if(fread(codeTList, sizeof(CodeType) , numChars, fileIn) == 0)
        throw std::runtime_error("ERROR: Counld not read the code table");

    // Número de 0's a esquerda utilizados para codificação
    if(fread(&reader, sizeof(char), 1, fileIn) == 0) 
        throw std::runtime_error("ERROR: Invalid padding size");
    padding = reader;      
    printf("Detected: %c | %d bit padding.\n",padding,padding);

    // Abre o aquivo de saída
    fileOut = fopen(outFileName, "w");
    if(fileOut == NULL) throw std::runtime_error("ERROR: Output file could not be oppened");

    // Decodifica e escreve (um char por vez)
    while(fread(&reader, sizeof(char), 1, fileIn) != 0) {

        char* decoded = decodeData(reader, padding, codeTList);
        
        int i=0;
        while(decoded[i] != '\0'){i++;};

        fwrite(decoded, sizeof(char), i-1, fileOut);
    }

    fclose(fileIn);
    fclose(fileOut);
}


/* Auxiliares Codificação */

void insert(Node *p, Node *m) { 

    if(m->next == nullptr) {
        m->next = p; 
        return;
    }

    while(m->next->frequency < p->frequency) {  
        m = m->next;
        if(m->next == nullptr) {
            m->next = p; 
            return;
        } 
    }
    p->next = m->next;
    m->next = p;
}

void addNode(char c){

    Node *p,*q,*m;

    if(head == nullptr){
        head = new Node(c);
        return;
    }
    
    p = head; 
    q = nullptr;

    if(p->data == c) {

        p->frequency++;

        if(p->next == nullptr)
            return;
        if(p->frequency > p->next->frequency) {

            head = p->next;
            p->next = nullptr;
            insert(p, head);
        }
        return;
    }

    while(p->next != nullptr && p->data != c) {
        q = p; 
        p = p->next;
    }

    if(p->data == c) {

        p->frequency++;
        if(p->next==NULL) return;

        if(p->frequency > p->next->frequency)
        {
            m = p->next;
            q->next=p->next;
            p->next=nullptr;
            insert(p,head);
        }

    } else {	
        q = new Node(c);
        q->next = head;
        head = q;
    }
    
}

void makeTree(){
    
    Node* p = head;
    Node* q;
    
	while(p != nullptr) {

		q = new Node('@');

		q->type = 'i';
		q->left = p;
		q->frequency = p->frequency;

		if(p->next!=NULL) {
			p = p->next;
			q->right = p;
			q->frequency += p->frequency;
		}

		p = p->next;

		if( p == nullptr) break;
        
        
		if(q->frequency <= p->frequency){
			q->next = p;
			p = q;
		} else
			insert(q,p);
	}

	root = q;
}

void codefy(Node *p,char* code){

    char *lcode,*rcode;
    static Node* s;
    static int flag;

    if(p != nullptr){
    
        if(p->type == 'l'){	
            if(flag ==0 ) {
                flag = 1; 
                head = p;
            }else { 
                s->next = p;
            }
            p->next = nullptr;
            s = p;
        }

        p->code = code;
        
        lcode = (char *)malloc(strlen(code)+2);
        rcode = (char *)malloc(strlen(code)+2);
        sprintf(lcode,"%s0",code);
        sprintf(rcode,"%s1",code);
        
        codefy(p->left,lcode);
        codefy(p->right,rcode);
    }
}

void outPutHeader() {

    CodeType codeT;
    Node* p;
    int temp = 0;
    int i = 0;
    p = head;

    while(p != nullptr) {

        temp += (strlen(p->code)) * (p->frequency);
        temp %= 8;
        i++;
        p = p->next;
    }

    if(i == 256)
        N=0;
    else 
        N=i;

    fwrite(&N,sizeof(unsigned char),1, fileOut);
    printf("N = %u\n",i);

    p = head;
    while(p!=NULL){

        codeT.c = p->data;
        strcpy(codeT.code, p->code);
        fwrite(&codeT, sizeof(CodeType), 1, fileOut);
        
        p=p->next;
    }

    
    
    char padding = 8 - (char)temp;

    fwrite(&padding,sizeof(char), 1, fileOut);
    for(i = 0; i < padding; i++)
        writeBit(0);

}

void writeBit(int b) {

	static char byte;
	static int cnt;
	char temp;
    
	if(b==1) {	
        temp=1;
		temp = temp<<(7-cnt);
		byte = byte | temp;
	}
	cnt++;
	
	if(cnt==8) {
        
		fwrite(&byte,sizeof(char),1,fileOut);
		cnt=0; 
        byte=0;
		return;
	}
	return;
}

void writeCode(char c){

    char *code = getCode(c);
    
	while(*code!='\0'){
		if(*code=='1')
			writeBit(1);
		else
			writeBit(0);
	    code++;
	}
	return;
}

char* getCode(char ch) {
    
    Node* p = head;
	while(p != NULL) {

	    if(p->data == ch)
		  return p->code;
	    p = p->next;
	}
	return NULL;
}


/* Auxiliares Decodificação */

char* decodeData(char b, char padding, CodeType* codeTList){

    int j=0,t;
    static int k;
    static int buffer;
    char* decoded = (char*) malloc(CODE_SIZE * sizeof(char));


    t=(int)b;
    t=t & 0x00FF;
    t=t<<8-k;
    buffer=buffer | t;
    k=k+8;

    if(padding!=0)
    {buffer=buffer<<padding;
    k=8-padding;
    padding=0;}

    int i = 0;
    while(i < numChars)
    {
        if(!match(codeTList[i].code, int2string(buffer),k))
        {	
            decoded[j++] = codeTList[i].c;	//match found inserted decoded
            t=strlen(codeTList[i].code);	//matched bits
            buffer=buffer<<t;		//throw out matched bits
            k=k-t;				//k will be less
            i=0;				//match from initial record
            //printf("\nBuffer=%s,removed=%c,k=%d",int2string(buffer),decoded[j-1],k);
            if(k==0) break;
            continue;
        }
    i++;
    }

    decoded[j]='\0';
    return decoded;
}

int match(char a[],char b[],int size) {
	b[strlen(a)] = '\0';
	b[size] = '\0';
	return strcmp(a,b);
}

char *int2string(int n) {
    
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