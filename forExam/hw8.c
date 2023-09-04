
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



int conta_nodi(albero a){
    int conta = 0;
    if(a!=NULL) {
        conta = conta_nodi(a->left)+conta_nodi(a->right)+1;
    }
    return conta;
}

int somma_nodi(albero a){
    int somma=0;
    if(a!=NULL){
        somma = a->info + somma_nodi(a->left) + somma_nodi(a->right);
    }
    return somma;
}

void somma_conta_nodi(albero a){
    int numero = conta_nodi(a);
    int somma = somma_nodi(a);
    printf("\nNumero nodi e' %d", numero);
    printf("\nSomma dei nodi e' %d", somma);
}