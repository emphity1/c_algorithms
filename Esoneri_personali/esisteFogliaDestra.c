#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"



/* Considera un albero binario T di interi. 
       La funzione somma_e_conta_nodi ritorna un void, ma aggiorna
       gli interi puntati da "somma" e "numero" con la somma dei valori
       dei nodi dell'albero e il numero dei nodi stessi.  */
       

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
    if(a==NULL) return 0;
    if(a->left==NULL && a->right == NULL) return 1;
    return 0;
}
int esiste_foglia(albero a){
    if( a == NULL) return 0;
    if(is_foglia(a->right)) return 1;
    return esiste_foglia(a->left) || esiste_foglia(a->right);
}

void stampa(albero a){
    if(esiste_foglia(a) == 1){
        printf("\nEsiste foglia destra");
    }
}