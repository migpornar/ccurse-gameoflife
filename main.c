#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITERACIONES 5
#define EJEX 6
#define EJEY 5
#include "funciones.c"

int main()
{
  int n;
  int i;
  int j;
  int matriz [EJEX][EJEY];
  for (i=0; i< EJEX; i++){
    for (j=0; j < EJEY; j++)
      matriz[i][j] = cerounoaleatorio();
  }
  imprimematriz(matriz);
  for(n=0; n < ITERACIONES; n++) {
    siguientematriz(matriz);
    imprimematriz(matriz);
  }
  return 0;
}


