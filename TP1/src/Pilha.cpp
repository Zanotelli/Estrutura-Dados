#include "../include/Pilha.h"

Pilha::Pilha(){
	fila = Fila();
}

Pilha::~Pilha(){
	tamanho = 0;
}

bool Pilha::Vazia(){
	if(tamanho == 0) return true;
	return false;
}

int Pilha::Desempilha() {

	Fila filaAux = Fila();

	int aux;

	for(int i = 0; i < tamanho - 1; i++){
		aux = fila.Desenfileira();
		filaAux.Enfileira(aux);
	}

	aux = fila.Desenfileira(); 

	fila = filaAux;
	
	tamanho--;

	return aux;
}

void Pilha::Empilha(int item) {
	fila.Enfileira(item);
	tamanho++;
}

int Pilha::GetTamanho(){
	return tamanho;
}