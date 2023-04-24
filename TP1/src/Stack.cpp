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
	return itens[tamanho - 1];
}

template <class T>
T Stack<T>::remove() {

	T aux = itens[tamanho-1];
	
	tamanho--;

	return aux;
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

/* template <class T>
void Stack<T>::printStack(){
	printf("Stack: ");
	for(int i = 0; i < tamanho; i++){
		printf("%f ", itens[i]);
	}
	printf("\n");
} */


template class Stack<Node<char*>*>;
template class Stack<char*>;
template class Stack<double>;