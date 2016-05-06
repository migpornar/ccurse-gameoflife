
all: juegovida

juegovida: main.o
	gcc main.o -o juegovida

main.o: main.c funciones.c funciones.h
	gcc -c main.c

