#include "mundo.c"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>
#define ITERACIONES 5


int main()
{
  int ejex, ejey;
  //int *matriz;
  printf("Introduce el numero de columnas: ");
  scanf("%d",&ejex);

  printf("Introduce el numero de filas: ");
  scanf("%d",&ejey);
  
  matriz = mundo_inicializar(ejex,ejey);

  int n;
  int i;
  int j;

  for (i=0; i< ejex; i++){
    for (j=0; j < ejey; j++)
      *(matriz + ejey*j + i) = cerounoaleatorio();
  }

  mundo_imprimematriz(*matriz,ejex,ejey);
  for(n=0; n < ITERACIONES; n++) {
    mundo_siguientematriz(*matriz, ejex, ejey);
    mundo_imprimematriz(*matriz,ejex,ejey);
  }
  mundo_free(matriz);
  return 0;
}


