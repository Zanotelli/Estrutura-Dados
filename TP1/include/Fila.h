#ifndef FILA_H
#define FILA_H

#include <stdexcept>

class Fila {
    public:
        Fila();
        ~Fila();
        void Enfileira(int item);
        int Desenfileira();
        void Limpa();
    protected:
        int tamanho;
        int frente;
        int tras;
        static const int MAXTAM = 10;
        int itens[MAXTAM];
};

#endif