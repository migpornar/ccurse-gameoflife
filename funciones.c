#include "funciones.h"

void imprimematriz(int **matriz, int ejex, int ejey)
{
  int i;
  int j;
  for (i = 0; i < ejex ; i++) {
    printf("\n");
    for (j=0; j < ejey ; j++)
      printf("%d ", matriz[i][j]);
  }
  printf("\n \n");
}

int arreglaindicesi(int i, int ejex)
{
  if (i == ejex)
    i = 0;
  if (i == -1)
    i = ejex -1;
  return(i);
}
      
int arreglaindicesj(int j, int ejey)
{
  if (j == ejey)
    j = 0;
  if (j == -1)
    j = ejey -1;
  return(j);
}

int cerounoaleatorio()
{
  return (rand() % 2);
}

int estadocelula(int **matriz,int i, int j,int ejex, int ejey)
{
  i = arreglaindicesi(i, ejex);
  j = arreglaindicesj(j, ejey);
  return (matriz[i][j]);
}

int numerovecinos(int **matriz, int i, int j, int ejex, int ejey)
{
  int suma;
  suma = 0; 
  suma =        estadocelula(matriz, i-1, j-1, ejex, ejey);
  suma = suma + estadocelula(matriz, i  , j-1, ejex, ejey);
  suma = suma + estadocelula(matriz, i+1, j-1, ejex, ejey);
  suma = suma + estadocelula(matriz, i-1, j  , ejex, ejey);
  suma = suma + estadocelula(matriz, i+1, j  , ejex, ejey);
  suma = suma + estadocelula(matriz, i-1, j+1, ejex, ejey);
  suma = suma + estadocelula(matriz, i  , j+1, ejex, ejey);
  suma = suma + estadocelula(matriz, i+1, j+1, ejex, ejey);
  return(suma);
}
  

void siguientematriz(int **matriz,int ejex, int ejey)
 {
   int matrizsig [ejex][ejey];
   int i;
   int j;
   int suma;
   for(i=0; i < ejex; i++) {
     for (j=0; j < ejey; j++) {
       suma = numerovecinos(matriz, i, j, ejex, ejey);
       if(estadocelula(matriz, i, j, ejex, ejey) == 1) //SI LA CELULA ESTA VIVA
	 {
	   if ((suma == 2)||(suma == 3))
	     matrizsig[i][j] = 1;
	   else 
	     matrizsig[i][j] = 0;
	 } else { //SI LA CELULA ESTA MUERTA
	 if (suma == 3)
	   matrizsig[i][j] = 1;
	 else 
	   matrizsig[i][j] = 0;
       }
     }
   }
   for(i=0; i < ejex; i++) {
     for (j=0; j < ejey; j++)
       matriz[i][j] = matrizsig [i][j];
   }
 }

