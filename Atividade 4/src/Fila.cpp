#include "Fila.h"

Fila::Fila(){
	frente = 0;
	tras = 0;
    tamanho = 0;
}

void Fila::Limpa(){
	frente = 0;
	tras = 0;
    tamanho = 0;
}

void Fila::Enfileira(int item){
    if (tamanho == MAXTAM)
		throw "Pilha Cheia!";
	itens[tras] = item;
	tras = (tras + 1) % MAXTAM;
	tamanho++;
}

int Fila::Desenfileira(){
    int aux;
	if (tamanho == 0)
		throw "Fila está vazia!";
	aux = itens[frente];
	frente = (frente + 1) % MAXTAM;
	tamanho--;
	return aux;
}