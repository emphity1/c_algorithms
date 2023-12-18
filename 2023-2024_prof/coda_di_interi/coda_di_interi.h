#ifndef _CODA_DI_INTERI
#define _CODA_DI_INTERI

typedef struct {

   int* A; 
   int size;
   int head;
   int tail;

} coda;

coda* new_coda(int size);

int is_empty_coda(coda* c);

void enqueue(coda* c, int x);

int dequeue(coda* c);

void print_coda(coda* c);

#endif