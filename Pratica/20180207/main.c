#include <stdio.h>
#include <stdlib.h>
#include "listaInsegnamenti.h"


int main(int argc, char *argv[])
{
    Lista l;
    FILE *fp;
    char codice[10];
    int giorno;
    float inizio;
    float fine;

    if (argc!=2) 
    {
        printf("errore nella linea di comando");
        exit(-1);
    }

    if((fp=fopen(argv[1],"rt"))==NULL)
    {
        printf("errore nell'apertura del file");
        exit(-2);        
    }

    nuovaLista(&l);

    while((fscanf(fp,"%s %d %f %f",codice,&giorno,&inizio,&fine))==4)
    {
        aggiorna(&l,codice,giorno,inizio,fine);
    }

    fclose(fp);

    stampa(l);

    return 0;   
}