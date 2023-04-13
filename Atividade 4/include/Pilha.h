#include "TipoItem.h"
#include "FilaBase.h"

class Pilha : public Fila {
	public:
		Pilha();
		~Pilha();
		void Empilha(TipoItem item);
		TipoItem Desempilha();
		void Imprime();
	private:
		int frente;
		int tras;
		static const int MAXTAM = 10;
		TipoItem itens[MAXTAM];	
};
