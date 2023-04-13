#include "Pilha.h"

Pilha::Pilha(){
	frente = 0;
	tras = 0;
}

Pilha::~Pilha(){
	frente = 0;
	tras = 0;
	tamanho = 0;
	itens = new TipoChave[MAXTAM];
}

TipoItem Pilha::Desempilha() {
	TipoItem aux;
	if (tamanho == 0)
		throw "Fila está vazia!";
	aux = itens[frente];
	// fila circular
	frente = (frente + 1) % MAXTAM;
	tamanho--;
	return aux;
}

void Pilha::Empilha(TipoItem item) {
	if (tamanho == MAXTAM)
		throw "Pilha Cheia!";
	itens[tras] = item;
	// fila circular
	tras = (tras + 1) % MAXTAM;
	tamanho++;
}

void Pilha::Imprime(){
	int count = frente;
	for(int i=0; i < tamanho; i++){
		if(count>=MAXTAM)
			count = 0;
		//printf("%d", itens[count]);
		count++;
	}
}