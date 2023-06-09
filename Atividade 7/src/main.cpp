#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
#include <time.h>

#include "../include/vet.h"
#include "msgassert.h" 


void shell_sort(vetor_tipo * vec) {

    int i, j;
    int rep = 0;

    int count_trocas = 0;
    int h = vec->tam / 2;

    int numero_loop = 0;

    while (h > 0 && numero_loop < vec->tam * 10) {

        count_trocas = 0;

        for (i = h; i < vec->tam; i++) {
            double aux = vec->v[i];
            j = i;

            while (j >= h && aux < vec->v[j-h]) {
                vec->v[j] = vec->v[j-h];
                j -= h;
                rep++;
                count_trocas += 1;
            }

            vec->v[j] = aux;
        }
        
        if(count_trocas % 2 == 0) {
            h += h/4;
        } else {
            h -= h/4;
        } 

        numero_loop++;
    }

    h = 1;
    for (i = h; i < vec->tam; i++) {
        double aux = vec->v[i];
        j = i;

        while (j >= h && aux < vec->v[j-h]) {
            vec->v[j] = vec->v[j-h];
            j -= h;
            rep++;
            count_trocas += 1;
        }

        vec->v[j] = aux;
    }
}


void heapsort(vetor_tipo * vec) {

    int n = vec->tam;
    int i = n / 2, pai, filho;
    double t = 0;

    while(true) {
        if (i > 0) {
            i--;
            t = vec->v[i];
        } else {
            n--;
            if (n <= 0) return;
            t = vec->v[n];
            vec->v[n] = vec->v[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (vec->v[filho + 1] > vec->v[filho]))
                filho++;
            if (vec->v[filho] > t) {
                vec->v[pai] = vec->v[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        vec->v[pai] = t;
    }
}

void clkDiff(struct timespec t1, struct timespec t2,
                   struct timespec * res)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  if (t2.tv_nsec < t1.tv_nsec){
    // ajuste necessario, utilizando um segundo de tv_sec
    res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
  } else {
    // nao e necessario ajuste
    res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec;
  }
}


int main() {

    vetor_tipo vec_shell;
    vetor_tipo vec_heap;

    int count = 1;
    int retp;
    struct timespec inittp, endtp, restp;

    for(int i = 950; i < 1001; i++){

        printf("\n");

        criaVetor(&vec_shell, i, 1);
        inicializaVetorAleatorio(&vec_shell, i);
        criaVetor(&vec_heap, i, 1);
        inicializaVetorAleatorio(&vec_heap, i);
        
        printf("TESTE %d (N = %d)\n", count, i);

        retp = clock_gettime(CLOCK_MONOTONIC, &inittp);
        heapsort(&vec_heap);
  	    retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
        clkDiff(inittp, endtp, &restp);
  	    printf("Heapsort: %ld.%ld\n",restp.tv_sec,restp.tv_nsec);

        retp = clock_gettime(CLOCK_MONOTONIC, &inittp);
        shell_sort(&vec_shell);
  	    retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
        clkDiff(inittp, endtp, &restp);
  	    printf("Shellsort: %ld.%ld\n",restp.tv_sec,restp.tv_nsec);
        printf("\n");
        
        destroiVetor(&vec_shell);
        destroiVetor(&vec_heap);

        count++;
    }
    return 0;
}
