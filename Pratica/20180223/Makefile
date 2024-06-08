prenotazioni: main.o listaPrenotazioni.o
	gcc -g -o prenotazioni main.o listaPrenotazioni.o

listaPrenotazioni.o: listaPrenotazioni.c listaPrenotazioni.h
	gcc -g -c listaPrenotazioni.c

main.o: main.c listaPrenotazioni.h
	gcc -g -c main.c