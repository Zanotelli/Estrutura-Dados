#include "./Fila.h"


class Pilha {
	public:
		Pilha();
		~Pilha();
		void Empilha(int item);
		int Desempilha();
		bool Vazia();
		int GetTamanho();
	private:
		Fila fila;	
        int tamanho;
};