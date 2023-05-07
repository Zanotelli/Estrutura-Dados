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
}

Formula::Formula(char * formula, bool isInfix) {

    if( isInfix ){

        printf("In fixa \n");
        buildFromInFix(formula);

    } else{

        printf("Pos fixa \n");
        buildFromPosFix(formula);

    }
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

    tree = BinaryTree();
    Stack stack = Stack<Node<char *> *>();
    
    

    tree.insert(stack.remove());

}

// PRIVATE

void Formula::Solve(){

    Queue queue = Queue<char *>();

    tree.unmount(tree.getHead(), &queue);

    double solution = solveQueue(&queue);
    
    printf("# %f \n", solution);
}

double Formula::solveQueue(Queue<char*> * queue){

    double result = 0.0;
    Stack stackAux = Stack<double>();

    double a;
    double b;

    while (!queue->isEmpty()) {

        char * item = queue->remove();

        if (is_number(item)) {
            stackAux.add(atof(item));
        } else {
            b = stackAux.remove();
            a = stackAux.remove();
            
            if(strcmp(item, "+") == 0)
                result = a + b;
            else if (strcmp(item, "-") == 0) 
                result = a - b;
            else if (strcmp(item, "*") == 0)
                result = a * b;
            else if (strcmp(item, "/") == 0)
                result = a / b;
            
            stackAux.add(result);
        }
    }
    
    return result;
}

// Prints

void Formula::printPosFix(){

    tree.postOrderTrack(tree.getHead());
    printf("\n");
}