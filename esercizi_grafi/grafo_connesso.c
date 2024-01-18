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



/* Funzione di visita in profondità ricorsiva */
void dfs(nodo* n){
    n->color=1;
    elem_arco* ea=n->archi;
    while(ea!=NULL){
        if(ea->info->from->color==0){
            dfs(ea->info->from);
        }
        if(ea->info->to->color==0){
            dfs(ea->info->to);
        }
        ea=ea->next;
    }
}


/* Funzione principale per verificare se il grafo è connesso */
int test(grafo_o* g) {
    if (g->numero_nodi <= 1) {
        return 1;  // Se il grafo non ha nodi o ha un solo nodo, ritorna true (grafo connesso)
    }

    // Inizializza tutti i nodi con il colore 0 (non visitato)
    elem_nodo* current_node = g->nodi;
    while (current_node != NULL) {
        current_node->info->color = 0;
        current_node = current_node->next;
    }

    // Imposta il colore del primo nodo a visitato
    g->nodi->info->color = 1;

    // Esegue la DFS partendo dal primo nodo
    dfs(g->nodi->info);

    // Verifica se tutti i nodi sono stati visitati
    current_node = g->nodi;
    while (current_node != NULL) {
        if (current_node->info->color == 0) {
            return 0;  // Se c'è almeno un nodo non visitato, il grafo non è connesso
        }
        current_node = current_node->next;
    }

    return 1;  // Tutti i nodi sono stati visitati, il grafo è connesso
}