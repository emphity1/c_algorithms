#include <stdlib.h>

/* NON MODIFICARE LE STRUTTURE QUI SOTTO */

typedef struct struct_nodo nodo;  // forward declaration
typedef struct struct_arco arco;  // forward declaration

typedef struct struct_elem_arco {  // elemento di una lista di archi
   struct struct_elem_arco* prev;
   struct struct_elem_arco* next;
   arco* info;

} elem_arco;

typedef struct struct_elem_nodo {  // elemento di una lista di nodi
   struct struct_elem_nodo* prev;
   struct struct_elem_nodo* next;
   nodo* info;
} elem_nodo;

typedef struct struct_nodo {  // struttura corrispondente ad un nodo
   int color;
   elem_arco* archi;  // lista di archi incidenti sul nodo
   elem_nodo* pos;    // posizione nella lista di nodi del grafo
} nodo;

typedef struct struct_arco {  // struttura corrispondente ad un arco
   nodo* from;
   nodo* to;
   elem_arco* pos;     // posizione nella lista del grafo
   elem_arco* frompos; // posizione nella lista del nodo from 
   elem_arco* topos;   // posizione nella lista del nodo to
} arco;

typedef struct struct_grafo {  // struttura corrispondente ad un grafo
   int numero_nodi;
   int numero_archi;
   elem_nodo* nodi;
   elem_arco* archi;
} grafo_o;

/* NON MODIFICARE LE STRUTTURE QUI SOPRA */

/* puoi scrivere qui eventuali funzioni di appoggio */





/* Scrivi il codice in linguaggio C della funzione 
   int test(grafo_o* g) che accetta come input un 
   puntatore g ad un grafo realizzato tramite oggetti 
   e riferimenti e ritorna 1 (true) se il grafo 
   contiene un nodo che ha esattamente tre archi incidenti. 
   Altrimenti la funzione ritorna 0 (false). Assumi 
   che il grafo passato alla funzione non sia mai NULL. */

int test(grafo_o* g) {
    if (g->numero_nodi == 0) {
        return 0;  // Se il grafo non ha nodi, ritorna false
    }

    elem_nodo* current_node = g->nodi;

    while (current_node != NULL) {
        int count_edges = 0;  // Contatore per il numero di archi incidenti

        // Itera attraverso la lista di archi incidenti sul nodo corrente
        elem_arco* current_edge = current_node->info->archi;
        while (current_edge != NULL) {
            count_edges++;
            current_edge = current_edge->next;
        }

        // Se il nodo ha esattamente tre archi incidenti, ritorna true
        if (count_edges == 3) {
            return 1;  // true
        }

        current_node = current_node->next;
    }

    return 0;  // Nessun nodo con esattamente tre archi incidenti, ritorna false
}
