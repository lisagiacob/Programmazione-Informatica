typedef struct 
{
    char codice[10];
    float ore;
} Orario;

typedef struct nodo
{
    Orario dato;
    struct nodo *next;
} Nodo;

typedef Nodo * Lista;

void nuovaLista(Lista * pl);
void aggiorna(Lista *pl,char c[], int g, float i, float f);
Lista* ricerca(Lista* pl, char c[]);
void insTesta(Lista* pl, Orario o);
void stampa(Lista l);