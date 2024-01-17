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

int dfs(nodo* n, int dfscont) {
    n->color = 1;
    dfscont++;

    elem_arco* ea = n->archi;
    while (ea != NULL) {
        if (ea->info->from->color == 0) {
            dfscont = dfs(ea->info->from, dfscont);
        }
        if (ea->info->to->color == 0) {
            dfscont = dfs(ea->info->to, dfscont);
        }
        ea = ea->next;
    }
    return dfscont;
}



/* Ritorna true se la componente ha esattamentre 3 nodi */

int test(grafo_o* g) {
    
    
    if (g->numero_nodi == 0 || g->numero_nodi == 1) {
        return 0;  // Grafo vuoto o con un solo nodo, considerato connesso
    }

    // Azzera i colori di tutti i nodi
    elem_nodo* en = g->nodi;
    while (en != NULL) {
        en->info->color = 0;
        en = en->next;
    }

    // Esegui la DFS dal primo nodo
    int dfscont = dfs(g->nodi->info, 0);

    // Verifica se tutti i nodi sono stati visitati durante la DFS
    return (dfscont == 3);
}

