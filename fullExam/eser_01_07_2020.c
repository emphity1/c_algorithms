#include <stdlib.h>
#include <stdio.h>


/*
Calcolare profondità albero
Calcolare quanti nodi a quella profondità
Controllare se sono uguali
*/



int nodi_a_prof(nodo_albero*a,int h){
    if(a==NULL) return 0;
    if(h==0) return 1;
    return nodi_a_prof(a->left,h-1) + nodi_a_prof(a->right,h-1);
}
int altezza_albero(nodo_albero*a){
    if(a==NULL) return 0;
    int l = altezza_albero(a->left);
    int r = altezza_albero(a->right);
    if(l>r) return l;
    return r;
}


int verifica(nodo_albero*a){
    if(a==NULL) return 0;
    int h=altezza_albero(a);

    for(int i=0;i<=h;i++){
        if(nodi_a_prof(a,i)==i) return 1;
    }
}