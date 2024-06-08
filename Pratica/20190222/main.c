#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaContatti.h"

int main(int argc, char * argv[])
{
    Registro r;
    Lista l;
    nuovaLista(&l);
    FILE *fp;
    
    if (argc!=2)
    {
        printf("errore linea di comando");
        exit(-1);
    }

    if ((fp=fopen(argv[1],"rb"))==NULL)
    {
        printf("errore nell'apertura del file");
        exit(2);
    }
    while (fread(&r,sizeof(Registro),1,fp)==1)
    {
        aggiorna(&l,r);
    }
    fclose(fp);
    stampa(l);
    perseMax(l);
    return 0;
}