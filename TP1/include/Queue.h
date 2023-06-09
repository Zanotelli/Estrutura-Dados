#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <class T>
class Queue {
	public:
		Queue();
		~Queue();
		void add(T item);
		T remove();
		bool isEmpty();
	private:
        static const int MAXTAM = 200;
        T itens[MAXTAM];	
        int size;
        int front;
        int back;
};

#endif