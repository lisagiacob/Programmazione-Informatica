typedef struct 
{
    char codice[17];
    int attività[3];
    int negati;
} Iscritto;

typedef struct nodo
{
    Iscritto dato;
    struct nodo *next;
} Nodo;

typedef Nodo * Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl,char c[]);
Lista* ricerca (Lista *pl,char c[]);
void stampa(Lista * pl);