#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"


/*

Algoritmo calcola 2 cose:

- foglie
- nodi con un solo figlio

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

int is_foglia(albero a){
    if(a->left==NULL && a->right==NULL) return 1;
    return 0;
}

int nodo_figlio_solo(albero a){
    if((a->left==NULL && a->right!=NULL) || (a->left!=NULL && a->right==NULL)) return 1;
}

int conta_nodi_figlio_solo(albero a){
    if(a==NULL) return 0;
    int count=0;

    if(nodo_figlio_solo(a)==1){
        count++;
    }
    return count + conta_nodi_figlio_solo(a->left) + conta_nodi_figlio_solo(a->right);

}

int conta_foglie(albero a){

    if(a==NULL) return 0;
    int count=0;

    if(is_foglia(a)==1){
        count++;
    }
    return count + conta_foglie(a->left) + conta_foglie(a->right);
}

void stampa_foglie(albero a){
    int c = conta_foglie(a);
    int d = conta_nodi_figlio_solo(a);
    printf("\nCi sono  %d foglie\n", c);
    printf("\nCi sono %d nodi con un figlio solo\n",d);
}