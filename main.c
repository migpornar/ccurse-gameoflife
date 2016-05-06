#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"


int main()
{
  int n;
  imprimematriz();
  for(n=0; n < ITERACIONES; n++)
    {
    siguientematriz();
    imprimematriz();
    }
  return 0;
}


