#include "../include/Node.h"

Node::Node(){
    data = ' ';
    frequency = 0;
    type = 'l';
    left = nullptr;
    right = nullptr;
    next = nullptr;
}

Node::Node(char dat){
    data = dat;
    frequency = 1;
    type = 'l';
    left = nullptr;
    right = nullptr;
    next = nullptr;
}
