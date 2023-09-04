#ifndef _GRAFO_OGGETTI_H
#define _GRAFO_OGGETTI_H

typedef struct elem_lista_nodi elem_nodi; // forward declaration
typedef struct elem_lista_archi elem_archi; // forward declaration

typedef struct nodo_struct {

	elem_nodi* pos;
	elem_archi* archi;
	int color;

} nodo;


typedef struct elem_lista_nodi {

	struct elem_lista_nodi* prev;
	struct elem_lista_nodi* next;
	nodo* info;

} elem_nodi;

typedef struct arco_struct {

	elem_archi* pos;
    nodo* from;
    nodo* to;
 	elem_archi* frompos;
	elem_archi* topos;

} arco;


typedef struct elem_lista_archi {

	struct elem_lista_archi* prev;
	struct elem_lista_archi* next;
	arco* info;

} elem_archi;

typedef struct grafo_struct {

   int numero_nodi;
   int numero_archi;
   elem_nodi* nodi;
   elem_archi* archi;

} grafo;


grafo* new_grafo_oggetti();

nodo* aggiungi_nodo(grafo* g);

arco* aggiungi_arco(grafo* g, nodo* from, nodo* to);

void* rimuovi_nodo(grafo* g, nodo* n);

void* rimuovi_arco(grafo* g, arco* a);

void visita_ampiezza(grafo* g, nodo* n);

void visita_ampiezza_non_inizializza(grafo* g, nodo* n);


int grafo_oggetti_connesso(grafo* g);

int componenti_connesse(grafo* g);

int componenti_uguali(grafo* g);
int componenti_uguali2(grafo* g);

void dfs_marcatore(nodo* n, int mark);


#endif