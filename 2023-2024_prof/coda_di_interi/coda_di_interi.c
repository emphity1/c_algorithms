#include <stdlib.h>
#include <stdio.h>
#include "coda_di_interi.h"

coda* new_coda(int size) {

    coda* out = (coda*)malloc(sizeof(coda));
    out->A = (int*)calloc(size,sizeof(int));
    out->size = size;
    out->head = 0;
    out->tail = 0;

    return out;
}

int is_empty_coda(coda* c);

void enqueue(coda* c, int x) {

   if( (c->tail == c->head-1) || 
       (c->head == 0 && c->tail == c->size-1) ) {
       //printf("Errore: enqueue su una pila piena\n");
       //exit(1);
       c->size = c->size*2;
       c->A = (int*)realloc(c->A,sizeof(int)*c->size);
       if( c->head > c->tail ) {
            int i;
            for( i = 0; i < c->tail ; i++) {
                 c->A[c->size/2 + i] = c->A[i];
            }
            c->tail = c->size/2 + i; 
       }
   } 
   c->A[c->tail] = x;
   c->tail = (c->tail+1) % c->size;
}

int dequeue(coda* c) {

    if( c->head == c->tail) {
        printf("Errore: dequeue da coda vuota\n");
        exit(1);
    }
    int out = c->A[c->head];
    c->head = (c->head+1) % c->size;
    return out;
}

void print_coda(coda* c) {

    printf("contenuto della coda: ");
    int i;
    for( i = 0; i < c->size ; i++) {
        printf("[%d]",c->A[i]);
    }
    printf(" c->head = %d, c->tail = %d\n", c->head,c->tail);
}
