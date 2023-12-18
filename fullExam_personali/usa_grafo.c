#include <stdlib.h>
#include <stdio.h>
#include "grafo_matrice.h"
#include "grafo_liste.h"


void main() {

   grafo_matrice gm = new_grafo_matrice(10);

   int i;
   for(i = 0; i < 8; i++) {
      add_directed_edge_matrice(gm,i,i+1);
   }
   for(i = 0; i < 8; i++) {
   	  add_directed_edge_matrice(gm,9,i);
   }

   print_grafo_matrice(gm);

   grafo_liste gl = liste(gm);

   print_grafo_liste(gl);

   printf("grado di uscita di 0 = %d\n",grado_uscita_matrice(gm,0));
   printf("grado di uscita di 9 = %d\n",grado_uscita_matrice(gm,9));

   printf("grado di ingresso di 0 = %d\n",grado_ingresso_matrice(gm,0));
   printf("grado di ingresso di 9 = %d\n",grado_ingresso_matrice(gm,9));
   printf("grado di ingresso di 2 = %d\n",grado_ingresso_matrice(gm,2));

   grafo_matrice gm2 = matrice(gl);

   print_grafo_matrice(gm2);

   printf("arco tra 1 e 2 = %d\n",verifica_arco_liste(gl,1,2));
   printf("arco tra 2 e 2 = %d\n",verifica_arco_liste(gl,2,2));

   printf("verifica_non_orientato_liste(gl)=%d\n",verifica_non_orientato_liste(gl));

   printf("verifica_sorgente_liste(gl,9)=%d\n",verifica_sorgente_liste(gl,9));

   printf("verifica_unione(gl,gl)=%d\n", verifica_unione(gl,gl));

 
   grafo_liste mio_grafo = new_grafo_liste(10); // creo un grafo con 10 nodi
   for( i = 0; i < 9; i++) {
      add_non_directed_edge_liste(mio_grafo, i, i+1);
   }
   add_non_directed_edge_liste(mio_grafo, 2, 6);
   add_non_directed_edge_liste(mio_grafo, 3, 7);
   add_non_directed_edge_liste(mio_grafo, 0, 9);

   print_grafo_liste(mio_grafo);

   int* order = BFS_order(mio_grafo, 0);
   for(i = 0; i < 10; i++) {
      printf("il nodo %d ha numero d'ordine %d\n",i,order[i]);
   }

   int* dist = distanze(mio_grafo, 0);
   for(i = 0; i < 10; i++) {
      printf("il nodo %d ha distanza %d dal nodo 0\n",i,dist[i]);
   }

   int* parent = albero_ricoprente_DFS(mio_grafo, 5);
   for(i = 0; i < 10; i++) {
      printf("il nodo %d ha parent %d \n",i,parent[i]);
   }


   free(order);
   free(dist);
   free(parent);
}



