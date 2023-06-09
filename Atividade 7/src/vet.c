//---------------------------------------------------------------------
// Arquivo	: vet.c
// Conteudo	: implementacao do TAD VET 
// Autor	: Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico	: 2022-04-01 - arquivo criado
//---------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vet.h"
#include "msgassert.h"

// limite superior da inicializacao aleatoria
#define INITRANDOMRANGE 10

void criaVetor(vetor_tipo * vet, int tam, int id)
// Descricao: cria vetor com dimensao tam
// Entrada: vet, tam, id
// Saida: vet
{
  // verifica se o valor tam e valido
  erroAssert(tam>0,"Dimensao nula");
  erroAssert(tam<=MAXTAM,"Dimensao maior que permitido");

  // inicializa as dimensoes da vetor
  vet->tam = tam;
  // inicializa o identificador da vetor, para rastreamento
  vet->id = id;
}

void inicializaVetorNulo(vetor_tipo * vet)
// Descricao: inicializa vet com valores nulos 
// Entrada: vet
// Saida: vet
{
  int i;
  // inicializa todos os elementos do vetor com 0, por seguranca 
  for (i=0; i<MAXTAM; i++){
    vet->v[i] = 0;
  }
}

void inicializaVetorAleatorio(vetor_tipo * vet, int x)
// Descricao: inicializa vet com valores aleatorios
// Entrada: vet 
// Saida: vet
{
  int i;
  srand48(x);
  // inicializa a vetor com valores nulos, por seguranca
  inicializaVetorNulo(vet);
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i=0; i<vet->tam; i++){
    vet->v[i] = drand48()*INITRANDOMRANGE;
  }
}

void imprimeVetor(vetor_tipo * vet)
// Descricao: imprime o vetor com a identificacao das posicoes
// Entrada: vet
// Saida: impressao na saida padrao (stdout) 
{
  int i;

  // seguranca, mas erro não deve acontecer jamais
  erroAssert(vet->tam<=MAXTAM,"Dimensao maior que permitido");

  // imprime os identificadores de posicao 
/*   for(i=0; i<vet->tam; i++)
    printf("%6d ",i);
  printf("\n");
 */
  // imprime o vetor
  for (i=0; i<vet->tam; i++){
    printf("%6.2f ",vet->v[i]);
  }
  printf("\n");
}

void escreveElemento(vetor_tipo * vet, int pos, double v)
// Descricao: atribui o valor v ao elemento (pos) de vet
// Entrada: vet, pos, v
// Saida: vet
{
  // verifica se pos e valido
  erroAssert((pos<0)||(pos>=vet->tam),"Indice invalido");

  vet->v[pos] = v;
}

double leElemento (vetor_tipo * vet, int pos)
// Descricao: retorna o elemento (pos) de vet 
// Entrada: vet, pos
// Saida: vet[pos] 
{
  // verifica se pos e valido
  erroAssert((pos<0)||(pos>=vet->tam),"Indice invalido");

  return vet->v[pos];
}

void copiaVetor(vetor_tipo *src, vetor_tipo * dst, int dst_id)
// Descricao: faz uma copia de src em dst
// Entrada: src, dst_id
// Saida: dst
{
  int i;

  // cria novamente a vetor dst para ajustar as suas dimensoes
  criaVetor(dst,src->tam, dst_id);
  // inicializa a vetor dst como nulo
  inicializaVetorNulo(dst);
  // copia os elementos do vetor src
  for (i=0; i<src->tam; i++){
    dst->v[i] = src->v[i];
  }
}

void somaVetores(vetor_tipo *a, vetor_tipo *b, vetor_tipo *c)
// Descricao: soma as vetores a e b e armazena o resultado em c
// Entrada: a, b
// Saida: c
{
  int i;
  // verifica se as dimensoes dos vetores a e b sao as mesmas
  erroAssert(a->tam==b->tam,"Dimensoes incompativeis");

  // inicializa o vetor c garantindo a compatibilidade das dimensoes
  criaVetor(c, a->tam, c->id);
  inicializaVetorNulo(c);

  // faz a soma elemento a elemento
  for (i=0; i<a->tam; i++){
    c->v[i] = a->v[i]+b->v[i];
  }
}

double produtoInternoVetores(vetor_tipo * a, vetor_tipo * b)
// Descricao: calcula produto interno dos vetores a e b
// Entrada: a,b
// Saida: s
{
  int i;
  double s=0.0;
  
  // verifica se as dimensoes dos vetores a e b sao as mesmas
  erroAssert(a->tam==b->tam,"Dimensoes incompativeis");

  // calcula o produto interno
  for (i=0; i<a->tam;i++){
    s += a->v[i]*b->v[i];
  }
  return s;
}

double normaVetor(vetor_tipo *a)
// Descricao: calcula a norma do vetor a
// Entrada: a
// Saida: s
{
  int i;
  double s = 0.0;
  
  // faz a transposicao como se a vetor fosse quadrada
  for (i=0; i<a->tam; i++){
    s+= (a->v[i])*(a->v[i]);
  }
  return sqrt(s);
}

void destroiVetor(vetor_tipo *a)
// Descricao: destroi a vetor a, que se torna inacessível
// Entrada: a
// Saida: a
{
  // apenas um aviso se a vetor for destruida mais de uma vez
  avisoAssert((a->tam>0),"Vetor já foi destruido");

  // torna as dimensoes invalidas
  a->id = a->tam = -1;
}
