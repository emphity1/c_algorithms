#include <stdlib.h>
#include <stdio.h>
#include "coda_di_nodi.h"
#include "grafo_oggetti.h"

coda_nodi nuova_coda_di_nodi() {

	coda_nodi mia_coda = (coda_nodi)malloc(sizeof(coda_nodi_struct));

	mia_coda->size = 4;
	mia_coda->A = (nodo**)calloc(mia_coda->size,sizeof(nodo*));
	mia_coda->head = 0;
	mia_coda->tail = 0;
	return mia_coda;
}

void enqueue_coda_nodi_telescopico(coda_nodi p, nodo* x) {


	if( (p->tail + 1 == p->head) || (p->head == 0 && p->tail == p->size-1) ) {
        int new_size = p->size*2;
		printf("raddoppio l'array da %d a %d\n", p->size, new_size);
		p->A = (nodo**)realloc(p->A,new_size*sizeof(nodo*));
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

nodo* dequeue_coda_nodi(coda_nodi p) {

   if( p->head == p->tail ) {
   	  printf("errore di underflow: dequeue su coda vuota\n");
      exit(1);
   }
   nodo* output = p->A[p->head];
   p->head++;
   if( p->head == p->size) {
   	   p->head = 0;
   }
   return output;
}

int is_coda_nodi_empty(coda_nodi p) {
   return p->head == p->tail;
}