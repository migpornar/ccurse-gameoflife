#include <stdio.h>
#include <stdlib.h>
#define ITERACIONES 5
#define EJEX 6
#define EJEY 5
#define MATRIZDATO {{0,1,0,0,0},{0,0,1,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}

#include "funciones.c"

int main()
{
  int matriz [EJEX][EJEY] = MATRIZDATO;
  int n;
  imprimematriz(matriz);
  for(n=0; n < ITERACIONES; n++) {
    siguientematriz(matriz);
    imprimematriz(matriz);
  }
  return 0;
}


