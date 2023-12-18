#ifndef _ALBERO_B_H
#define _ALBERO_B_H

#include "../lista_s/lista_s.h"


typedef struct nodo {

   struct nodo* parent;
   struct nodo* left;
   struct nodo* right;
   int info;

} nodo;

typedef nodo* albero;  // faccciamo coincidere l'albero 
                       // con il puntatore alla radice

/*
typedef struct albero {

	nodo* root;

} albero;
*/

int is_albero_b_empty(albero a);
//int is_albero_b_empty(nodo* n);

int two_children(nodo* n);

/* aggiungi all'abr il valore della chiave val */

nodo* aggiungi_nodo_abr(nodo** ppn, int val);
nodo* aggiungi_nodo_abr2(nodo** ppn, int val);


/* pn è un puntatore ad una zona di memoria
   dove ci deve essere il puntatore al nuovo
   nodo creato. Il valore val e' l'intero da 
   mettere dentro il figlio. */ 

void aggiungi_figlio_b(nodo* parent, nodo** pn, int val);

nodo* aggiungi_figlio_2(nodo* parent, int val);

nodo* cerca_albero_b_preordine(nodo* n, int val);
nodo* cerca_albero_b_postordine(nodo* n, int val);
nodo* cerca_albero_b_simmetrica(nodo* n, int val);

int conta_nodi_albero_b(nodo* n);

int cammino_albero_b(nodo* n);

int altezza_albero_b(nodo* n);
int altezza_albero_b_2(nodo* n);
int altezza_albero_b_3(nodo* n);

int somma_albero_b(nodo* n);

float media_albero_b(nodo* n);
float media_albero_b_2(nodo* n);

int completo_albero_b(nodo* n);

void dealloca_albero_b(nodo** n);

void parentetica_simmetrica(nodo* n);
void parentetica_preordine(nodo* n);
void stampa_outline(nodo* n);

int due_figli_albero_b(nodo* n);
int conta_foglie_albero_b(nodo* n);

item* calcola_lista_da_root_a(nodo* n);

int parentela_albero_b(nodo* n1, nodo* n2);

#endif
