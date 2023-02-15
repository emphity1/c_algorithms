
#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"


/*



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



//Controlla QUANTI nodi hanno campo info = all'altezza dell'albero
//calcolo altezza dell'albero
int altezza(albero a){ 
    if(a==NULL) return 0;
    
    int l = altezza(a->left);
    int r = altezza(a->right);
    if(l>r) return l+1;
    return r+1;
}

int verifica_nodi(albero a,int h){
    if(a==NULL) return 0;
    int conta = 0;
    if(a->info == h) conta++;

    return conta + verifica_nodi(a->left,h) + verifica_nodi(a->right,h);
}

void stampa_nodi_trovati(albero a){
    int h = altezza(a);
    int tot = verifica_nodi(a,h);
    
    printf("\nAltezza albero e' %d", h);
    printf("\nCi sono %d nodi con altezza %d",tot,h);
}