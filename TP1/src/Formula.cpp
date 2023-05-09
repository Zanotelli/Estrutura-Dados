#include "../include/Formula.h"

// UTIL

bool is_number(char * s) {
    char* end = nullptr;
    strtod(s, &end);
    return (end != s) && (*end == '\0') && (strcmp(s, "(") || strcmp(s, ")"));
}


// CONSTRUCTOR

Formula::~Formula(){
    tree.clear();
}

Formula::Formula(char * formula, bool isInfix) {

    try{
        if( isInfix ){

            buildFromInFix(formula);

        } else{

            buildFromPosFix(formula);

        }
    } catch(const std::exception & e){
        printf("ERROR: Couldn't build binary tree. %s.", e.what());
    }

}


void Formula::buildFromPosFix(char * formula) {

    try{
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

    }catch(const std::exception & e){

        throw std::runtime_error("Invalid PostFix formula");

	}
}

void Formula::buildFromInFix(char * formula) {    

    try{

        tree = BinaryTree();
        Stack stack = Stack<Node<char *> *>();
        
        char * word = strtok(formula, " ");

        while(word != NULL){
            
            Node<char*> * node = new Node(word);

            if(is_number(word)){

                stack.add(node);

            } else if (word[0] == '(') {

                stack.add(node);
                
            } else if (word[0] == ')') {

                Node<char*> * right = stack.remove();
                
                if (!stack.isEmpty() && stack.look()->getData()[0] == '(') {
                    Node<char*> * aux = stack.remove();     // Remove '('
                    delete aux;
                }

                if(!stack.isEmpty() && stack.look()->getData()[0] != '(' ){
                    
                    Node<char*> * op = stack.remove();
                    Node<char*> * left = stack.remove();
                    
                    op->setLeft(left);
                    op->setRigth(right);
                    
                    stack.add(op);

                } else {
                    stack.add(right);
                }

                delete node;

            } else {

                stack.add(node);

            }

            word = strtok(NULL, " ");
        }

        tree.insert(stack.remove());

    }catch(const std::exception & e){

        throw std::runtime_error("Invalid InFix formula");

	}

}

// PRIVATE

void Formula::Solve(){

    Queue queue = Queue<char *>();

    tree.unmount(tree.getHead(), &queue);

    double solution = solveQueue(&queue);
    
    printf("VAL: %f \n", solution);
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