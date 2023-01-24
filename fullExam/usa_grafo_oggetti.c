#include <stdlib.h>
#include <stdio.h>
#include "grafo_oggetti.h"


void main() {

   grafo* g = new_grafo_oggetti();

   printf("aggiungo il nodo n1\n");
   nodo* n1 = aggiungi_nodo(g);
   printf("aggiungo il nodo n2\n");
   nodo* n2 = aggiungi_nodo(g);
   printf("aggiungo il nodo n3\n");
   nodo* n3 = aggiungi_nodo(g);
   printf("aggiungo il nodo n4\n");
   nodo* n4 = aggiungi_nodo(g);

   printf("aggiungo un arco tra n1 ed n2\n");
   arco* a1 = aggiungi_arco(g,n1,n2);
   printf("aggiungo un arco tra n2 ed n3\n");
   arco* a3 = aggiungi_arco(g,n2,n3);
   printf("aggiungo un arco tra n3 ed n4\n");
   arco* a4 = aggiungi_arco(g,n3,n4);

   // visita_ampiezza(g,n1);

   printf("rimuovo l'arco tra n2 ed n3\n");
   rimuovi_arco(g,a3);

   printf("il grafo e' connesso = %d\n", grafo_oggetti_connesso(g));

   printf("componenti_connesse(g)=%d\n",componenti_connesse(g));
   printf("componenti_uguali(g)=%d\n",componenti_uguali(g));
   printf("componenti_uguali2(g)=%d\n",componenti_uguali2(g));

}