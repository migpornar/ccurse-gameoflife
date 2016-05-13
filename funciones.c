#include "funciones.h"

void imprimematriz(int matriz [EJEX][EJEY])
{
  int i;
  int j;
  for (i = 0; i < EJEX ; i++) {
    printf("\n");
    for (j=0; j < EJEY ; j++)
      printf("%d ", matriz[i][j]);
  }
  printf("\n \n");
}

int arreglaindicesi(int i)
{
  if (i == EJEX)
    i = 0;
  if (i == -1)
    i = EJEX -1;
  return(i);
}
      
int arreglaindicesj(int j)
{
  if (j == EJEY)
    j = 0;
  if (j == -1)
    j = EJEY -1;
  return(j);
}

int cerounoaleatorio()
{
  return (rand() % 2);
}

int estadocelula(int matriz[EJEX][EJEY],int i, int j)
{
  i = arreglaindicesi(i);
  j = arreglaindicesj(j);
  return (matriz[i][j]);
}

int numerovecinos(int matriz [EJEX][EJEY], int i, int j)
{
  int suma;
  suma = 0; 
  suma =        estadocelula(matriz, i-1, j-1);
  suma = suma + estadocelula(matriz, i  , j-1);
  suma = suma + estadocelula(matriz, i+1, j-1);
  suma = suma + estadocelula(matriz, i-1, j  );
  suma = suma + estadocelula(matriz, i+1, j  );
  suma = suma + estadocelula(matriz, i-1, j+1);
  suma = suma + estadocelula(matriz, i  , j+1);
  suma = suma + estadocelula(matriz, i+1, j+1);
  return(suma);
}
  

void siguientematriz(int matriz [EJEX][EJEY])
 {
   int matrizsig [EJEX][EJEY];
   int i;
   int j;
   int suma;
   for(i=0; i < EJEX; i++) {
     for (j=0; j < EJEY; j++) {
       suma = numerovecinos(matriz, i, j);
       if(estadocelula(matriz,i,j) == 1) //SI LA CELULA ESTA VIVA
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
   for(i=0; i < EJEX; i++) {
     for (j=0; j < EJEY; j++)
       matriz[i][j] = matrizsig [i][j];
   }
 }

