#include <stdlib.h>
#include <stdio.h>
#include "grafo_matrice.h"
#include "grafo_liste.h"


grafo_matrice new_grafo_matrice(int size) {

	grafo_matrice output = (grafo_matrice)malloc(sizeof(grafo_m_struct));
	output->numero_nodi = size;
	output->A = (int**)calloc(size, sizeof(int*));
	int i;
	for(i=0; i < size; i++) {
		output->A[i] = (int*)calloc(size, sizeof(int));
	}
    return output;  // non devo inizializzarlo perche' e' gia' pieno di zeri
}

void free_grafo_matrice(grafo_matrice g) {

   int i;
   for( i = 0; i < g->numero_nodi; i++ ) {
   	   free(g->A[i]);
   }
   free(g->A);
   free(g);
}



void add_directed_edge_matrice(grafo_matrice g, int u, int v) {
	g->A[u][v] = 1;
}

void add_non_directed_edge_matrice(grafo_matrice g, int u, int v) {
	g->A[u][v] = 1;
	g->A[v][u] = 1;	
}

grafo_liste liste(grafo_matrice g) {

   grafo_liste gl = new_grafo_liste(g->numero_nodi);
   int i, j;
   for(i = 0; i < g->numero_nodi; i++) {
   	   for(j = 0; j < g->numero_nodi; j++) {
   	   	   if(g->A[i][j] == 1) {
   	   	   	   add_directed_edge_liste(gl,i,j);
   	   	   }
   	   }
   }

   return gl;
}


void print_grafo_matrice(grafo_matrice g) {

   int i, j;
   for( i = 0; i < g->numero_nodi; i++) {
       for( j=0; j < g->numero_nodi; j++) {
       	   printf("%d\t",g->A[i][j]);
       }
       printf("\n");
   }
   printf("\n");
}

int grado_uscita_matrice(grafo_matrice g, int u) {

    int cont = 0;
	int i;
	for(i = 0; i < g->numero_nodi; i++) {
		cont = cont + g->A[u][i];  // se e' zero vuol dire che non c'e' l'arco
	}
	return cont;
}

int grado_ingresso_matrice(grafo_matrice g, int u) {

    int cont = 0;
	int i;
	for(i = 0; i < g->numero_nodi; i++) {
		cont = cont + g->A[i][u];  // se e' zero vuol dire che non c'e' l'arco
	}
	return cont;
}
