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


void siguientematriz(int matriz [EJEX][EJEY])
 {
   int matrizsig [EJEX][EJEY];
   int i;
   int j;
   int suma;
   for(i=0; i < EJEX; i++) {
     for (j=0; j < EJEY; j++) {
       //CALCULA LA CANTIDAD DE CELULAS VIVAS ALREDEDOR DE [i][j]
       suma = 0; 
       if (((i-1)>=0) && ((j-1)>=0))
	 suma = matriz[i-1][j-1];
       if ((j-1)>=0)
	 suma = suma + matriz[i][j-1];
       if (((i+1)<EJEX) && ((j-1)>=0))
	 suma = suma + matriz[i+1][j-1];
       if ((i-1)>=0)
	 suma = suma + matriz[i-1][j];
       if ((i+1)<EJEX)
	 suma = suma + matriz[i+1][j];
       if (((i-1)>=0) && ((j+1)<EJEY))
	 suma = suma + matriz[i-1][j+1];
       if ((j+1)<EJEY)
	 suma = suma + matriz[i][j+1];
       if (((i+1)<EJEX) && ((j+1)<EJEY))
	 suma = suma + matriz[i+1][j+1];
	  
       if(matriz[i][j] == 1) //SI LA CELULA ESTA VIVA
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

