
#include <stdlib.h>
#include <stdio.h>
#include "albero_binario.h"


/*
Scrivi in linguaggio C il codice della funzione int conta(nodo* a) che accetti in input un
puntatore alla radice di un albero di grado arbitrario di interi. La funzione restituisce il
numero dei nodi dell’albero che hanno un valore del campo info pari al numero dei
discendenti del nodo stesso.

*/
// per compilare:   gcc  usa_albero_binario.c  discendenti_2020_luglio.c -o discendenti
// poi:  ./discendenti

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

int discendenti(albero a){

    if(a==NULL) return 0;
    int disc = 0;
    albero x = a->left;
    while(x!=NULL){
        disc++;
        disc = disc + discendenti(x);
        x = x->right;
    }

    return disc;

}

int conta(albero a){
    if(a==NULL) return 0;
    int count = 0;
    if(discendenti(a) == a->info){
        count++;
    }

    return count + conta(a->left) + conta(a->right);
}


void stampaDisc(albero a){
    int ris = conta(a);
    printf("\nDisc sono: %d", ris);
}