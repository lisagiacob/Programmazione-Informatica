#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaPrenotazioni.h"
void nuovaLista(Lista* pl)
{
    *pl=NULL;
}

Lista* ricerca(Lista* pl, char d[]) {
    while (*pl) {
        if (strcmp((*pl)->Dato.destinazioni,d)==0) break;
        pl = &(*pl)->next;
    }
return pl;
}

void insOrd(Lista* pl, Offerte d) {
    pl = ricerca(pl, d.destinazioni);
    if(*pl==NULL) insTesta(pl, d);
    else (*pl)->Dato.posti+=d.posti;
}

void insTesta(Lista* pl, Offerte d) {
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    strcpy(aux->Dato.destinazioni,d.destinazioni);
    aux->Dato.posti=d.posti;
    aux->next = *pl;
    *pl = aux;
}
