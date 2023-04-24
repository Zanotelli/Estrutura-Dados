#include "../include/Node.h"

template <class T>
Node<T>::Node(){
}

template <class T>
Node<T>::Node(T item){
    data = item;
    left = nullptr;
    rigth = nullptr;
}

template <class T>
Node<T>::~Node(){
    delete left;
    delete rigth;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
void Node<T>::setLeft(Node * node){
    left = node;
}

template <class T>
void Node<T>::setRigth(Node * node){
    rigth = node;
}

template <class T>
Node<T> * Node<T>::getLeft(){
    return left;
}

template <class T>
Node<T> * Node<T>::getRigth(){
    return rigth;
}

template class Node<char *>;