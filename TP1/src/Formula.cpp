#include "../include/Formula.h"

// UTIL

bool is_number(char * s) {
    char* end = nullptr;
    strtod(s, &end);
    return (end != s) && (*end == '\0');
}


// CONSTRUCTOR

Formula::~Formula(){
    tree.clear();
    delete &tree;
}

Formula::Formula(char * formula) {

    if( formula[0] == '(' ){
        printf("In fixa \n");
        buildFromInFix(formula);
    } else{
        printf("Pos fixa \n");
        buildFromPosFix(formula);
    }
}


// PRIVATE

void Formula::Solve(){

    BinaryTree auxTree = tree;
    Stack stack = Stack<char *>();

    double solution = 0.0;

    char * data = NULL;

    do{
        data = auxTree.unmount(auxTree.getHead());
        stack.add(data);

    } while (data != NULL);
    
    printf("SOLUTION: %d \n", solution);
}

void Formula::buildFromPosFix(char * formula) {

    tree = BinaryTree();
    Stack stack = Stack<Node<char *> *>();

    char * word = strtok(formula, " ");

     while(word != NULL){
        
        Node<char*> * node = new Node(word);

        if(is_number(word)){
            stack.add(node);
        } else {
            Node<char*> * r = stack.remove();
            Node<char*> * l = stack.remove();
            node->setRigth( r );
            node->setLeft ( l );
            stack.add(node);
        }

        word = strtok(NULL, " ");
    }

    tree.insert(stack.remove());
}


void Formula::buildFromInFix(char * word) {
/*
    tree = BinaryTree();
    Stack stack = Stack<Node<char *>>();

     while(word != NULL){
        
        

        word = strtok(NULL, " ");
    }*/
}