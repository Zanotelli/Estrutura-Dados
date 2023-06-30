#include "../include/Node.h"

Node::Node(){
    data = ' ';
    frequency = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(char dat, int freq){
    data = dat;
    frequency = freq;
    left = nullptr;
    right = nullptr;
}
