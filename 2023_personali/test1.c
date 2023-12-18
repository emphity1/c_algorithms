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


//algoritmo che calcola la profondità(h) dell'albero
// e cerca se esiste una nodo con campo info pari ad h


int altezza(albero a){
    if(a==NULL) return 0;

    int l = altezza(a->left);
    int r = altezza(a->right);
    if(l>r) return l+1;
    return r+1;

}


int altezza_uguale_nodo(albero a, int h){
    if(a == NULL) return 0;
    if(a->info == h){
        return 1;
    }

    return altezza_uguale_nodo(a->left,h) || altezza_uguale_nodo(a->right,h);
}


void verifica_test1(albero a){
    int h = altezza(a);
    if(altezza_uguale_nodo(a,h) == 1){
        printf("\nC'è un nodo con campo info pari ad h=%d\n", h);
    }else{
        printf("\nNON c'è un nodo con campo info pari ad h=%d\n", h);

    }
}