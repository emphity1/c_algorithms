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

int is_foglia(albero a){
    if(a->right==NULL && a->left==NULL){
        return 1;
    }
    return 0;
}

int foglie(albero a){
    if(a==NULL) return 0;
    int count = 0;
    if(is_foglia(a)==1){
        count++;
    }

    return count + foglie(a->left) + foglie(a->right);
}


void ContaFoglie(albero a){

    int num = foglie(a);
    printf("\n Numero di foglie: %d\n\n", num);

}