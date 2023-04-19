#include "../include/Queue.h"

template <class T>
Queue<T>::Queue(){
	frente = 0;
	tras = 0;
    tamanho = 0;
}

template <class T>
Queue<T>::~Queue(){
	frente = 0;
	tras = 0;
    tamanho = 0;
}

template <class T>
T Queue<T>::look(){
	if(tamanho > 0)
		return itens[tamanho-1];
	else
		return NULL;
}

template <class T>
void Queue<T>::add(T item){
    if (tamanho == MAXTAM)
		throw std::runtime_error("Fila Cheia!");
	itens[tras] = item;
	tras = (tras + 1) % MAXTAM;
	tamanho++;
}

template <class T>
T Queue<T>::remove(){
    T aux;
	if (tamanho == 0)
		throw std::runtime_error("Fila está vazia!");
	aux = itens[frente];
	frente = (frente + 1) % MAXTAM;
	tamanho--;
	return aux;
}

template class Queue<char *>;