#include <stdlib.h>
#include <stdio.h>


/*
Cerca nodi a profondità H e li conta
Conta nodi della componente piu grande
Verifica se sono uguali
*/


/*ALBERO*/
int cerca_nodi_prof(nodo_albero* a){
    if(a==NULL) return 0;
    int prof = 0;
    //passo base
    if(h==0) return 1;
    return cerca_nodi_prof(a->left,h-1) + cerca_nodi_prof(a->right,h-1);
}


/*GRAFO*/

int dfs_conta(nodo* n){
    int c=0;
    n->color = 1;
    elem_archi* el = n->archi;
    while(el!=NULL){
        nodo* nuovo_nodo = el->info->from;
        if(nuovo_nodo == n){
            nuovo_nodo = el->info->from;
        }
        if(nuovo_nodo->color == 0){
            c = c + dfs_conta(nuovo_nodo);
        }
        el=el->next;
    }
    return cont;
}

//calcolo della componente massima
int comp_max(grafo* g){
    int max_nodi = 0;
    elem_nodi* ln = g->nodi;
    while(ln!=0){
        ln->info->color = 0;
        ln=ln->next;
    }
    ln = g->nodi;
    while(ln != NULL){
        if(ln->info->color == 0){
            int current = dfs_conta(ln->info);
            if(current > max_nodi){
                max_nodi = current;
            }
        }
        ln = ln->next;
    }
    return max_nodi;
}



int verifica(int h,nodo_albero*a, grafo*g){
    if(a==NULL || g==NULL) return 0;
    return cerca_nodi_prof(a,h) == comp_max(g);
}

