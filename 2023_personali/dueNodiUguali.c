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


int cercaNodiUguali(albero a) {
    if (a == NULL) return 0;
    int count = 0;

    if ((a->left != NULL && a->info == a->left->info) ||
        (a->right != NULL && a->info == a->right->info)) {
        count++;
    }

    count += cercaNodiUguali(a->left);
    count += cercaNodiUguali(a->right);

    return count;
}



void stampa(albero a){
    int ris = cercaNodiUguali(a);
  
    printf("\n Risultato: %d", ris);
    
}
