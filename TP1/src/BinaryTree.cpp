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

void BinaryTree::unmount(Node<char *> * node, Queue<char *> * queue){
    if(node != nullptr) {
        unmount(node->getLeft(), queue);
        unmount(node->getRigth(), queue);
        queue->add(node->getData());
    }
}

void BinaryTree::postOrderTrack(Node<char *> * node){
    if(node != nullptr) {
        postOrderTrack(node->getLeft());
        postOrderTrack(node->getRigth());
        printf("%s ", node->getData());
    }
}

void BinaryTree::inOrderTrack(Node<char *> * node){
    if(node != nullptr) {
        printf("(");
        inOrderTrack(node->getLeft());
        printf(" %s ", node->getData());
        inOrderTrack(node->getRigth());
        printf(")");
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