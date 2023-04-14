#include "Pilha.h"

using namespace std;

int main(){

    Pilha pilha = Pilha();


    //cout << "Hello";

    pilha.Empilha(0);
    pilha.Empilha(1);
    pilha.Empilha(2);
    pilha.Empilha(3);

    int aux = pilha.Desempilha();

    //cout << aux;

    return 0;
}