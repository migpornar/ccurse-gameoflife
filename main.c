#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITERACIONES 5
//#define EJEX 6
//#define EJEY 5
#include "funciones.c"

int main()
{
  int ejex, ejey;
  int** matriz;
 // int **matriz;
  printf("Introduce el numero de columnas: ");
  scanf("%d",&ejex);

  printf("Introduce el numero de filas: ");
  scanf("%d",&ejey);
  int n;
  int i;
  int j;
  //matriz= (int*)malloc(EJEY*sizeof(int*));
  matriz= (int**)malloc(ejey*sizeof(int*));
//  matriz = (int**)malloc(filas*sizeof(int*));
  if (matriz == NULL) {
    printf("No se ha podido reservar el espacio de memoria. \n");
    exit(1);
  }

  for(i = 0; i < ejey; i++){
    matriz[i] = (int*)malloc(ejex*sizeof(int*));
    if (matriz == NULL) {
      printf("No se ha podido reservar el espacio de memoria. \n");
      exit(1);
    }
  }
    
  for (i=0; i< ejex; i++){
    for (j=0; j < ejey; j++)
      matriz[i][j] = cerounoaleatorio();
  }
  imprimematriz(matriz,ejex,ejey);
  for(n=0; n < ITERACIONES; n++) {
    siguientematriz(matriz, ejex, ejey);
    imprimematriz(matriz,ejex,ejey);
  }
  free(matriz);
  return 0;
}


