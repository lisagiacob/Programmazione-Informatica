contatti: listaContatti.o main.o
	gcc -g -o contatti listaContatti.o main.o

listaContatti.o: listaContatti.c listaContatti.h
	gcc -g -c listaContatti.c

main.o: main.c listaContatti.h
	gcc -g -c main.c