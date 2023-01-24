#ifndef _CODA_DI_NODI_H
#define _CODA_DI_NODI_H

typedef struct nodo_struct nodo;  // forward declaration

typedef struct nome_coda_struct {
     nodo** A;    // array (che mettero' sull'heap)
     int size;  // dimensione di A
     int head;  // indice dell'elemento da servire
     int tail;  // indice della prima cella vuota (da usare per il prossimo elemento)
} coda_nodi_struct;

typedef coda_nodi_struct* coda_nodi;

coda_nodi nuova_coda_di_nodi();

void enqueue_coda_nodi_telescopico(coda_nodi p, nodo* x);

nodo* dequeue_coda_nodi(coda_nodi p);

int is_coda_nodi_empty(coda_nodi p);


#endif