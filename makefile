
all: juegovida

juegovida: main.o mundo.o
	gcc main.o mundo.o -o juegovida

main.o: main.c mundo.h
	gcc -c main.c

mundo.o: mundo.c mundo.h
	gcc -c mundo.c
