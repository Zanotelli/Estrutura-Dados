#include "../include/Huffman.h"


/* Variáveis auxiliares */
Node* head = nullptr;
Node* root;
FILE* inputFile;
FILE* outputFile;


/* Métodos */

void encode(const char* inFileName, const char* outFileName){

    inputFile = fopen(inFileName, "r");
    if(inputFile == NULL) throw std::runtime_error("ERROR: Input file could not be oppened");

    head = nullptr;
    root = nullptr;
    char c;

    while(fread(&c,sizeof(char),1, inputFile)!=0)
        add2NodeQueue(c);
    makeHuffmanTree();
    
    codefy(root, "\0");

    inputFile = fopen(inFileName, "r");
    outputFile = fopen(outFileName, "w");
    if(outputFile == NULL) throw std::runtime_error("ERROR: Output file could not be oppened");

    writeHeader();

    while(fread(&c,sizeof(char),1, inputFile)!=0)
        writeCode(c);
    
    fclose(inputFile);
    fclose(outputFile);
}


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

void add2NodeQueue(char c){

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

void makeHuffmanTree(){
    
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

void codefy(Node* p,char* code){

    char *lcode;
    char* rcode;
    static Node* node;
    static int flag;

    if(p != nullptr){
    
        if(p->type == 'l'){	
            if(flag ==0 ) {
                flag = 1; 
                head = p;
            }else { 
                node->next = p;
            }
            p->next = nullptr;
            node = p;
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

void writeHeader() {

    CodeType codeT;
    Node* node;
    int temp = 0;
    int i = 0;
    node = head;
    unsigned char N;

    while(node != nullptr) {

        temp += (strlen(node->code)) * (node->frequency);
        temp %= 8;
        i++;
        node = node->next;
    }

    if(i == 256)
        N=0;
    else 
        N=i;

    fwrite(&N,sizeof(unsigned char),1, outputFile);
    printf("Number of distinct characters: %u\n",i);

    node = head;
    while(node != NULL){

        codeT.c = node->data;
        strcpy(codeT.code, node->code);
        fwrite(&codeT, sizeof(CodeType), 1, outputFile);
        
        node = node->next;
    }
    
    char padding = 8 - (char)temp;

    fwrite(&padding,sizeof(char), 1, outputFile);
    for(i = 0; i < padding; i++)
        writeBit(0);

}

void writeBit(int n) {

	static char byte;
	static int count;
	char temp;
    
	if(n == 1) {	
        temp=1;
		temp = temp << (7 - count);
		byte = byte | temp;
	}
	count++;
	
	if(count == 8) {
        
		fwrite(&byte,sizeof(char),1,outputFile);
		count = 0; 
        byte = 0;
		return;
	}
	return;
}

void writeCode(char c){

    char* code = getCode(c);
    
	while(*code != '\0'){
		if(*code == '1')
			writeBit(1);
		else
			writeBit(0);
	    code++;
	}
	return;
}

char* getCode(char c) {
    
    Node* node = head;
	while(node != NULL) {

	    if(node->data == c)
		  return node->code;
	    node = node->next;
	}
	return NULL;
}
