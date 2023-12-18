#include <stdlib.h>
#include <stdio.h>
#include "albero_a.h"

nodo_a* aggiungi_figlio_albero_a(nodo_a** pn, int val) {

    nodo_a* new = (nodo_a*)malloc(sizeof(nodo_a));
    new->info = val;
    new->left_child = NULL;
    new->parent = (*pn);
    if( (*pn) == NULL ) {
        new->right_sibling = NULL;
        (*pn) = new;
    } else {
        new->right_sibling = (*pn)->left_child;
        (*pn)->left_child = new;
    }
    return new;
}


int conta_nodi_albero_a(nodo_a* n) {

    if( n == NULL ) return 0;

    int cont = 1;  // conto il nodo corrente
    nodo_a* f = n->left_child;
    while( f != NULL ) {
        cont += conta_nodi_albero_a(f);
        f = f->right_sibling;
    }
    return cont;
}

int conta_nodi_albero_a2(nodo_a* n) {

    if( n == NULL ) return 0;
    return 1 + conta_nodi_albero_a2(n->left_child) + conta_nodi_albero_a2(n->right_sibling);

}

nodo_a* cerca_nodo_albero_a(nodo_a* n, int val) {

    if( n == NULL) return NULL;
    if( n->info == val ) return n;
    
    nodo_a* x = n->left_child;
    while( x != NULL ) {
        nodo_a* result = cerca_nodo_albero_a(x,val);
        if( result != NULL) return result;
        x = x->right_sibling;
    }
    return NULL;
}

nodo_a* cerca_nodo_albero_a2(nodo_a* n, int val) {

    if( n == NULL) return NULL;
    if( n->info == val ) return n;
    nodo_a* l = cerca_nodo_albero_a2(n->left_child,val);
    if ( l != NULL ) return l;
    nodo_a* r = cerca_nodo_albero_a2(n->right_sibling,val);
    return r;
    //  return l || r;  non ha signficato se l ed r sono due puntatori
}


int binario_albero_a(nodo_a* n){

    if( n == NULL ) return 1;
    
    int cont = 0;
    nodo_a* x = n->left_child;
    while( x != NULL && cont < 3) {
        cont++;
        if( !binario_albero_a(x) )
            return 0;
        x = x->right_sibling;
    }
    return cont < 3;
}

int binario_albero_a2(nodo_a* n) {

   if( n == NULL ) return 1;
    

   int cont = 0;
   nodo_a* x = n->left_child;
   while( x != NULL ) {
        cont++;
        x = x->right_sibling;
   }
   if( cont > 2 ) return 0;

   x = n->left_child;
   while( x != NULL ) {
        if( !binario_albero_a(x) )
            return 0;
        x = x->right_sibling;
   }
   return 1;
}

int binario_albero_a3(nodo_a* n) {

   if( n == NULL ) return 1;
   int cont = 0;
   nodo_a* x = n->left_child;
   while( x != NULL && cont < 3 ) {
        cont++;
        x = x->right_sibling;
   }
   return (cont < 3) && 
          binario_albero_a3(n->left_child) && 
          binario_albero_a3(n->right_sibling);
}





void stampa_outline_ricorri_a(nodo_a* n, int prof) {
    if( n == NULL ) return;
    int i;
    for(i = 0; i < prof; i++){
        printf("  ");
    }
    printf("%d\n",n->info);
    nodo_a* x = n->left_child;
    while( x != NULL ) {
       stampa_outline_ricorri_a(x,prof+1);
       x = x->right_sibling;
    }
}

void stampa_outline_a(nodo_a* n) {
    stampa_outline_ricorri_a(n, 0);
}