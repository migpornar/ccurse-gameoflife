#ifndef MUNDO_h
#define MUNDO_h
#include <stdio.h>
#include <stdlib.h>
#include "mundo.h"
#include <time.h>
#include <string.h>
#include <stdbool.h>

struct mundo {
    int filas;
    int columnas;
    int* matriz;
    int* matrizsig;
};

enum atributos_mundo{
    NUM_FIL,
    NUM_COL,
    MATRIZ,
    MATRIZ_SIG,
};

struct mundo* mundo_inicializar(int ejex,int ejey);

int* matriz_alloc(int fila,int columna);

int* array_alloc(int vect);

void mundo_siguientematriz(int *matriz, int ejex, int ejey);

void mundo_imprimematriz(int *matriz, int ejex, int ejey);

int arreglaindicesi(int i, int ejex);

int arreglaindicesj(int j, int ejey);

int cerounoaleatorio();

int mundo_numerovecinos(int *matriz, int i, int j,int ejex, int ejey);

int arreglaindicesi(int i, int ejex);

int arreglaindicesj(int j, int ejey);

int mundo_estadocelula(int *matriz,int i, int j, int ejex, int ejey);

void mundo_free(int * matriz);

#endif
