#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"


/*



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


/* Valore massimo di un albero BINARIO e vede se è uguale al numero dei nodi dell'albero*/


int massimo(albero a){
    if(a==NULL) return 0;

    while(a->right != NULL){
        a=a->right;
    }
    int max = a->info;
    printf("\nValore max  dell'albero e': %d\n", max);
    return max;
}


int conta_nodi(albero a){

    if (a == NULL) {
        return 0; // Caso base: l'albero è vuoto, nessun nodo da contare
    }

    int l = conta_nodi(a->left);
    int r = conta_nodi(a->right);

    return 1+l+r;
}


void compara(albero a){
    int tot_nodi = conta_nodi(a);
    int max = massimo(a);
    if(tot_nodi==max){
        printf("\n SUCCESS\n");
    }else{
        printf("\n FAILED \n");
    }
    

    printf("\nValore  tot dei nodi e': %d\n", tot_nodi);
}