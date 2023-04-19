#include "../include/Formula.h"


// CONSTRUCTOR

Formula::Formula(char * formula) {

    formQueue = Queue<char *>();

    char * word = strtok(formula, " ");

    while(word != NULL){
        formQueue.add(word);
        word = strtok(NULL, " ");
    }
    

}




// PUBLIC


// PRIVATE
/*
Queue<char *> Formula::buildPostFix() {
    return Queue<char *>();
}

Queue<char *> Formula::buildInFix() {
    return Queue<char *>();
}
*/