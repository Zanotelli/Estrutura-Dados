#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstdio>

#include "Node.h"
#include "Stack.h"
#include "Queue.h"

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        Node<char *> * getHead();
        void insert(Node<char *> *);
        void unmount(Node<char *> * node, Queue<char *> * stack);
        void postOrderTrack(Node<char *> *);
        void clear();
    private:
        Node<char *> * head;
        void insertRecursive(Node<char *> *);
        void deleteRecursive(Node<char *> *);
        void byLevel();
        void preOrder(Node<char *> *);
        void inOrder(Node<char *> *);
        void posOrder(Node<char *> *);
};

#endif