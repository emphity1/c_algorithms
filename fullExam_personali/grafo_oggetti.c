#include <stdlib.h>   // NULL, malloc
#include <stdio.h>    // printf
#include "grafo_oggetti.h"
#include "coda_di_nodi.h"

grafo* new_grafo_oggetti() {

	grafo* output = (grafo*)malloc(sizeof(grafo));
    
    output->numero_nodi = 0;
    output->numero_archi = 0;
    output->nodi = NULL;
    output->archi = NULL;

    return output;
}

nodo* aggiungi_nodo(grafo* g) {

	nodo* output = (nodo*)malloc(sizeof(nodo));
	output->pos = (elem_nodi*)malloc(sizeof(elem_nodi));
	output->archi = NULL;
    output->color = 0;
	output->pos->info = output;
	output->pos->next = g->nodi;
	output->pos->prev = NULL;   // sono il primo della lista

	if( g->nodi != NULL ) {  // c'era almeno un nodo nella lista nodi del grafo
        g->nodi->prev = output->pos;
	}
 
    g->nodi = output->pos;
    g->numero_nodi++;
    return output; 
}

arco* aggiungi_arco(grafo* g, nodo* from, nodo* to) {

    arco* output = (arco*)malloc(sizeof(arco));
    output->pos = (elem_archi*)malloc(sizeof(elem_archi));
    output->frompos = (elem_archi*)malloc(sizeof(elem_archi));
    output->topos = (elem_archi*)malloc(sizeof(elem_archi));
    
    output->from = from;
    output->to = to;

    output->pos->prev = NULL;  // sara' il primo della lista del grafo
    output->pos->next = g->archi;
    output->pos->info = output;

    output->frompos->prev = NULL;  // sara' il primo della lista del nodo from
    output->frompos->next = from->archi;
    output->frompos->info = output;

    output->topos->prev = NULL;  // sara' il primo della lista del nodo from
    output->topos->next = to->archi;
    output->topos->info = output;
    
    if( g->archi != NULL ) {  // la lista degli archi del grafo non era vuota
        g->archi->prev = output->pos;
    } 

    if( from->archi != NULL ) {  // la lista degli archi del nodo from non era vuota
        from->archi->prev = output->frompos;
    } 

    if( to->archi != NULL ) {  // la lista degli archi del nodo to non era vuota
        to->archi->prev = output->topos;
    } 

    g->archi = output->pos;
    from->archi = output->frompos;
    to->archi = output->topos;

    g->numero_archi++;
    return output;
}

void* rimuovi_elem_nodo(elem_nodi** head, elem_nodi* rem) {

    if( rem->prev != NULL ) {
        rem->prev->next = rem->next;  // mi sono scavalcato nella catena dei next
    } else {
       (*head) = rem->next;
    }
    if( rem->next != NULL ) {
        rem->next->prev = rem->prev;  // mi sono scavalcato nella catena dei prev
    }
    free(rem); 
}



void* rimuovi_nodo(grafo* g, nodo* n) {

    // rimuovo prima tutti gli archi incidenti su n
    //
    elem_archi* ea = n->archi;
    while( ea != NULL ) {
        elem_archi* next = ea->next;
        rimuovi_arco(g, ea->info);  // distruggo anche ea
        ea = next;
    } 

    rimuovi_elem_nodo(&(g->nodi),n->pos);
    free(n);
    g->numero_nodi--;
}


void* rimuovi_elem_arco(elem_archi** head, elem_archi* rem) {

    if( rem->prev != NULL ) {
        rem->prev->next = rem->next;  // mi sono scavalcato nella catena dei next
    } else {
       (*head) = rem->next;
    }
    if( rem->next != NULL ) {
        rem->next->prev = rem->prev;  // mi sono scavalcato nella catena dei prev
    }
    free(rem); 
}


void* rimuovi_arco(grafo*g, arco* a) {

    rimuovi_elem_arco(&(g->archi),a->pos);
    rimuovi_elem_arco(&(a->from->archi),a->frompos);
    rimuovi_elem_arco(&(a->to->archi),a->topos);

    free(a);
    g->numero_archi--;
}


void visita_ampiezza(grafo* g, nodo* n) {

   // coloro tutto il grafo con zero
   //
   elem_nodi* en = g->nodi; 
   while(en != NULL) {
       en->info->color = 0;
       en = en->next;
   }

   coda_nodi q = nuova_coda_di_nodi();

   enqueue_coda_nodi_telescopico(q, n);
   n->color = 1;

   while( !is_coda_nodi_empty(q) ) {
      
      nodo* next = dequeue_coda_nodi(q);
      elem_archi* ea = next->archi;
      while( ea != NULL) {
         
         nodo* altro_nodo = ea->info->from;
         if( altro_nodo == next ) {
            altro_nodo = ea->info->to;
         }
         if( altro_nodo->color == 0) {
            enqueue_coda_nodi_telescopico(q, altro_nodo);
            altro_nodo->color = 1;
         }

         ea = ea->next;
      } // fine while della lista degli archi
   }  // fine dell'estrazione dalla coda
} // fine della funzione


