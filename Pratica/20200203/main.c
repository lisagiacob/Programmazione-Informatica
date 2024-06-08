#include "listaUtenti.h"
#include <stdio.h> //comando FILE
#include <stdlib.h> //comando exit

int main (int argc, char * argv[])
{
    Lista l;
    FILE *fp;
    Iscritto i;
    int a,x;

    if(argc!=3)
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

    while(fread(i.codice,sizeof(i.codice),1,fp)==1)
    {
        insTesta(&l,i.codice);
    }
 
    fclose(fp);
 
    fp=fopen(argv[2],"rt");
    if(fp==NULL)
    {
        printf("Errore nell'apertura del secondo file");
        exit(-3);
    }
 
    Lista * pl;
    pl=&l;
 
    while ((fscanf(fp,"%s %d", i.codice,&a))==2)
    {
        pl=ricerca(&l,i.codice);
        if((*pl)->dato.attività[a-1]!=0) (*pl)->dato.attività[a-1]--;
        else if((*pl)->dato.negati!=3)
        {
            printf("Attività %d: Accesso negato\n",a);
            (*pl)->dato.negati++;
        }
        else printf("Tessera annullata per iscritto:%s\n",(*pl)->dato.codice);
    }
    fclose(fp);
    stampa(&l);
    return 0;
}