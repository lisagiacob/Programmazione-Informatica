#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaContatti.h"

void nuovaLista(Lista* pl) {
    *pl = NULL;
}

void insTesta(Lista *pl, Contatto c)
{
    Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
    aux->dato=c;
    aux->next=*pl;
    *pl=aux;
}

Lista* ricerca(Lista* pl, char numero[]) {
    while(*pl && strcmp((*pl)->dato.numero,numero)!=0)
    {
        pl=&(*pl)->next;
    }
    return pl;
}

void aggiorna(Lista *pl, Registro r)
{
    int cons=0;
    pl=ricerca(pl,r.numero);
    if(*pl==NULL)
    {
        Contatto c;
        strcpy(c.numero, r.numero);
        c.effettuate=0;
        c.ricevute=0;
        c.perse=0;
        insTesta(pl,c);
    }
    switch(r.esito)
    {
        case 'E': 
            (*pl)->dato.effettuate ++;
            cons=0;
            break;
        case 'R':
            (*pl)->dato.ricevute ++;
            cons=0;
            break;
        case 'P':
            (*pl)->dato.perse ++;
            cons++;
            break;
    }
    if (cons>(*pl)->dato.m_cons) (*pl)->dato.m_cons=cons;
}

void stampa (Lista l)
{
    while (l)
    {
        printf("numero:%s effettuate:%d ricevute:%d perse:%d cons:%d\n",l->dato.numero, l->dato.effettuate, l->dato.ricevute, l->dato.perse, l->dato.m_cons);
        l=l->next;
    }
    printf("\n");
}

void perseMax(Lista l)
{
    int pmax=1;
    while (l)
    {
        if(pmax<l->dato.m_cons) pmax=l->dato.m_cons;
        if(l->dato.m_cons==pmax) printf("numero:%s chiamate perse consecutive:%d\n",l->dato.numero,l->dato.m_cons);
        l=l->next;   
    }
}