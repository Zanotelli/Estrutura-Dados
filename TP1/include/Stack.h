#ifndef STACK_H
#define STACK_H

#include "Node.h"

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
        static const int MAXTAM = 200;
        T itens[MAXTAM];	
        int tamanho;
};

#endif