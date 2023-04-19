#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <class T>
class Queue {
    public:
        Queue();
        ~Queue();
        T look();
        void add(T item);
        T remove();
        void Limpa();
    protected:
        int tamanho;
        int frente;
        int tras;
        static const int MAXTAM = 200;
        T itens[MAXTAM];
};

#endif