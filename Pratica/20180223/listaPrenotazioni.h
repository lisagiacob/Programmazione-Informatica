typedef struct 
{
    char destinazioni[30];
    int posti;
} Offerte;

typedef struct 
{
    int id;
    char destinazioni[30];
    enum {
        accettata,
        rifiutata,
    } esito;
} Richieste;

typedef struct nodo
{
    Offerte Dato;
    struct nodo *next;
} Nodo;

typedef Nodo * Lista;

void nuovaLista(Lista* pl);

Lista* ricerca(Lista* pl, char d[]);
void insOrd(Lista* pl, Offerte d);
void insTesta(Lista* pl, Offerte d);