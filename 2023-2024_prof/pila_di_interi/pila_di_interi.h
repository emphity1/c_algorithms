#ifndef _PILA_DI_INTERI
#define _PILA_DI_INTERI

typedef struct p {

   int* A; 
   int size;
   int top;

} pila;

pila* new_pila(int size);

int is_empty(pila* p);

void push(pila* p, int i);

int pop(pila* p);

int top(pila* p);

void print(pila* p);

#endif