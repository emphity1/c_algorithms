#ifndef _CODA_DI_INTERI_H
#define _CODA_DI_INTERI_H

typedef struct nome_coda_struct {
     int* A;    // array (che mettero' sull'heap)
     int size;  // dimensione di A
     int head;  // indice dell'elemento da servire
     int tail;  // indice della prima cella vuota (da usare per il prossimo elemento)
} coda_interi_struct;

typedef coda_interi_struct* coda_interi;

/*
   in questo momento questi tre tipi sono perfettamente equivalenti (sinonimi)

   struct nome_coda_struct* mia_coda;
   coda_interi_struct* mia_coda;
   coda_interi mia_coda;
*/


coda_interi nuova_coda_di_interi();

void enqueue_coda_interi(coda_interi p, int x);

void enqueue_coda_interi_telescopico(coda_interi p, int x);

int dequeue_coda_interi(coda_interi p);

void stampa_coda_interi(coda_interi p);

#endif