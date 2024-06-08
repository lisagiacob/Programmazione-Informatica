typedef struct
{
    char blocco;
    int stanza;
    int tempo;
} Segnalazione;

typedef struct nodo
{
    Segnalazione dato;
    struct nodo * next;
} Nodo;

typedef Nodo * Lista;

void nuovaLista(Lista * pl);
void insOrd(Lista* pl, Segnalazione s);
void insTesta(Lista* pl, Segnalazione s);
Lista* ricerca(Lista* pl, Segnalazione s);
void stampa(Lista l, char a);