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



int altezza(albero a){
    if(a==NULL) return 0;
    int l = altezza(a->left);
    int r = altezza(a->right);

    if (l>r) return l+1;
    return r+1;
}

void verifica_profondita(albero a, int v){
    int h = altezza(a);
    if(h==v){
        printf("\nL'albero è alto %d\n\n",v);
    }else{
        printf("\nAltezza albero è diversa da %d\n\n",v);
    }
}