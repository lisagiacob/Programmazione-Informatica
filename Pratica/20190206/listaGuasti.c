#include <stdio.h>
#include <stdlib.h>
#include "listaGuasti.h"

void nuovaLista(Lista * pl)
{
    *pl=NULL;
}

void insOrd(Lista* pl, Segnalazione s) {
    pl = ricerca(pl, s);
    insTesta(pl, s);
}

void insTesta(Lista* pl, Segnalazione s) {
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = s;
    aux->next = *pl;
    *pl = aux;
}

Lista* ricerca(Lista* pl, Segnalazione s) {
    while (*pl) {
        if ((*pl)->dato.tempo > s.tempo) break;
        pl = &(*pl)->next;
    }
return pl;
}

void stampa(Lista l,char a) { 
    while (l) {
        if(l->dato.blocco==a) printf("Blocco:%c Stanza:%d Giorni:%d \n", l->dato.blocco, l->dato.stanza, l->dato.tempo);
        l = l->next;
    }
    printf("\n");
}