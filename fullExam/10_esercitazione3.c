#include <stdlib.h>
#include <stdio.h>



/*
che accetti in input un intero h, un puntatore a alla radice di un albero binario di interi e un puntatore g ad
grafo non orientato rappresentato tramite oggetti e riferimenti. La funzione restituisce 1 se il numero di
nodi dell’albero a che sono radici di un sottoalbero di profondità h sono tanti quanti sono i nodi della
componente più piccola del grafo g, altrimenti la funzione restituisce 0.

*/


int verifica(int a,nodo_albero* a,grafo* g){
    if(a==NULL && g==NULL) return 1;
    if(a==NULL || g==NULL) return 0;

    return nodi_radici(a,h) == comp_piu_piccola(g);
}

int prof_albero(nodo_albero* a){
    if(a==NULL) return 0;
    int l = prof_albero(a->left);
    int r = prof_alber(a->right);
    if(l>r) return l;
    return r;
}

int num_sottoalberi(nodo_albero* a, int h){
    if(a==NULL) return -1;
    int ris = num_sottoalberi(a->left,h) + num_sottoalberi(a->right,h);
    if(prof_albero(a) == h){
        ris++;
    }
    return ris;
}


//visita in profondità
int DFS(nodo* n){
    n->color = 1;
    int out = 1;
    elem_archi* ea = n->archi;
    while(ea!=NUL){
        nodo* nuovoNodo =
    }
}

int dim_comp_min(grafo* g){
    elem_nodi* en = g->nodi;
    
    while(en!=NULL){
        en->info->color = 0;
        en=en->next;
    }

    int piu_piccola = DFS_size(g->nodi->info);
    ln = g->nodi; // riutilizzo la variabile ln (non indispensabile)
    while( ln != NULL ) {
        if(ln->info->color == 0) { // trovata componente da visitare
        int size = DFS_size(ln->info); // la visito
        if( size < piu_piccola ) piu_piccola = size;
        }
        ln = ln->next;
    }
    return piu_piccola;

}

