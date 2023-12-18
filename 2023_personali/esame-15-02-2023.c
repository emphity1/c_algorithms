

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









/* Scrivi il codice in linguaggio C della funzione
info_altezza() che prende in input un albero
binario T di interi e ritorna 1 (true) se tutti i
nodi dell'albero hanno come valore l'altezza
dell'albero stesso (la distanza della foglia piu'
profonda dalla radice), altrimenti ritorna 0 (false).
Se l'albero e' vuoto info_altezza() ritorna 1 (true). */

int altezza(albero a){
    if(a==NULL) return 0;
    int l = altezza(a->left);
    int r = altezza(a->right);

    if(l>r) return l+1;
    return r+1;
}

int verifica(albero a, int h){
    if (a==NULL) return 0;
    if(a->info == h){
        return 1;
    }

    return verifica(a->left,h) && verifica(a->right,h);
}

void info_altezza(albero a){

    int h=altezza(a);

    if(a->info == h && verifica(a,h)==1 ){
        printf("\n tutti i nodi dell'albero hanno come valore %d\n",h);
    }else{
        printf("\n non tutti i nodi dell'albero hanno come valore %d\n",h);
    }

}