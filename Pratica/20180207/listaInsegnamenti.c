#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaInsegnamenti.h"

void nuovaLista(Lista * pl)
{
    *pl=NULL;
}

Lista* ricerca(Lista* pl, char c[]) {
    while (*pl) {
        if (strcmp((*pl)->dato.codice,c)==0) break;
        pl = &(*pl)->next;
    }
return pl;
}

void insTesta(Lista* pl, Orario o) {
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = o;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna(Lista *pl,char c[],int g, float i, float f)
{
    float tp;
    Orario o;
    tp=f-i;
    strcpy(o.codice,c);
    o.ore=tp;
    pl=ricerca(pl,o.codice);
    if(*pl==NULL) insTesta(pl,o);
    else (*pl)->dato.ore+=tp;
}

void stampa(Lista l) { 
    while (l) {
        printf("%s %.1f\n", l->dato.codice, l->dato.ore);
        l = l->next;
    }
    printf("\n");
}