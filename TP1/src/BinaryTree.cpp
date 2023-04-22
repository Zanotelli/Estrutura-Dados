#include "../include/BinaryTree.h"

BinaryTree::BinaryTree(){
    head = nullptr;
}

BinaryTree::~BinaryTree(){
    clear();
}

Node<char *> * BinaryTree::getHead(){
    return head;
}

void BinaryTree::clear(){
    deleteRecursive(head);
}

char * BinaryTree::unmount(Node<char *> * node) {

    if(node != nullptr) {
        if(node->getLeft() != nullptr)
            return unmount(node->getLeft());
        if(node->getRigth() != nullptr)
            return unmount(node->getRigth());
        
        char * aux = node->getData();
        printf("return: %s \n", node->getData());
        node = nullptr;
        return aux;
    }
    return NULL;
}


// INSERTS

void BinaryTree::insert(Node<char *> * node){
    head = node;
}

void BinaryTree::insertRecursive(Node<char *> * node){

    if(head == nullptr){
        head = node;
    } else {
        if(head->getLeft() == nullptr) {
            //insertRecursive()
        }
    }
}

void BinaryTree::deleteRecursive(Node<char *> * node){
    if(node != NULL) {
        deleteRecursive(node->getLeft());
        deleteRecursive(node->getRigth());
        delete node;
    }
}