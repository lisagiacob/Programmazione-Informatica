#include <stdio.h>
#include <stdlib.h>
#include "listaPrenotazioni.h"

int main(int argc, char* argv[])
{
    Lista l,*pl;
    FILE *fp;
    Offerte d;
    Richieste r;
    if(argc!=3)
    {
        printf("Errore nella linea di comando");
        exit(-1);
    }   

    fp=fopen(argv[1],"rb");
    if(fp==NULL)
    {
        printf("Errore nell'apertura del file 1");
        exit(-2);
    }

    nuovaLista(&l);

    while(fread(&d,sizeof(Offerte),1,fp)==1)
    {
        insOrd(&l,d);
    }

    fclose(fp);

    fp=fopen(argv[2],"r");
    if(fp==NULL)
    {
        printf("Errore nell'apertura del file 2");
        exit(-2);
    }

    while((fscanf(fp,"%d %s",&r.id, r.destinazioni))==2)
    {
        pl=ricerca(&l,r.destinazioni);
        if(*pl==NULL) 
            r.esito=rifiutata;
        else if(pl)
        {
            if(((*pl)->Dato.posti)>0) 
                r.esito=accettata;
            else r.esito=rifiutata;
        }
        printf("%d %u\n",r.id,r.esito);
    }

return 0;
}