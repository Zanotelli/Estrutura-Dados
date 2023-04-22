#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        Node();
        Node(T item);
        ~Node();
        T getData();
        void setLeft(Node *);
        void setRigth(Node *);
        Node * getLeft();
        Node * getRigth();
    private:
        T data;
        Node * left;
        Node * rigth;
};

#endif