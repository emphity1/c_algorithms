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



int height(albero a){

    if (a == NULL) {
        return 0;
    }

    
    int l = height(a->left);
    int r = height(a->right);

    if (l>r){
        return l+1;
    }

    return r+1;
    
}


void altezza(albero a){
    int h = height(a);
    printf("\nAltezza dell'albero e': %d\n", h);
    
}





