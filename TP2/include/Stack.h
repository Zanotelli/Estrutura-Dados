#ifndef STACK_H
#define STACK_H

#include <type_traits>
#include <iostream>
#include <string>
#include <stdexcept>

#include "Point.h"

template <class T>
class Stack {
	public:
		Stack();
		~Stack();
		void add(T item);
		T remove();
		T look();
		bool isEmpty();
		int getSize();
		void invert();
	private:
        static const int MAXTAM = 200;
        T itens[MAXTAM];	
        int tamanho;
};

#endif