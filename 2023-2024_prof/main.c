#include <stdlib.h>   // ora ho NULL
#include <stdio.h>    // ora ho printf
#include "albero_a/albero_a.h"

int main() {

   nodo_a* a = NULL;   // creo un albero vuoto

   aggiungi_figlio_albero_a(&a, 1);  // aggiunge la radice
   nodo_a* n2 = aggiungi_figlio_albero_a(&a, 2);
   nodo_a* n3 = aggiungi_figlio_albero_a(&a, 3);
   int i; 
   for( i = 4; i < 13; i++) {
      aggiungi_figlio_albero_a(&n3, i);
   }
   stampa_outline_a(a);

   printf("conta_nodi_albero_a(a)=%d\n",conta_nodi_albero_a(a));
   printf("conta_nodi_albero_a2(a)=%d\n",conta_nodi_albero_a2(a));
   printf("cerca_nodo_albero_a(a,11)=%p\n", cerca_nodo_albero_a(a,11));
   printf("cerca_nodo_albero_a(a,100)=%p\n", cerca_nodo_albero_a(a,100));
   printf("cerca_nodo_albero_a2(a,11)=%p\n", cerca_nodo_albero_a2(a,11));
   printf("cerca_nodo_albero_a2(a,100)=%p\n", cerca_nodo_albero_a2(a,100));
   printf("binario_albero_a(a)=%d\n", binario_albero_a(a));
   printf("binario_albero_a2(a)=%d\n", binario_albero_a2(a));
   printf("binario_albero_a3(a)=%d\n", binario_albero_a3(a));
}