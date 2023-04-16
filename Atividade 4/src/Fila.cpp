#include "../include/Fila.h"
#include <stdexcept>

Fila::Fila(){
	frente = 0;
	tras = 0;
    tamanho = 0;
}

Fila::~Fila(){
	frente = 0;
	tras = 0;
    tamanho = 0;
}


void Fila::Enfileira(int item){
    if (tamanho == MAXTAM)
		throw std::runtime_error("Fila Cheia!");
	itens[tras] = item;
	tras = (tras + 1) % MAXTAM;
	tamanho++;
}

int Fila::Desenfileira(){
    int aux;
	if (tamanho == 0)
		throw std::runtime_error("Fila está vazia!");
	aux = itens[frente];
	frente = (frente + 1) % MAXTAM;
	tamanho--;
	return aux;
}