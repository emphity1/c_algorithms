#include <stdlib.h>
#include <stdio.h>



/**
 * ALBERO: calcolare nodi che hanno un solo figlio
 * GRAFO: calcolare componente piu piccola
 * RIS: verifiare se sono uguali
 * 
 */


int dfs(nodo*n){
    int c=0;
    n->color = 1;
    elem_archi el = n->archi;

    while(el!=NULL){
        nodo* newNode = el->info->from;
        if(newNode == n){
            newNode = el->info->to;
        }
        if(newNode->color == 0){
            c = c + dfs(newNode)
        }
        el = el->next;
    }
    return c;
}

int comp_min(grafo* g){
    int min=0;
    elem_nodi* en = g->nodi;
    while(en!=NULL){
        en->info->color = 0;
        en = en->next;
    }
    en = g->nodi;
    min = dfs(en->info);
    en = en->next;
    while(en !=NULL){
        if(en->info->color == 0){
            int current = dfs(en->info);
            if(current > min ){
                min = current;
            }
        }
        en = en->next;
    }
    return min;
}


/*Nodi albero con un solo figlio*/
int conta_figli_singoli(nodo_albero* a){
    int c=0;
    if(a==NULL) return 0;
    if( (a->left==NULL)&&(a->right !=NULL)) c++;
    if( (a->left!=NULL)&&(a->right ==NULL)) c++;
    return c + conta_figli_singoli(a->left) + conta_figli_singoli(a->right);
}


int verifica(nodo_albero* a, grafo* g ){
    if(a==NULL || g==NULL) return 0;
    return conta_figli_singoli(a) == comp_min(g);
}