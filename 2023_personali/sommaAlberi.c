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



/*

Fa la somma dei campi info di tutti i nodi

*/





int somma_alberi(albero a){
    if(a==NULL) return 0;

    int sum=0;

    int r = somma_alberi(a->right);
    int l = somma_alberi(a->right);

    return a->info + r + l;
}


void somma(albero a){
    int somma = somma_alberi(a);
    printf("\nSomma e': %d\n", somma);
}