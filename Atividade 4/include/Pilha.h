#include "Fila.h"


class Pilha {
	public:
		Pilha();
		~Pilha();
		void Empilha(int item);
		int Desempilha();
	private:
		Fila fila;	
};