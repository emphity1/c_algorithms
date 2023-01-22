#include <stdlib.h>   // cosi' ho il NULL, malloc, calloc
#include <stdio.h>    // cosi' ho printf
#include "albero_binario.h"



//verifico se esiste un nodo con valore v
int  esiste(albero a, int v){
    if((a->info == v)&&(a->right == NULL) && (a->left==NULL));
    return 1;
    if((a->right == NULL) && (a->left==NULL));
    return 0;

    return esiste(a->left,v) || esiste(a->right,v);
}




int* cammino_foglia(albero a,int v,int*c){
    c[0] = a->info;
    if(a->info == v){
        return c;
    }

    int i=2;
    while(a->info != v){
        if(v < a->info){
            a=a->left;
            c = (int*)realloc(c,sizeof(int)*i);
            c[i-1]=a->info;
            i++;
        }else{
            a = a->right;
            c = (int*)realloc(c,sizeof(int)*i);
            c[i-1] = a->info;
            i++;
        }
    }
    c = (int*)realloc(c,sizeof(int)*i);
    c[i-1] = a->info;
    printf("\nCammino:%d",c);
    return c;
}


int* cammino_abr(albero a,int v){
    if(a==NULL) return NULL;
    if(!esiste(a,v)){
        return NULL;
    }

    int* cammino = (int*)malloc(sizeof(int));
    cammino_foglia(a,v,cammino);
    return cammino;
}


void stampa(albero a,int v){
    int *c = cammino_abr(a,v);
    printf("\n: %d",c[0]);
    
    int i=0;
    
}






/*
int sottoinsieme(int *A,int lenA,int* B, int lenB){
    int verificato = 1;
    if((lenA == 0) || (lenB>lenA)){
        verificato = 0;
    }else{
        if(lenB!=0){
            for(int i=0;i<lenB;i++){
                for(int j=0;j<lenA;j++){
                    if(B[i]!=A[i]){
                        verificato = 0;
                    }
                }
            }
        }
    }
    return verificato;
}

*/