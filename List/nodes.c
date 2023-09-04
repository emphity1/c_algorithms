#include <stdio.h>
#include <stdlib.h>

// struttura del nodo
typedef struct nodo{
    int elemento;
    struct nodo* successivo; //lista concatenada singolarmente
} nodo;


nodo* add_head(int n, nodo* head){
    if(head!=NULL){ //se la head non è vuoto
        nodo* nodoNext = head; //creo var nodoNext di tipo nodo e gli assegno head attuale
        head = (nodo*) malloc(sizeof(nodo));//alloco memoria a head
        head -> elemento = n; //assegno il mio valore n al mio campo elemento
        head -> successivo = nodoNext; //il mio nodo punta al nodoNext(vecchio head)
    }else{
        //se head è vuoto
        head = (nodo*)malloc(sizeof(nodo));
        head -> elemento = n;
        head -> successivo = NULL;

    }
}