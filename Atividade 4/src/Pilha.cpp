#include "Pilha.h"

Pilha::Pilha(){
	fila = Fila();
}

int Pilha::Desempilha() {
	int aux;
	aux = fila.Desenfileira();
	return aux;
}

void Pilha::Empilha(int item) {
	fila.Enfileira(item);
}
