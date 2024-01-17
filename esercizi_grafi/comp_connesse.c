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


int test(grafo_o* g) {
      elem_nodo* en=g->nodi;
      while(en!=NULL){
          en->info->color=0;
          en=en->next;
      }
      int contatore=0;
      en=g->nodi;
      while(en!=NULL){
          if(en->info->color==0){
              dfs(en->info);
              contatore++;
          }
          en=en->next;
      }
      return contatore;

}