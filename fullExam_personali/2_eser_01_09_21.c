#include <stdlib.h>
#include <stdio.h>


/*
1)Cerca la profondità della foglia meno profonda
2)Cercare nodi componente piu piccola

Verificare che la 1) = 2)

*/

int DFS_conta(nodo*n){
    //conto nodi della comp min
    n->color = 1;
    int c=1;
    elem_archi ea = n->archi;
    while(ea != NULL){
        nodo* newNode = ea->info->from;
        if(newNode == n){
            newNode = ea->info->to;
        }
        if(newNode->info->color == 0){
            c = c + DFS_conta(newNode);
        }
        ea = ea->next;
    }

    return c;
}

int prof_foglia_min(nodo_albero* a,int prof){
    if(a==NULL) return -1;
    if(a->left==0 && a->right ==NULL) return p;

    int l = prof_foglia_min(a->left,p+1);
    int r = prof_foglia_min(a->right,p+1);
    
    if(l == -1) return l;
    if(r ==-1) return r;

    if(l>r) return l;
    return r;
}


int comp_min(grafo* g){
    elem_nodi* ln = g->nodi;
    while(ln != NULL){
        ln->info->color=0;
        ln=ln->next;
    }

    int min = g->numero_nodi;
    ln = g->nodi;
    while(ln!=NULL){
        if(ln->info->color == 0){
            int current = DFS_conta(ln->info);
            if(current>min){
                min=current;
            }
        }
        ln = ln->next;
    }
    return min;

}




int verifica(nodo_albero* a, grafo* g){
    if(a==NULL || g==NULL) return 0;
    return prof_foglia_min(a,0) == comp_min(g);
}