void visita_ampiezza_non_inizializza(grafo* g, nodo* n) {

   coda_nodi q = nuova_coda_di_nodi();

   enqueue_coda_nodi_telescopico(q, n);
   n->color = 1;

   while( !is_coda_nodi_empty(q) ) {
      
      nodo* next = dequeue_coda_nodi(q);
      elem_archi* ea = next->archi;
      while( ea != NULL) {
         
         nodo* altro_nodo = ea->info->from;
         if( altro_nodo == next ) {
            altro_nodo = ea->info->to;
         }
         if( altro_nodo->color == 0) {
            enqueue_coda_nodi_telescopico(q, altro_nodo);
            altro_nodo->color = 1;
         }

         ea = ea->next;
      } // fine while della lista degli archi
   }  // fine dell'estrazione dalla coda
} // fine della funzione

int grafo_oggetti_connesso(grafo* g) {

   if ( g->numero_nodi == 0 ) return 0;  // ipotizzando che un grafo vuoto sia connesso

   visita_ampiezza(g, g->nodi->info);

   elem_nodi* en = g->nodi;
   while( en != NULL ) {
       if ( en->info->color == 0) {
          return 0; // false: ho trovato un nodo non raggiunto
       }
       en = en->next;
   } 
   return 1;
}


int componenti_connesse(grafo* g) {

   int comp = 0;

   // coloro tutto il grafo con zero
   //
   elem_nodi* en = g->nodi; 
   while(en != NULL) {
       en->info->color = 0;
       en = en->next;
   }   

   en = g->nodi;
   while(en != NULL) {
       if (en->info->color == 0) {
           comp++;
           visita_ampiezza_non_inizializza(g,en->info); 
       }
       en = en->next;
   }
   return comp;
}

int nodi_componente(grafo* g, int mark) {

   int cont = 0;
   elem_nodi* ln = g->nodi;
   while( ln != NULL ) {
        if(ln->info->color == mark) {   // trovato un nodo marcato mark
          cont++;
        }
        ln = ln->next;
   }
   return cont;
}


int componenti_uguali(grafo* g) {

     elem_nodi* ln = g->nodi;
     while( ln != NULL ) {
         ln->info->color = 0;   // tolgo tutte le marcature
         ln = ln->next;
     }

     int mark = 0;
     ln = g->nodi;
     while( ln != NULL ) {
        if( ln->info->color == 0 ) {  // trovato un nodo non marcato
            mark++;
            dfs_marcatore(ln->info, mark);
        }
        ln = ln->next;
     } 

     int prima_componente = nodi_componente(g,1);
     int i;
     for( i = 2; i <= mark; i++ ) {
         if( nodi_componente(g,i) != prima_componente) {
             return 0; // ho trovato una componente che ha un numero diverso di nodi
         }
     }
     return 1;  // tutte le componenti hanno la stessa dimensione della prima
}


int componenti_uguali2(grafo* g) {

     elem_nodi* ln = g->nodi;
     while( ln != NULL ) {
         ln->info->color = 0;   // tolgo tutte le marcature
         ln = ln->next;
     }

     int mark = 0;
     ln = g->nodi;
     while( ln != NULL ) {
        if( ln->info->color == 0 ) {  // trovato un nodo non marcato
            mark++;
            dfs_marcatore(ln->info, mark);
        }
        ln = ln->next;
     } 

     int* size_componente = (int*)calloc(mark+1,sizeof(int));
     ln = g->nodi;
     while( ln != NULL ) {
        size_componente[ln->info->color]++;
        ln = ln->next;
     }

     /*
           *-----*
        0  |     |
           *-----*
        1  |  2  |
           *-----*
        2  |  2  |
           *-----*
     */

     /* se avessi voluto contare gli archi

     int* archi_componente = (int*)calloc(mark+1,sizeof(int));
     elem_archi* la = g->archi;
     while( la != NULL ) {
        archi_componente[la->info->from->color]++;
        la = la->next;
     }
     */

     int i;
     for( i = 2; i <= mark; i++ ) {
         if( size_componente[i] != size_componente[1] ) {
             free(size_componente);
             return 0; // ho trovato una componente che ha un numero diverso di nodi
         }
     }
     free(size_componente);
     return 1;  // tutte le componenti hanno la stessa dimensione della prima
}




nodo* altro_nodo(arco* a, nodo* n) {
    if( a->from == n ) return a->to;
    return a->from;
}

void dfs_marcatore(nodo* n, int mark) {
     n->color = mark;
     elem_archi* la = n->archi;
     while( la != NULL ) {
        nodo* altro_nodo = la->info->from;
        if(altro_nodo == n) altro_nodo = la->info->to;
        // equivalentemente nodo* altro_nodo = altro_nodo(la->info, n);
        if( altro_nodo->color == 0) {
             dfs_marcatore(altro_nodo,mark);
        }
        la = la->next;
     }
}