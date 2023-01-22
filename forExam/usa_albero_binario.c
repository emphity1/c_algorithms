#include <stdlib.h>
#include <stdio.h>
#include "albero_binario.h"

void main() {

   albero mio_albero = NULL;   // creo un albero vuoto

   /*

     5
     `-4 (r)
     | |`-6 (rr)
     | `--7 (rl)
     `-8 (l)
       |`-9 (lr)
       `--10 (ll)
          |
          `-11 (lll) (figlio sinistro di 10)
   */

   // creo la radice 5
   //
   mio_albero = (nodo_albero*)malloc(sizeof(nodo_albero));
   mio_albero->info = 5;
   mio_albero->parent = NULL;
   mio_albero->left = NULL;
   mio_albero->right = NULL; 

   // aggiungo i discendenti
   //
   
   nodo_albero* l = aggiungi_figlio_sinistro(mio_albero,8);
   nodo_albero* r = aggiungi_figlio_destro(mio_albero,4);
   nodo_albero* rl = aggiungi_figlio_sinistro(r,7);
   nodo_albero* rr = aggiungi_figlio_destro(r,6);

   nodo_albero* ll = aggiungi_figlio_sinistro(l,10);
   nodo_albero* lr = aggiungi_figlio_destro(l,9);

   nodo_albero* lll = aggiungi_figlio_sinistro(ll,11);
/*
   printf("ricerca in postordine = %d\n", cerca_postordine(mio_albero,7));
   printf("ricerca in preordine = %d\n", cerca_preordine(mio_albero,7));
*/
   //cammino_abr(mio_albero,11);
   //stampa(mio_albero,11);

  //albero_altezza_foglie(mio_albero);

   somma_conta_nodi(mio_albero);
   
}
