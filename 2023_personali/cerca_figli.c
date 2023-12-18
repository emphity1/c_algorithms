
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

//data una altezza, la funzione deve cercare nodi a quel livello che 
// abbiano un figlio solo.

//serve una funzione che va a quel livello
//un'altra che mi verifica se effettivamente i nodi hanno un figlio solo

int altezza(albero a){
    if(a==NULL) return 0;
    int l = altezza(a->left);
    int r = altezza(a->right);

    if (l>r) return l+1;
    return r+1;
}



int cerca_figli(albero a, int v){
    if(a==NULL) return 0;
    if(altezza(a) == v){
        if( (a->left == NULL && a->right !=NULL) || (a->left != NULL && a->right ==NULL)){
            return 1;
        }
    } 

    return cerca_figli(a->left, v) || cerca_figli(a->right,v);      
}


void cerca_nodi_figlio_solo(albero a,int v){
    int ris = cerca_figli(a,v);
    if(ris==1){
        printf("\n\nEsistono nodi a lvl %d con un solo figlio\n",v);
    }else{
        printf("\n\nNon esistono nodi a lvl %d con un solo figlio\n",v);
    }
}