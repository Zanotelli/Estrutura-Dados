#include <cstdio>
#include "../include/Teste.h"


Teste::Teste()
{
     printf("\n-------------INICIALIZA TESTADOR--------------\n");
    count_teste = 0;
    count_sucessos = 0;
    count_falhas = 0;
}

Teste::~Teste()
{
    printf("\n------------RESULTADOS DOS TESTES------------\n");
    printf("De %d testes, obteve-se:\n", count_teste);
    printf("- %d SUCESSOS\n", count_sucessos);
    printf("- %d FALHAS\n", count_falhas);

    int percent = (count_sucessos * 100.0) / count_teste  ;

    printf("PORCENTAGEM DE TESTES QUE PASSARAM: %d%\n", percent);
    printf("---------------------------------------------\n");

}

void Teste::AumentaCount()
{
    count_teste++;
}

void Teste::TestaInt(const char * texto, int num1, int num2)
{
    printf("[Teste %d] %s : ", (count_teste + 1), texto);

    if(num1 == num2)
    {
        printf("SUCESSO\n");
        count_sucessos++;
    }
    else{
        printf("FALHA\n");
        count_falhas++;
    }

    this->AumentaCount();
}

void Teste::TestaThrow(const char * texto, void (*func)(int), int num)
{
    printf("[Teste %d] %s : ", (count_teste + 1), texto);

    try
    {
        func(num);
    }
    catch(int num)
    {
        printf("FALHA\n");
        count_falhas++;
        return;
    }
    printf("SUCESSO\n");
    count_sucessos++;
    
}