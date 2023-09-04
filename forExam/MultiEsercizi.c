#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"


/*

Conta quanti nodi di un albero binario hanno 
campo info uguale alla distanza del nodo dalla radice

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


int distanza(albero a,int h){
    if(a==NULL) return 0;
    int count = 0;
    if(a->info == h || a->info == h-1) count ++;

    return count + distanza(a->right,h) + distanza(a->left,h);
}


void verifica(albero a){
    printf("\n Ci sono %d nodi", distanza(a,0));
}








