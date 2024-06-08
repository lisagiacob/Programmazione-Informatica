interventi: listaGuasti.o main.o
	gcc -g -o interventi listaGuasti.o main.o

listaGuasti.o: listaGuasti.o listaGuasti.h
	gcc -g -c listaGuasti.c

main: main.c listaGuasti.h
	gcc -g -c main.c