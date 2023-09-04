 #include <stdio.h>
 #include <stdlib.h>



struct nodo
 {
    int data;
    struct nodo* next;
    
 };
 
 //void list_insert(struct nodo**, int);

 int sommaLista(struct nodo* p){

    int somma = 0;
    while(p!=NULL){
        somma = somma + p->data;
        p = p->next;
    }

    printf("\nSomma della lista e': %d", somma);
    return 0;
 }
 

 int main(){
    struct nodo* testa;
    struct nodo* nodo1 = NULL;
    struct nodo* nodo2 = NULL;
    struct nodo* nodo3 = NULL;

    nodo1 = malloc(sizeof(struct nodo));
    nodo2 = malloc(sizeof(struct nodo));
    nodo3 = malloc(sizeof(struct nodo));
    
    nodo1->data= 2;
    nodo2->data= 5;
    nodo3->data= 6;

    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = NULL;
    testa = nodo1;

    sommaLista(testa);

 }



/*
 void list_insert(struct node** head, int new_data){
    struct nodo* nuovo = (struct nodo*)malloc(sizeof(struct nodo));
    if(nuovo==NULL) return 0;

    nuovo->data = new_data;
    nuovo->next = (*head);
    (*head) = nuovo;
 }
 */

 