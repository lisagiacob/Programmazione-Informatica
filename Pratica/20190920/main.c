#include <stdio.h>
#include <stdlib.h>
#include "listaVisite.h"

int main (int argc, char *argv[])
{
    FILE* fp;
    cronologia c;
    Lista l;
    if(argc!=2)
    {
        printf("Errore nella linea di comando");
        exit(-1);
    }
    fp=fopen(argv[1],"rb");
    if(fp==NULL)
    {
        printf("Errore nell'apertura del file");
        exit(-2);
    }
    nuovaLista(&l);
    while(fread(&c,sizeof(cronologia),1,fp)==1)
    {
        inserisci(&l,c);
        printf("1");
    }
    stampa(l);

    return 0;
}