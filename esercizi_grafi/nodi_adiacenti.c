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
   int test(grafo_o* g) che accetta come input un puntatore 
   g ad un grafo realizzato tramite oggetti e riferimenti 
   e ritorna 1 (true) se il grafo contiene due nodi 
   adiacenti che hanno lo stesso valore del campo color. 
   Altrimenti la funzione ritorna 0 (false). Ovviamente 
   se il grafo non ha nodi o ha n solo nodo la funzione 
   ritorna 0 (false). */
   
int verifica_adiacente( grafo_o* g){
    elem_arco* current_edge = g->archi;
    while (current_edge != NULL) {
        // Verifica se i nodi collegati dall'arco hanno lo stesso colore
        if (current_edge->info->from->color == current_edge->info->to->color) {
            return 1;  // Trovati due nodi non adiacenti con lo stesso colore
        }

        current_edge = current_edge->next;
    }
    return 0;
}


int test(grafo_o* g) {
    if(g->numero_nodi <=1) return 0;
    
    elem_nodo* current = g->nodi;
    while(current != NULL && current->next != NULL && verifica_adiacente(g)==1){
        if (current->info->color == current->next->info->color) {
            return 1;  // Trovati due nodi adiacenti con lo stesso colore
        }
        current = current->next;
    }
    return 0;
    


    return 0;


}