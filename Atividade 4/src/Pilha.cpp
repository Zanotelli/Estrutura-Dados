#include "Pilha.h"

Pilha::Pilha(){
	fila = Fila();
}

Pilha::~Pilha(){
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

	return aux;
}

void Pilha::Empilha(int item) {
	fila.Enfileira(item);
	tamanho++;
}
