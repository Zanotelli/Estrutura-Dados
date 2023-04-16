#include <cstdio>
#include "../include/Pilha.h"
#include "../include/Teste.h"

int main()
{

    Pilha pilha = Pilha();
    Teste testador = Teste();

    testador.TestaInt("A pilha tem de estar vazia", pilha.Vazia(), 1);
    
    pilha.Empilha(0);

    testador.TestaInt("A pilha NÃO tem de estar vazia", pilha.Vazia(), 0);

    pilha.Empilha(1);
    pilha.Empilha(2);
    pilha.Empilha(3);


    testador.TestaInt("Tamanho de '4'", pilha.GetTamanho(), 4);
    
    int desempilhado =  pilha.Desempilha();

    testador.TestaInt("Desempilha '3'", desempilhado, 3);
    testador.TestaInt("Tamanho de '3'", pilha.GetTamanho(), 3);

    pilha.Empilha(4);
    pilha.Empilha(9);

    desempilhado = pilha.Desempilha();

    testador.TestaInt("Tamanho de '4'", pilha.GetTamanho(), 4);
    testador.TestaInt("Desempilha '9'", desempilhado, 9);

    pilha.Desempilha();
    pilha.Empilha(3);
    pilha.Empilha(4);
    pilha.Empilha(5);
    pilha.Empilha(6);
    pilha.Empilha(7);
    pilha.Empilha(8);
    pilha.Empilha(9);

    testador.TestaInt("Tamanho de '10'", pilha.GetTamanho(), 10);


    testador.TestaThrow("Tamanho de '10'", &pilha.Empilha, 10);
    pilha.Empilha(10);

    return 0;
}
