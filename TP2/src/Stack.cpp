#include "../include/Stack.h"

template <class T>
Stack<T>::Stack(){
	tamanho = 0;
}

template <class T>
Stack<T>::~Stack(){
	tamanho = 0;
}

template <class T>
bool Stack<T>::isEmpty(){
	if(tamanho == 0) return true;
	return false;
}

template <class T>
T Stack<T>::look() {
	try{

		return itens[tamanho - 1];

	}catch(const std::exception & e){
		throw std::runtime_error(e.what());
	}
}

template <class T>
T Stack<T>::remove() {
	
	try{

		T aux = itens[tamanho-1];
		tamanho--;
		return aux;

	}catch(const std::exception & e){
		throw std::runtime_error(e.what());
	}
}

template <class T>
void Stack<T>::add(T item) {
	itens[tamanho] = item;
	tamanho++;
}

template <class T>
int Stack<T>::GetTamanho(){
	return tamanho;
}

template class Stack<char*>;
template class Stack<double>;
template class Stack<Point*>;