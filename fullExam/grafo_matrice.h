#ifndef _GRAFO_MATRICE_H
#define _GRAFO_MATRICE_H

typedef struct gm {

   int** A;
   int numero_nodi;

} grafo_m_struct;

typedef grafo_m_struct* grafo_matrice;

/* forward declaration del tipo grafo_liste */

typedef struct gl grafo_struct;
typedef grafo_struct* grafo_liste;


grafo_matrice new_grafo_matrice(int size);

void free_grafo_matrice(grafo_matrice g);

void add_non_directed_edge_matrice(grafo_matrice g, int u, int v);

void add_directed_edge_matrice(grafo_matrice g, int u, int v);

grafo_liste liste(grafo_matrice g);

void print_grafo_matrice(grafo_matrice g);

int grado_uscita_matrice(grafo_matrice g, int u);

int grado_ingresso_matrice(grafo_matrice g, int u);

#endif