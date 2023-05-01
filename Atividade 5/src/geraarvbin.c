#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm{
  char nomesaida[200];
  int semente;
  int numno;
  FILE * saida;
  int treesize;
  int numlevel;
} prm_t;

void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr,"geraexp\n");
  fprintf(stderr,"\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr,"\t-s <num>\t(semente)\n");
  fprintf(stderr,"\t-n <num>\t(numero de nos)\n");
  fprintf(stderr,"\t-h\t(opcoes de uso)\n");
}

//==================================================

int posPre = 0;
int posPos = 0;
int posCtl = 0;

void criaPreOrdem(TipoNo * node, long * vec){
  if(node != NULL){
      vec[node->Reg.Chave] = posPre;
      posPre = posPre + 1;
      criaPreOrdem(node->Esq, vec);
      criaPreOrdem(node->Dir, vec);
  }
}

void criaPosOrdem(TipoNo * node, long * vec){
  if(node != NULL){
      criaPosOrdem(node->Esq, vec);
      criaPosOrdem(node->Dir, vec);
      vec[node->Reg.Chave] = posPos;
      posPos = posPos + 1;
  }
}

void criaCentral(TipoNo * node, long * vec){
  if(node != NULL){
      criaCentral(node->Esq, vec);
      vec[node->Reg.Chave] = posCtl;
      posCtl = posCtl + 1;
      criaCentral(node->Dir, vec);
  }
}

//==================================================

bool verificaPre(long * vec, int i, int j, int size){
  
  int i_pos = vec[i];
  int j_pos = vec[j];
/*   for(int a = 0; a < size; a++){
    if(vec[a] == (long) i){
      i_pos = a;
    }
    if(vec[a] == (long) j){
      j_pos = a;
    }
  } */
  return i_pos < j_pos;
}

bool verificaPos(long * vec, int i, int j, int size){
  int i_pos = vec[i];
  int j_pos = vec[j];
  return i_pos > j_pos;
}

bool verificaCtl(long * vec, int i, int j, int size, long rootVal){
  int i_pos = vec[i];
  int j_pos = vec[j];
  int maxVal_pos = vec[rootVal];
  return (i_pos <= maxVal_pos && j_pos <= maxVal_pos)
          || (i_pos >= maxVal_pos && j_pos >= maxVal_pos);
}

//==================================================

int ancestral(TipoNo * root, prm_t * prm, int i, int j){

  long preOrd[prm->treesize];
  long posOrd[prm->treesize];
  long centrl[prm->treesize]; 

  posPre = 0;
  posPos = 0;
  posCtl = 0;

  criaPreOrdem(root, preOrd);
  criaPosOrdem(root, posOrd);
  criaCentral (root, centrl);

  bool pre = verificaPre(preOrd,i,j,prm->treesize);
  bool pos = verificaPos(posOrd,i,j,prm->treesize);
  bool ctl = verificaCtl(centrl,i,j,prm->treesize,root->Reg.Chave);

  
  printf("(%d,%d)\n", i, j);
  printf("Pre: %d |", pre);
  printf(" Pos: %d |", pos);
  printf(" In : %d\n\n", ctl);
 

  if(pre && pos && ctl){
    return 1;
  } else {
    return 0;
  }
}


//==================================================

void parse_args(int argc, char ** argv, prm_t * prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
     extern char * optarg;
     extern int optind;
     int c ;
     // valores padrao
     prm->nomesaida[0] = 0;
     prm->semente = 0;
     prm->numno = 3;
     prm->numlevel = 2;
     // percorre a linha de comando buscando identificadores
     while ((c = getopt(argc, argv, "o:s:n:iph")) != EOF){
       switch(c) {
         case 'o':
	          // arquivo de saida
	          strcpy(prm->nomesaida,optarg);
                  break;
         case 's':
	          // semente aleatoria
	          prm->semente = atoi(optarg);
		  srand48((long) prm->semente);
		  break;
         case 'n':
	          // numero de nos
	          prm->numno = atoi(optarg);
		  prm->numlevel = ((int) log2((double) prm->numno))+4;
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     // verifica apenas o nome do arquivo de saida
     if (!prm->nomesaida[0]) {
       printf("Arquivo de saida nao definido.");
       exit(1);
     }
}

void dumpTree(TipoApontador * T, int level, prm_t * prm) {
  if ((*T) != NULL) {
    for(int i=0; i<level; i++) fprintf(prm->saida,"    ");
    fprintf(prm->saida," %3ld (%d)\n", (*T)->Reg.Chave,level);
    dumpTree(&(*T)->Esq,level+1,prm);
    dumpTree(&(*T)->Dir,level+1,prm);
  }
}

int createTree(TipoNo ** curr, int level, prm_t * prm){
  // create node
  (*curr) = (TipoNo*) malloc(sizeof(TipoNo));
  (*curr)->Esq = (*curr)->Dir = NULL;
  // set type
  if (drand48()>((8.0*(1<<level)*prm->treesize))/(((1<<prm->numlevel)*prm->numno))){
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
    if (prm->treesize<prm->numno) createTree(&((*curr)->Esq),level+1,prm);
    if (prm->treesize<prm->numno) createTree(&((*curr)->Dir),level+1,prm);
  } else {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
  }
  return prm->treesize;
}

int main(int argc, char *argv[])
{
  TipoNo *root;
  prm_t prm;
  int i,j;

  parse_args(argc,argv,&prm);
  prm.saida = fopen(prm.nomesaida,"wt");
  prm.treesize = 0;

  createTree(&root,0,&prm);
  dumpTree(&root,0,&prm);

  for (int k=0; k<prm.treesize; k++){
    i = j = 0;
    while (i==j){
      i = (int) (drand48()*prm.treesize);
      j = (int) (drand48()*prm.treesize);
    }
    fprintf(prm.saida,"%d testando ancestral(%d,%d)",k,i,j);
    int response = ancestral(root,&prm,i,j);   

    if(response){
      fprintf(prm.saida," - VERDADEIRO\n");
    } else {
      fprintf(prm.saida," - FALSO\n");
    }

  }

  fclose(prm.saida);
  return 0;
} 
