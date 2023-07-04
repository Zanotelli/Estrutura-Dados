#include "../include/Huffman.h"

Huffman::Huffman(FileReader reader){
    head = nullptr;
    root = nullptr;
    char c;

    while(true){
        c = reader.getNextChar();
        addNode(c);
        if(reader.getIsOver()){
            break;
        }
    };

    makeTree();
    encode(root, "\0");	
}


void Huffman::dencode(char * data){

    
}

char* Huffman::getData(){

    
}



// Aux

void Huffman::makeTree(){
    
    Node* p = head;
    Node* q;
    printf("\nmake tree begin\n");
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
    printf("make tree end\n\n");
}

void Huffman::encode(Node *p,char* code){

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
        
        encode(p->left,lcode);
        encode(p->right,rcode);
    }
}

void Huffman::addNode(char c){

    Node *p,*q,*m;

    if(head == nullptr){
        printf("a\n");
        head = new Node(c);
        printf("a\n");
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

void Huffman::insert(Node *p,Node *m) { 
    if(m->next == nullptr) {
        m->next = p; 
        return;
    }

    while(m->next->frequency < p->frequency) {  
        m = m->next;
        if(m->next==nullptr) {
            m->next = p; 
            return;
        } 
    }

    p->next = m->next;
    m->next = p;
}