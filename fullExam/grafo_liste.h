#ifndef _GRAFO_LISTE_H
#define _GRAFO_LISTE_H

typedef struct ela {

   struct ela* prev;
   struct ela* next;
   int info;          // id del nodo destinazione dell'arco corrente

} elem_l_adj;

typedef struct gl {

    elem_l_adj** A;  // array delle liste di adiacenza del grafo
    int numero_nodi;

} grafo_struct;

/* Forward declaration di grafo_matrice */

typedef struct gm grafo_m_struct;
typedef grafo_m_struct* grafo_matrice;

typedef grafo_struct* grafo_liste;

grafo_liste new_grafo_liste(int size);

void add_non_directed_edge_liste(grafo_liste g, int u, int v);

void add_directed_edge_liste(grafo_liste g, int u, int v);

void print_grafo_liste(grafo_liste g);

grafo_matrice matrice(grafo_liste g);

int verifica_arco_liste(grafo_liste g, int u, int v);

int verifica_non_orientato_liste(grafo_liste g);

int verifica_pozzo_liste(grafo_liste g, int u);

int verifica_sorgente_liste(grafo_liste g, int u);

int verifica_unione(grafo_liste g1, grafo_liste g2);

int verifica_pozzi_e_sorgenti(grafo_liste g1, grafo_liste g2);

int* BFS_order(grafo_liste g1, int n);

int* distanze(grafo_liste g1, int n);

int* albero_ricoprente_DFS(grafo_liste g1, int n);

void visita_DFS_parent(grafo_liste g1, int n, int* color, int* parent);

#endif