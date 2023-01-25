#include <stdlib.h>
#include <stdio.h>


void DFS(nodo *n){
    n->color = 1;
    elem_archi ea = n->archi;
    while(ea!=NULL){
        nodo* nuovo_nodo = ea->info->from;
        if(nuovo_nodo == n){
            nuovo_nodo = ea->info->to;
        }
        if(nuovo_nodo->color == 0){
            DFS(nuovo_nodo);
        }
        ea = ea->next;
    }
}


int sottoalbero_om(nodo_albero* a){
    if( a==NULL) return 0;
    if(a->info != 1) return 0;
    int out = 1;
    nodo_albero* x = a->left;
    while(x!=NULL){
        out = out && sottoalbero_om(x);
        x=x->right;
    }
    return out;
}

int conta_sottoableri(nodo_albero* a){
    int out = 0;
    if(a==NULL) return 0;
    out = sottoalbero_om(a);
    nodo_albero* x = a->left;
    while(x!=NULL){
        out = out + conta_sottoableri(x);
    }
    return out;
}

int verifica(grafo_oggetti* g, nodo_albero* a){
    if(g==NULL && a==NULL) return 1;
    if(g==NULL || a==NULL) return 0;

    elem_nodi en = g->nodi;
    while(en!=NULL){
        en->info->color = 0;
        en=en->next;
    }
    int comp = 0;

    while(en!=NULL){
        if(en->info->color == 0){
            comp++;
            
        }
    }



}