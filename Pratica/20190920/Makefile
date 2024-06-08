cronologia: main.o listaVisite.o
	gcc -o cronologia main.o listaVisite.o

listaVisite.o: listaVisite.c listaVisite.h
	gcc -c listaVisite.c listaVisite.h

main.o: main.c listaVisite.h
	gcc -c main.c listaVisite.h