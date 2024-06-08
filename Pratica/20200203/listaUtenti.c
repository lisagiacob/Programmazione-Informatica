#include "listaUtenti.h"
#include <stdio.h> //per comando NULL
#include <stdlib.h> //comando malloc
#include <string.h> //strcmp e strcpy

void nuovaLista(Lista *pl)
{
    *pl=NULL;
}

void insTesta(Lista *pl,char c[])
{
    int x;
    Nodo * aux=(Nodo*)malloc(sizeof(Nodo));
    strcpy(aux->dato.codice,c);
    for(x=0;x<3;x++)
    {
        aux->dato.attività[x]=4;
    }
    aux->next=*pl;
    *pl=aux;
}

Lista* ricerca (Lista *pl,char c[])
{
    while (*pl)
    {
        if (strcmp((*pl)->dato.codice,c)==0) break;    
        pl=&((*pl)->next);
    }
    return pl;
}

void stampa(Lista * pl)
{
    while(*pl)
    {
        printf("%s %d %d %d\n",(*pl)->dato.codice,(*pl)->dato.attività[0],(*pl)->dato.attività[1],(*pl)->dato.attività[2]);
        pl=&(*pl)->next;
    }
    printf("\n");
}