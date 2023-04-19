#include "../include/Stack.h"

template <class T>
Stack<T>::Stack(){
	fila = Queue<T>();
}

template <class T>
Stack<T>::~Stack(){
	tamanho = 0;
}

template <class T>
bool Stack<T>::Vazia(){
	if(tamanho == 0) return true;
	return false;
}

template <class T>
T Stack<T>::look() {
	return fila.look();
}

template <class T>
T Stack<T>::remove() {

	Queue<T> filaAux = Queue<T>();

	T aux;

	for(int i = 0; i < tamanho - 1; i++){
		aux = fila.remove();
		filaAux.add(aux);
	}

	aux = fila.remove(); 

	fila = filaAux;
	
	tamanho--;

	return aux;
}

template <class T>
void Stack<T>::add(T item) {
	fila.add(item);
	tamanho++;
}

template <class T>
int Stack<T>::GetTamanho(){
	return tamanho;
}

template class Stack<char *>;