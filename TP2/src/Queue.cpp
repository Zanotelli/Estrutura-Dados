#include "../include/Queue.h"

template <class T>
Queue<T>::Queue(){
	size = 0;
    front = 0;
    back = 0;
}

template <class T>
Queue<T>::~Queue(){
	size = 0;
    front = 0;
    back = 0;
}

template <class T>
void Queue<T>::add(T item){
	itens[back] = item;
	back = (back + 1) % MAXTAM;
	size++;
}

template <class T>
T Queue<T>::remove(){
    T aux;
	aux = itens[front];
	front = (front + 1) % MAXTAM;
	size--;
	return aux;
}

template <class T>
bool Queue<T>::isEmpty(){
    return front == back ? true : false;
}

template <class T>
int Queue<T>::getSize(){
    return size;
}


template class Queue<Node<char*>*>;
template class Queue<char*>;
template class Queue<Point*>;