#include "../include/BinaryTree.h"

BinaryTree::BinaryTree(){
    head = nullptr;
}

BinaryTree::~BinaryTree(){
    deleteRecursive(head);
}

Node<char *> * BinaryTree::getHead(){
    return head;
}


void BinaryTree::unmount(Node<char *> * node, Queue<char *> * queue){
    if(node != nullptr) {
        unmount(node->getLeft(), queue);
        unmount(node->getRigth(), queue);
        queue->add(node->getData());
        delete node;
    }
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
    if(node != nullptr) {
        deleteRecursive(node->getLeft());
        deleteRecursive(node->getRigth());
        delete node;
    }
}