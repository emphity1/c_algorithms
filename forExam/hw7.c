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

//  ---   gcc hw7.c usa_albero_binario.c -o hw7   ---


/* Considera un albero binario T di interi. 
       La funzione albero_altezza_foglie deve ritornare un booleano: 
       1 (true) se l'altezza di T è pari al numero di foglie di T, 
       0 (false) altrimenti. 
       Si ricorda che in un albero binario vuoto l'altezza e' pari 
       a -1 mentre il numero di foglie e' pari a 0; quindi se T e' 
       vuoto allora la funzione albero_altezza_foglie deve ritornare 0. */



int conta_altezza(albero n){
    if(n==NULL) return -1;
    int left = conta_altezza(n->left);
    int right = conta_altezza(n->right);
    if(left>right){
        return left+1;
    }
    return right+1;
}

int conta_foglie(albero n){
    if(n==NULL) return -1;
    if((n->left == NULL) && (n->right==NULL)){
        return 1;
    }
    return conta_foglie(n->left)+conta_foglie(n->right);
}

void stampa(int v){
    printf("\nIl risultato e': %d", v);
}

int albero_altezza_foglie(albero a){
    int verificato = 0;
    if(a==NULL){
        return -1;
    }
    if(conta_altezza(a) <= conta_altezza(a)){
        verificato=1;
    }else{
        verificato = 0;
    }

    stampa(verificato);
    return 0;

}



