#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char sito[30];
    int anno;
    int mese;
    int giorno;
} cronologia;

typedef struct nodo
{
    cronologia dato;
    struct nodo *next;
} Nodo;

typedef Nodo * Lista;

void nuovaLista(Lista* pl);
void stampa(Lista l);
void inserisci(Lista * pl, cronologia c);
void insTesta(Lista* pl, cronologia c);