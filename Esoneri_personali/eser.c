
#include <stdlib.h>
#include <stdio.h>
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


/*
Esercizio inventato:

quanti nodi hanno solo 1 figlio

*/

int contaNodi_figlioSolo(albero a){
    if(a==NULL) return 0;
    int c = 0;
    if(a->left==NULL || a->right==NULL){
        c++;
    }
    return c + contaNodi_figlioSolo(a->left) + contaNodi_figlioSolo(a->right);

}

int conta_foglie(albero a){
    if(a==NULL) return 0;
    int c = 0;
    if(a->left==NULL && a->right==NULL){
        c++;
    }
    return c + conta_foglie(a->left) + conta_foglie(a->right);

}

void stampaNodi_figlioSolo(albero a){
    int ris1 = contaNodi_figlioSolo(a);
    int ris2 = conta_foglie(a);
    printf("\nCi sono  %d nodi con un solo figlio\n", ris1);
    printf("\nCi sono  %d foglie\n", ris2);
}

