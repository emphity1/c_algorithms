#include <stdlib.h>
#include <stdio.h>
#include "grafo_liste.h"
#include "grafo_matrice.h"
#include "coda_di_interi.h"


grafo_liste new_grafo_liste(int size) {

     grafo_liste output = (grafo_liste)malloc(sizeof(grafo_struct));
     output->numero_nodi = size;
     output->A = (elem_l_adj**)calloc(size,sizeof(elem_l_adj*));
     return output;
}

// Assumo, senza controllarlo, che l'arco non ci sia gia'
//
void add_non_directed_edge_liste(grafo_liste g, int u, int v) {

   elem_l_adj* e1 = (elem_l_adj*)malloc(sizeof(elem_l_adj));
   elem_l_adj* e2 = (elem_l_adj*)malloc(sizeof(elem_l_adj));

   e1->prev = NULL;
   e2->prev = NULL;
   e1->info = v;     // da mettere nella lista di u
   e2->info = u;     // da mettere nella lista di v
   e1->next = g->A[u];
   e2->next = g->A[v];
   if( g->A[u] != NULL) {   // se c'era un elemento nella lista di u
   	  g->A[u]->prev = e1;
   }
   if( g->A[v] != NULL) {   // se c'era un elemento nella lista di v
   	  g->A[v]->prev = e2;
   }
   g->A[u] = e1;  // aggiunto e1 in testa alla lista di u
   g->A[v] = e2;  // aggiunto e2 in testa alla lista di v
}

// Assumo, senza controllarlo, che l'arco non ci sia gia'
//
void add_directed_edge_liste(grafo_liste g, int u, int v) {

   elem_l_adj* e1 = (elem_l_adj*)malloc(sizeof(elem_l_adj));
   e1->prev = NULL;
   e1->info = v;     // da mettere nella lista di u
   e1->next = g->A[u];
   if( g->A[u] != NULL) {   // se c'era un elemento nella lista di u
   	  g->A[u]->prev = e1;
   }
   g->A[u] = e1;  // aggiunto e1 in testa alla lista di u
}

void print_grafo_liste(grafo_liste g) {

   int i; 
   for( i = 0; i < g->numero_nodi; i++) {
      printf("[%d]",i);
      elem_l_adj* e = g->A[i];
      while ( e != NULL) {
         printf("->(%d)",e->info);
         e = e->next;  
      }
      printf("\n");
   }
   printf("\n");
}

grafo_matrice matrice(grafo_liste g) {

    grafo_matrice gm = new_grafo_matrice(g->numero_nodi);

    int i;
    for( i = 0; i < g->numero_nodi; i++) {
       elem_l_adj* e = g->A[i];
       while( e != NULL) {
           gm->A[i][e->info] = 1;
           e = e->next;
       }
    }
    return gm;
}

int verifica_arco_liste(grafo_liste g, int u, int v) {

   elem_l_adj* e = g->A[u];
   while ( e != NULL ) {
      if( e->info == v )
          return 1; // true
      e = e->next;
   }
   return 0; // cioe' false
}

int verifica_non_orientato_liste(grafo_liste g) {

   int i;
   for( i = 0; i < g->numero_nodi; i++) {
     elem_l_adj* e = g->A[i];
     while ( e != NULL ) {
        if( !verifica_arco_liste(g,e->info,i) )
            return 0; // false perche' ho trovato l'arco (i,e->info) ma non 
                      // c'e' l'arco (e->info,i)
        e = e->next;
     }
   }
   return 1; // true: tutti gli archi diretti hanno un opposto.
}

int verifica_pozzo_liste(grafo_liste g, int u) {
    return g->A[u] == NULL;
}

int verifica_sorgente_liste(grafo_liste g, int u) {

   int i;
   for( i = 0; i < g->numero_nodi; i++) {
     elem_l_adj* e = g->A[i];
     while ( e != NULL ) {
        if( e->info == u )
            return 0; // false perche' ho trovato un arco entrante
        e = e->next;
     }
   }
   return 1; // true: non ho nessun arco entrante
}

int verifica_unione(grafo_liste g1, grafo_liste g2) {

   if( g1->numero_nodi != g2->numero_nodi) return 0;

   grafo_matrice g1m = matrice(g1);
   grafo_matrice g2m = matrice(g2);
   int i, j;
   for( i = 0; i < g1->numero_nodi; i++) {
      for( j = 0; j < g1->numero_nodi; j++) {
          if( g1m->A[i][j] == 0 && g2m->A[i][j] == 0) {
              free_grafo_matrice(g1m);
              free_grafo_matrice(g2m);
              return 0; // l'unione dei grafi manca di un arco
          }
      }
   }
   // devo deallocare i grafi matrice
   free_grafo_matrice(g1m);
   free_grafo_matrice(g2m);
   return 1;  // se sei qui tutti gli archi sono in g1 o g2
}

