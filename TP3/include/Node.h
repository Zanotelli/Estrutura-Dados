#ifndef NODE_H
#define NODE_H

struct Node {
    public:
        Node();
        Node(char);
        char data;        
        int frequency;  
        char type;   
        char* code;      
        Node* left;    
        Node* right;    
        Node* next;     
};

#endif