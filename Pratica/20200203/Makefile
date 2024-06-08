palestra: main.o listaUtenti.o
	gcc -o palestra main.o listaUtenti.o

listaUtenti.o: listaUtenti.c listaUtenti.h
	gcc -c listaUtenti.c listaUtenti.h

main.o: main.c listaUtenti.h
	gcc -c main.c listaUtenti.h