int verifica_pozzi_e_sorgenti(grafo_liste g1, grafo_liste g2){

   if(g1->numero_nodi != g2->numero_nodi) return 0;

   int* pozzi_g1 = (int*)calloc(g1->numero_nodi,sizeof(int));
   int* pozzi_g2 = (int*)calloc(g2->numero_nodi,sizeof(int));
   int* sorgenti_g1 = (int*)calloc(g1->numero_nodi,sizeof(int));
   int* sorgenti_g2 = (int*)calloc(g2->numero_nodi,sizeof(int));

  int i;
  for( i = 0; i < g1->numero_nodi; i++) {
      pozzi_g1[i] = 1;
      pozzi_g2[i] = 1;
      sorgenti_g1[i] = 1;
      sorgenti_g2[i] = 1;
  }
  for( i = 0; i < g1->numero_nodi; i++) {
     elem_l_adj* e = g1->A[i];
     while ( e != NULL ) {
        pozzi_g1[i] = 0;          // ha un arco uscente
        sorgenti_g1[e->info] = 0; // ha un arco entrante
        e = e->next;
     }
   }
  for( i = 0; i < g2->numero_nodi; i++) {
     elem_l_adj* e = g2->A[i];
     while ( e != NULL ) {
        pozzi_g2[i] = 0;          // ha un arco uscente
        sorgenti_g2[e->info] = 0; // ha un arco entrante
        e = e->next;
     }
   }
  for( i = 0; i < g2->numero_nodi; i++) {
     if( (pozzi_g1[i] && !sorgenti_g2[i]) ||
         (sorgenti_g1[i] && !pozzi_g2[i]) ) {
          free(pozzi_g1);
          free(pozzi_g2);
          free(sorgenti_g1);
          free(sorgenti_g2);
          return 0;
     }
  }
  free(pozzi_g1);
  free(pozzi_g2);
  free(sorgenti_g1);
  free(sorgenti_g2);
  return 1;
}

int* BFS_order(grafo_liste g, int n) {

   int* color = (int*)calloc(g->numero_nodi,sizeof(int));
   int* output = (int*)calloc(g->numero_nodi,sizeof(int));
   int ordine = 0;

   coda_interi mia_coda = nuova_coda_di_interi();

   color[n] = 1;
   enqueue_coda_interi(mia_coda, n);

   while( mia_coda->head != mia_coda->tail ) {
      
      int estratto = dequeue_coda_interi(mia_coda);
      output[estratto] = ordine;
      ordine++;
       
      elem_l_adj* el = g->A[estratto];
      while( el != NULL) {

          int vicino = el->info;
          if( color[vicino] == 0) {
             color[vicino] = 1;
             enqueue_coda_interi_telescopico(mia_coda, vicino);
          }
          el = el->next;
      }
   }
   return output;
}

int* distanze(grafo_liste g, int n) {

   int* color = (int*)calloc(g->numero_nodi,sizeof(int));
   int* output = (int*)calloc(g->numero_nodi,sizeof(int));
   int i;
   for(i = 0; i < g->numero_nodi; i++) {
       output[i] = -1;   // inizializzo le distanza come se i nodi fossero 
                         // tutti non raggiungibili
   }

   coda_interi mia_coda = nuova_coda_di_interi();

   color[n] = 1;
   output[n] = 0;   // il nodo n e' a distanza zero da se stesso
   enqueue_coda_interi(mia_coda, n);

   while( mia_coda->head != mia_coda->tail ) {
      
      int estratto = dequeue_coda_interi(mia_coda);
       
      elem_l_adj* el = g->A[estratto];
      while( el != NULL) {

          int vicino = el->info;
          if( color[vicino] == 0) {
             color[vicino] = 1;
             output[vicino] = output[estratto]+1;
             enqueue_coda_interi_telescopico(mia_coda, vicino);
          }
          el = el->next;
      }
   }
   free(color);
   return output;
}

int* albero_ricoprente_DFS(grafo_liste g1, int n) {

   int* color = (int*)calloc(g1->numero_nodi,sizeof(int));
   int* parent = (int*)calloc(g1->numero_nodi,sizeof(int));
   int i;
   for(i = 0; i < g1->numero_nodi; i++) {
       parent[i] = -1;   // inizializzo per ogni nodo il nodo di provenienza 
                         // nella visita DFS
   }
   
   visita_DFS_parent(g1,n,color,parent);

   free(color);
   return parent;
}

void visita_DFS_parent(grafo_liste g1, int n, int* color, int* parent) {

   color[n] = 1;
   elem_l_adj* el = g1->A[n];
   while( el != NULL) {
      if( color[el->info] == 0 ) { // ho trovato un nuovo nodo
          parent[el->info] = n;
          visita_DFS_parent(g1, el->info, color, parent);
      }
      el = el->next;
   }
}