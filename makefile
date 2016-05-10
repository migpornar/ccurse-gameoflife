
all: juegovida

juegovida: main.o funciones.o
	gcc main.o funciones.o -o juegovida

main.o: main.c funciones.h
	gcc -c main.c

funciones.o: funciones.c funciones.h
	gcc -c funciones.c
