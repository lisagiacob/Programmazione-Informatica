typedef struct 
{
    char numero[11];
    char esito;
    int durata;
} Registro;

typedef struct 
{
    char numero[11];
    int effettuate, ricevute, perse;
    int m_cons;
} Contatto;


typedef struct nodo
{
    Contatto dato;
    struct nodo * next;
} Nodo;

typedef Nodo * Lista;

void nuovaLista(Lista* pl);
void insTesta(Lista* pl, Contatto c);
Lista* ricerca(Lista* pl, char numero[]);
void aggiorna(Lista *pl, Registro r);
void stampa (Lista l);
void perseMax(Lista l);