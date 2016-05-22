#include "mundo.h"
#define ATTR_SET(flags,attr)   (flags) |= (1<<(attr))
#define ATTR_IS_SET(flags,attr)     ((flags) & (1<<(attr)))


struct mundo* mundo_inicializar(int ejex,int ejey)
{
  struct mundo * world;
  world = (struct mundo*)malloc(sizeof(struct mundo));
  
  if (!world)
    return NULL;
  
  world->filas=ejex;
  world->columnas=ejey;
  
  int* matriz = matriz_alloc(ejex, ejey);
  if (!matriz) {
    return NULL;
  }
  world->matriz = matriz;
  
  int* matrizsig = matriz_alloc(ejex, ejey);
  if (!matrizsig) {
    return NULL;
  }
  world->matrizsig = matrizsig;
  return world;
}

int* matriz_alloc(int ejex,int ejey)
{
  int * matriz;
  matriz = (int *)malloc (ejex * ejey * sizeof(int *));
  
  if (!matriz)
    return NULL;
  int i;
  int j;
  for (i=0; i<ejex; i++) {
    for (j=0; j<ejey; j++)
      *(matriz + i * ejey + j) = 0;
  }
  return matriz;
}

void mundo_imprimematriz(int *matriz, int ejex, int ejey)
{
  int i;
  int j;
  for (i = 0; i < ejex ; i++) {
    printf("\n");
    for (j=0; j < ejey ; j++)
      printf("%d ", *(matriz+ i + j*ejey));
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

int mundo_estadocelula(int *matriz,int i, int j,int ejex, int ejey)
{
  i = arreglaindicesi(i, ejex);
  j = arreglaindicesj(j, ejey);
  return (*(matriz + i + j*ejey));
}

int mundo_numerovecinos(int *matriz, int i, int j, int ejex, int ejey)
{
  int suma;
  suma = 0; 
  suma =        mundo_estadocelula(matriz, i-1, j-1, ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i  , j-1, ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i+1, j-1, ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i-1, j  , ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i+1, j  , ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i-1, j+1, ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i  , j+1, ejex, ejey);
  suma = suma + mundo_estadocelula(matriz, i+1, j+1, ejex, ejey);
  return(suma);
}


void mundo_siguientematriz(int *matriz,int ejex, int ejey)
 {
   int matrizsig [ejex][ejey];
   int i;
   int j;
   int suma;
   for(i=0; i < ejex; i++) {
     for (j=0; j < ejey; j++) {
       suma = mundo_numerovecinos(matriz, i, j, ejex, ejey);
       if(mundo_estadocelula(matriz, i, j, ejex, ejey) == 1) //SI LA CELULA ESTA VIVA
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
       *(matriz + i + ejey*j) = *(matrizsig + i + ejey*j);
   }
 }

void mundo_free(int * matriz)
{
  free(matriz);
}
