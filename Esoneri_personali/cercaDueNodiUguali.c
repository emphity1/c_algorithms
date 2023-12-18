#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"


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




int cercaNodoUguali(albero a, int v){
    
    if(a==NULL) return 0;

    if(a->info == v){
        return 1;
    }else{
       return cercaNodoUguali(a->left,v) || cercaNodoUguali(a->right,v);
    }
}


void stampa(albero a, int v){
    int ris = cercaNodoUguali(a,v);
    if(ris == 1){
        printf("\nCi Sono 2 nodi consecutivi uguali\n");
    }else{
        printf("\n NON ci Sono 2 nodi consecutivi uguali\n");
    }
    
}
