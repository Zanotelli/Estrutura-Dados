#include "../include/Huffman.h"


/* Variáveis auxiliares */
Node* head = nullptr;
Node* root;
FILE* fileIn;
FILE* fileOut;
unsigned char N;

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

    // ===========

    fileIn = fopen(inFileName, "r");
    fileOut = fopen(outFileName, "w");
    if(fileOut == NULL) throw std::runtime_error("ERROR: Output file could not be oppened");

    outPutHeader();

    while(fread(&c,sizeof(char),1, fileIn)!=0)
        writeCode(c);
    
    // ===========

    fclose(fileIn);
    fclose(fileOut);
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


/* Auxiliares */

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
    printf("\nN = %u",i);

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

