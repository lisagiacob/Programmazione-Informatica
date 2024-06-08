#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaVisite.h"

void nuovaLista(Lista* pl) {
    *pl = NULL;
}

void insTesta(Lista* pl, cronologia c) {
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = c;
    aux->next = *pl;
    *pl = aux;
}

void inserisci(Lista * pl, cronologia c)
{
    int data;
    data=(c.anno*10000)+(c.mese*100)+c.anno;
    while(*pl)
    {
        int datal=((*pl)->dato.anno*10000)+((*pl)->dato.mese*100)+(*pl)->dato.giorno;
        if (strcmp((*pl)->dato.sito,c.sito)==0)
        {
            if(datal>data) insTesta(pl,c);
            else if (datal<data && strcmp((*pl)->next->dato.sito, c.sito)!=0)
            {
                pl=&(*pl)->next;
                insTesta(pl,c);
            }
            else if (datal<data && strcmp((*pl)->next->dato.sito, c.sito)==0) break;
        }
        pl=&(*pl)->next;
    }
}

void stampa(Lista l) { 
    while (l) {
        printf("%s %d/%d/%d", l->dato.sito,l->dato.giorno,l->dato.mese,l->dato.anno);
        l = l->next;
    }
    printf("\n");
}