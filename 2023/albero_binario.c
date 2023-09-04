#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"

/* 
   Assumo che il nodo corrente sia diverso da NULL.
   Assumo che il figlio sinistro del nodo corrente sia NULL 
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

int cerca_preordine(albero a, int v) {

	if( a == NULL) return 0; // false
	printf("sto controllando il nodo che ha il valore %d\n",a->info);
	if( a->info == v) return 1; // true
    return cerca_preordine(a->left,v) || cerca_preordine(a->right,v);
}

int cerca_postordine(albero a, int v) {

	if( a == NULL) return 0; // false

	int l = cerca_postordine(a->left,v);
	int r = cerca_postordine(a->right,v);
	if( l != r ) return 1;  // l'ho trovato nei sottoalberi 

	printf("sto controllando il nodo che ha il valore %d\n",a->info);
	if( a->info == v) return 1; // true
    else return 0;  // false, non l'ho trovato in questo sottoalbero
}

/* 
albero conta_nodi(albero a){

   if(a==NULL) return 0;

   int l = conta_nodi(a->left);
   int r = conta_nodi(a->right);

   return l+r+1;
}

*/
/*
albero lunghezza_cammino(albero a, int v){
   if(a==NULL) return 0;
   if(a->info==v) return 1;

   albero l = lunghezza_cammino(a->left, v);
   if(l!=0){
      return l+1;
   }
   albero r = lunghezza_cammino(a->right,v);
   if(r!=0){
      return r+1;
   }
   return 0;
}

albero conta_percorso(albero a, int v){
   int lun = lunghezza_cammino(a,v);

}
*/
int cerca_nodi(albero root, int target) {
    if (root == NULL)
        return 0;
    if (root->info == target)
        return 1;
    int leftCount = cerca_nodi(root->left, target);
    if (leftCount != 0)
        return leftCount + 1;
    int rightCount = cerca_nodi(root->right, target);
    if (rightCount != 0)
        return rightCount + 1;
    return 0;
}

//contare i nodi che hanno figli foglie


int conta_figli_foglie(albero a){

   int count = 0;
   
   if(a==NULL) return 0;

   count = (a->left==NULL) && (a->right ==NULL);
   count += conta_figli_foglie(a->left);
   count += conta_figli_foglie(a->right);

   return count;
}

void stampa_figli(albero a){
   if(conta_figli_foglie(a) > 0){
      printf("\nNumero di figli foglie e'  %d", conta_figli_foglie(a));
   }else{
      printf("\nNon ci sono figli foglie\n");
   }
}

//contate quanti nodi di un albero binario hanno campo info
// uguale alla distanza del nodo   dalla radice