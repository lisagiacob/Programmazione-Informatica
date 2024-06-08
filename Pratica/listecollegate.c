#include <stdlib.h>

typedef int Dato;
typedef struct nodo { Dato dato;
struct nodo* next;
} Nodo;
typedef Nodo* Lista;

void listaNonOrdinata(Lista* pl, int n);
void listaOrdinata(Lista* pl, int n);
int vuota(Lista l);
int piena(Lista l);
void stampa(Lista l);
int somma(Lista l);
void insTesta(Lista* pl, int numero);
void elimTesta(Lista* pl);
void nuovaLista(Lista* pl);
Lista* ricerca(Lista* pl, int numero);
void insOrd(Lista* pl, int numero);
void insertionSort(Lista* pl1);
void reverse(Lista l1, Lista* pl2);
void insCoda(Lista* pl, int d);
int elim1(Lista* pl, int numero);
void elimTutti(Lista* pl, int d);
int lunghezza(Lista l);
Lista arrayToList(int a[], int dl);
void azzera(Lista l);
void eliminaDuplicati(Lista* pl);

void listaNonOrdinata(Lista* pl, int n) {
  int a[] = {6, 2, 3, 2, 4, 7, 0, 2, 5, 1};
  int i;
  for (i = 0; i < n; i++) {
    (*pl)->dato = a[i];
    // e il cui campo next è NULL (cioè *pl ha un solo elemento; eventualmente
    // ne saranno aggiunti altri nelle iterazioni successive)
    (*pl)->next = NULL;
    // assegna a pl l'indirizzo della sua coda
    pl = &(*pl)->next;
  }
}

void listaOrdinata(Lista* pl, int n) {
  int a[] = {2, 3, 4, 5, 7, 8, 12, 15, 21, 24};
  int i;
  for (i = 0; i < n; i++) {
    (*pl) = (Nodo*)malloc(sizeof(Nodo));
    (*pl)->dato = a[i];
    (*pl)->next = NULL;
    pl = &(*pl)->next;
  }
}

int vuota(Lista l) {
    return l == NULL;
}

int piena(Lista l) { 
    return 0;
}

void stampa(Lista l) { 
    while (l) {
        printf("%d ", l->dato);
        l = l->next;
    }
    printf("\n");
}

int somma(Lista l) { 
    int s = 0;
    while (l) {
        s += l->dato; 
        l = l->next;
    }
    return s;
}

void insTesta(Lista* pl, Dato d) {
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void elimTesta(Lista* pl) { 
    Nodo* aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

void nuovaLista(Lista* pl) {
    *pl = NULL;
}

Lista* ricerca(Lista* pl, Dato d) {
    while (*pl) {
        if ((*pl)->dato == d) break;
        pl = &(*pl)->next;
    }
return pl;
}

void insOrd(Lista* pl, int d) {
    pl = ricerca(pl, d);
    insTesta(pl, d);
}

void insertionSort(Lista* pl1) {
    Lista l2;
    nuovaLista(&l2);
    while (*pl1) {
        insOrd(&l2, (*pl1)->dato);
        elimTesta(pl1);
    }
    *pl1 = l2;
}

void reverse(Lista l1, Lista* pl2) {
  *pl2 = NULL;
  while (l1) {
    insTesta(pl2, l1->dato);
    l1 = l1->next;
  }
}

void insCoda(Lista* pl, int d) {
    pl = ricerca(pl, d);
    insTesta(pl, d);
}

int elim1(Lista* pl, int d) {
    pl = ricerca(pl, d);
    if (*pl) {
        elimTesta(pl);
        return 1;
    }
    else return 0;
}

void elimTutti(Lista* pl, int d) {
    while (*pl) {
        pl = ricerca(pl, d); 
        if (*pl) elimTesta(pl);
    }
}

int lunghezza(Lista l) {
    int n = 0;
    while (l) {
        n++;
        l = l->next;
    }
    return n;
}

Lista arrayToList(int a[], int dl) {
  Lista l = NULL;
  Lista* pl;
  int i;
  for (i = 0; i < dl; i++) {
    // inserisci in coda a l a[i]
    pl = ricerca(&l); //la funzione ricerca qua è lievemente diversa: non dispone del campo d perche la lista l abbiamo già detto che è vuota quindi basta eliminare la linea dell' if
    insTesta(pl, a[i]);
  }
  return l;
}

void azzera(Lista l) {
  while (l) {
    l->dato = 0;
    l = l->next;
  }
}

void elimTesta(Lista* pl) {
  Nodo* aux = *pl;
  *pl = (*pl)->next;
  free(aux);
}

void eliminaDuplicati(Lista* pl) {
  while (*pl && (*pl)->next) {
    elimTutti(&(*pl)->next, (*pl)->dato);
    pl = &(*pl)->next;
  }
}
