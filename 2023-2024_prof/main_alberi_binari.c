#include <stdlib.h>   // ora ho NULL
#include <stdio.h>    // ora ho printf
#include "albero_b/albero_b.h"
#include "lista_s/lista_s.h"

int main() {

   albero a = NULL;   // creo un albero vuoto
   aggiungi_figlio_b(NULL, &a, 1);  // aggiunta la radice
   aggiungi_figlio_b(a,&(a->left),2); // aggiunto figlio sinistro 
   aggiungi_figlio_b(a,&(a->right),3); // aggiunto figlio destro 

   aggiungi_figlio_b(a->left,&(a->left->left),4); // figlio sx di sx

   //printf("la radice ha due figli? %d\n", two_children(a));
   //printf("il figlio sx della radice ha due figli? %d\n", two_children(a->left));

   a->right->left = aggiungi_figlio_2(a->right,5);
/*
 a ->  1
      / \
     2   3
    /   /
   4   5
*/
   /*
   printf("ho trovato 100 in preordine? %d\n", cerca_albero_b_preordine(a,100) != NULL);
   printf("ho trovato 5 in preordine? %d\n", cerca_albero_b_preordine(a,5) != NULL);

   printf("ho trovato 100 in postordine? %d\n", cerca_albero_b_postordine(a,100) != NULL);
   printf("ho trovato 5 in postordine? %d\n", cerca_albero_b_postordine(a,5) != NULL);

   printf("ho trovato 100 simmetrica? %d\n", cerca_albero_b_simmetrica(a,100) != NULL);
   printf("ho trovato 5 simmetrica? %d\n", cerca_albero_b_simmetrica(a,5) != NULL);

   printf("l'albero ha %d nodi\n", conta_nodi_albero_b(a));

   printf("l'albero a e' un cammino? %d\n", cammino_albero_b(a));
   printf("l'albero radicato su a->left e' un cammino? %d\n", cammino_albero_b(a->left));

   printf("l'altezza dell'albero \"a\" e' %d\n", altezza_albero_b(a));
   printf("l'altezza dell'albero \"a\" e' %d (secondo metodo)\n", altezza_albero_b_2(a));
   printf("l'altezza dell'albero \"a\" e' %d (terzo metodo)\n", altezza_albero_b_3(a));

   printf("la somma del campo info dei nodi dell'albero e' %d\n", somma_albero_b(a));

   printf("la media dei valori dell'albero e' %f\n", media_albero_b(a));
   printf("la media dei valori dell'albero e' %f (secondo metodo)\n", media_albero_b_2(a));
   //printf("la media dei valori dell'albero vuoto e' %f\n", media_albero_b(NULL));

   printf("l'albero \"a\" e' completo? %d\n", completo_albero_b(a));
   printf("l'albero NULL e' completo? %d\n", completo_albero_b(NULL));
   printf("l'albero \"a->left->left\"  e' completo? %d\n", completo_albero_b(a->left->left));

   */
   a->left->right = aggiungi_figlio_2(a->left,6);
   a->right->right = aggiungi_figlio_2(a->right,7);

/*
 a ->   1
       / \
      /   \
     2     3
    / \   / \
   4   6 5   7
*/
   // printf("l'albero \"a\" e' completo? %d\n", completo_albero_b(a));

   //printf("dealloco a\n");
   //dealloca_albero_b(&a);
   //printf("a == NULL? %d\n", a==NULL);
   parentetica_simmetrica(a);
   printf("\n");
   parentetica_preordine(a);
   printf("\n");
   stampa_outline(a);
   printf("\n");

   printf("due_figli_albero_b(a)=%d\n",due_figli_albero_b(a));
   printf("conta_foglie_albero_b(a)=%d\n",conta_foglie_albero_b(a));

   item* l = calcola_lista_da_root_a(a->left->right); 
   print_lista_s(l);

   printf("il grado di parentela di %d e %d e' %d\n", a->left->right->info,
                                                      a->right->info,
                                                      parentela_albero_b(a->left->right,
                                                                         a->right));
   nodo* abr = NULL;
   nodo* f1 = aggiungi_nodo_abr2(&abr, 100);
   nodo* f2 = aggiungi_nodo_abr2(&abr, 200);
   nodo* f3 = aggiungi_nodo_abr2(&abr, 50);
   nodo* f4 = aggiungi_nodo_abr2(&abr, 25);
   nodo* f5 = aggiungi_nodo_abr2(&abr, 300);
   nodo* f6 = aggiungi_nodo_abr2(&abr, 150);

   stampa_outline(abr);
   parentetica_simmetrica(abr);
   printf("\n");

}