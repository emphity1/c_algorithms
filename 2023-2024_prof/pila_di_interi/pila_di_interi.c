#include <stdlib.h>
#include <stdio.h>
#include "pila_di_interi.h"

pila* new_pila(int size) {

    pila* out = (pila*)malloc(sizeof(pila));
    out->A = (int*)calloc(size,sizeof(int));
    out->size = size;
    out->top = -1;

    return out;
}

int is_empty(pila* p) {
    return p->top == -1;
}


void push(pila* p, int i) {

    if( p->top == p->size - 1) {
        //printf("Errore: inserimento in una pila di dimensione %d piena!\n", p->size);
        //exit(1);
        p->size = p->size*2;
        p->A = (int*)realloc(p->A,sizeof(int)*p->size);
    } 
    p->top = p->top + 1;
    p->A[p->top] = i;

}

int pop(pila* p) {

   if(is_empty(p)) {
      printf("Errore: estrazione da un pila vuota\n");
      exit(1);
   } else {
      p->top = p->top-1;
      return p->A[p->top+1];
      // return p->A[p->top--];  // equivalente ma piu' involuto
   }

}

int top(pila* p){
   if(is_empty(p)) {
      printf("Errore: top su un pila vuota\n");
      exit(1);
   } else {
      return p->A[p->top];
   }
}

void print(pila* p) {

	printf("contenuto della pila: ");
	int i;
	for( i = 0; i < p->size ; i++) {
        printf("[%d]",p->A[i]);
	}
    printf("p->top = %d\n", p->top);
}