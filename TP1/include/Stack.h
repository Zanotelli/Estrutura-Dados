#ifndef STACK_H
#define STACK_H

#include "./Queue.h"


template <class T>
class Stack {
	public:
		Stack();
		~Stack();
		void add(T item);
		T remove();
		T look();
		bool Vazia();
		int GetTamanho();
	private:
		Queue<T> fila;	
        int tamanho;
};

#endif