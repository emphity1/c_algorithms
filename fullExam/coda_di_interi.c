#include <stdlib.h>
#include <stdio.h>
#include "coda_di_interi.h"

coda_interi nuova_coda_di_interi() {

	coda_interi mia_coda = (coda_interi)malloc(sizeof(coda_interi_struct));

	mia_coda->size = 4;
	mia_coda->A = (int*)calloc(mia_coda->size,sizeof(int));
	mia_coda->head = 0;
	mia_coda->tail = 0;
	return mia_coda;
}

void enqueue_coda_interi(coda_interi p, int x) {

	if( (p->tail + 1 == p->head) || (p->head == 0 && p->tail == p->size-1) ) {
		printf("overflow: inserimento in una coda piena (size = %d)\n",p->size);
		exit(1);
	}
    p->A[p->tail] = x;
    p->tail = p->tail + 1;
    if( p->tail == p->size) {
    	p->tail = 0;
    } 
}

void enqueue_coda_interi_telescopico(coda_interi p, int x) {

	if( (p->tail + 1 == p->head) || (p->head == 0 && p->tail == p->size-1) ) {
        int new_size = p->size*2;
		printf("raddoppio l'array da %d a %d\n", p->size, new_size);
		p->A = (int*)realloc(p->A,new_size*sizeof(int));
        if( p->tail + 1 == p->head ) {
        	int i;
        	for( i = 0; i < p->tail; i++) {
        		p->A[p->size+i] = p->A[i];
        	}
        	p->tail = p->size + p->tail;   // == p->size + i
        }
        p->size = new_size;
	}
    p->A[p->tail] = x;
    p->tail = p->tail + 1;
    if( p->tail == p->size) {
    	p->tail = 0;
    } 


}

int dequeue_coda_interi(coda_interi p) {

   if( p->head == p->tail ) {
   	  printf("errore di underflow: dequeue su coda vuota\n");
      exit(1);
   }
   int output = p->A[p->head];
   p->head++;
   if( p->head == p->size) {
   	   p->head = 0;
   }
   return output;
}

void stampa_coda_interi(coda_interi c){

	int i;
	printf("A = ");
	for( i = 0; i < c->size; i++) {
		printf("%d ", c->A[i]);
	}
    printf("\nhead = %d\n", c->head);
    printf("tail = %d\n", c->tail);
  

}
