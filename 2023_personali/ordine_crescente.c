#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"


/*

Problema: Trova il Massimo in un Albero Binario

Data una struttura di un albero binario, scrivi una funzione che trovi e restituisca il valore massimo presente nell'albero.

*/
       

nodo_albero* aggiungi_figlio_sinistro(nodo_albero* n, int value) {

   n->left = (nodo_albero*)malloc(sizeof(nodo_albero));
   n->left->parent = n;
   n->left->left = NULL;
   n->left->right = NULL;
   n->left->info = value;
   return n->left;
}

nodo_albero* aggiungi_figlio_destro(nodo_albero* n, int value) {

   n->right = (nodo_albero*)malloc(sizeof(nodo_albero));
   n->right->parent = n;
   n->right->left = NULL;
   n->right->right = NULL;
   n->right->info = value;
   return n->right;

}



int profondita(albero a){
    int prof = 0;
    while(a!=NULL){
        prof++;
        a=a->parent;
    }
    return prof;
}


int trova(albero a, int v){
    if(a==NULL) return 0;

    if(a->info == v){
        printf("\nIl valore è stato trovato\n");
        int h = profondita(a);
        printf("\nLa sua profondita' e': %d\n",h-1);
    }

    return trova(a->left,v) || trova(a->right,v);
}


