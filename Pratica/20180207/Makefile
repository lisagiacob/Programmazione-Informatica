orari: listaInsegnamenti.o main.o
	gcc -g -o orari listaInsegnamenti.o main.o

listaInsegnamenti.o: listaInsegnamenti.c listaInsegnamenti.h
	gcc -g -c listaInsegnamenti.c

main.o: main.c listaInsegnamenti.h
	gcc -g -c main.c