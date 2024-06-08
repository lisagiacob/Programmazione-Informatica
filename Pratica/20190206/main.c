#include <stdio.h>
#include <stdlib.h>
#include "listaGuasti.h"

int main(int argc, char * argv[])
{
    Lista l;
    Segnalazione s;
    char a;
    FILE * fp;
    if(argc!=2)
    {
        printf ("errore nella linea di comando");
        exit(1);
    }
    if((fp=fopen(argv[1],"rb"))==NULL)
    {
        printf("eroore nell'apertura del file");
        exit(2);
    }
    nuovaLista(&l);
    while(fread(&s,sizeof(Segnalazione), 1, fp)==1)
    {
        insOrd(&l, s);
    }
    printf("Che blocco?");
    scanf("%c",&a);
    stampa(l,a);
    return 0;
}
