#include <stdlib.h>
#include <stdio.h>

/*


SOLO GRAFO 


Cercare una componente connessa che abbiamo nodi totali
uguale al numero di componenti del grafo.


*/









void DFS(nodo*n,int color){
    n->color = color;
    elem_archi* ea = n->archi;

    while(ea!=NULL){
        nodo* newNode = ea->info->from;
        if(newNode == n){
            newNode = ea->info->to;
        }
        if(newNode->color == 0){
            DFS(ea,color);
        }
        ea=ea->next;
    }
}

int dim_com(grafo*g,int comp){
    int c=0;
    elem_nodi en = en->nodi;

    while(en!=NULL){
        if(en->info->color == comp){
            c++;
        }
        en=en->next;
    }
    return c;
}


//parto da un nodo e me li vedo tutti
int verifica(grafo* g){
    if(g==NULL) return 1;

    elem_nodi* en = g->nodi;
    while(en!=NULL){
        en->color = 0;
        en=en->next;
    }

    int color = 0;
    en=g->nodi;
    while(en!=NULL){
        if(en->info->color == 0){
            color++;
            DFS(en->info, color); //colore la componente con COLOR
                             //ogni componente avrà un COLOR suo.
        }
        en=en->next;
    }

    int i;
    for(i=1;i<=color;i++){
        if(dim_comp(g,i) == color){
            return 1;
        }
    }
    return 0;
}