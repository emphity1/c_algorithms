#include <stdlib.h>
#include <stdio.h>

/*
che accetti in input un puntatore ad grafo non orientato g rappresentato tramite oggetti e un puntatore a
alla radice di un albero binario di interi. La funzione restituisce 1 se il numero di nodi della componente
connessa più grande (cioè con più nodi) del grafo è uguale alla profondità del nodo con indice (campo info)
più alto dell’albero, altrimenti restituisce 0.
*/


//ricerca in profondità
void DFS(nodo*n,int mark){
    n->color = mark;
    elem_archi ea = n->archi;
    while(ea!=NULL){
        nodo* nuovo_nodo = ea->info->from;
        if(nuovo_nodo == n){
            nuovo_nodo = ea->info->to;
        }
        if(nuovo_nodo->color == 0){
            DFS(nuovo_nodo,mark);
        }
        ea = ea->next;
    }
    
}
//ritorna il numero di nodi della componente
int nodi_comp(grafo_ogg* g, int comp){
    int c = 0;
    elem_nodi* en = g->nodi;
    while(en!=NULL){
        if(en->info->color == comp){
            c++;
        }
        en=en->next;
    }
    return c;
}
int massimo(int a,int b){
    if(a>b) return a;
    return b;
}


//valore massimo contenuto in UN NODO nell'albero
int max_albero(nodo_albero* a){
    if(a==NULL) return 0;
    int left = massimo_alber(a->left);
    int right = massimo_albero(a->right);
    return massimo(a->info,massimo(left,right));
    
}






int verifica(grafo_oggetti* g, nodo_alber* a){

    elem_nodi en = g->nodi;
    while(en != NULL){
        en->info->color = 0;
        en= en->next;
    }
    int comp = 0;
    en = g->nodi;

    while(en!=NULL){
        if(en->info->color == 0){
            comp++;
            DFS(n,comp);
        }
        en=en->next;
    }

    int nodi_comp_max = 0;
    int j;
    for(j=1; j<=comp;j++){
        nodi_comp_max = massimo(nodi_comp_max,nodi_comp(g,j));
    }

    int prof_nodo = profondita_nodo(a, massimo_albero(a));
    return prof_nodo == nodi_comp_max;

}