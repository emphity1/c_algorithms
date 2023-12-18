#ifndef _LISTA_D
#define _LISTA_D

typedef struct elem {

   int info; 
   struct elem* prev;
   struct elem* next;

} elem;

typedef elem* lista_d;   // da questo momento in poi usare "item*" 
                         // o "lista_s" e' lo stesso


void insert_lista_d(lista_d* l, int n);

void insert_before_d(lista_d* l, int n, elem* i);

void add_after_d(lista_d* l, int n, elem* i);


void print_lista_d(lista_d l);

void cancella_lista_d(lista_d* l, int n);

void insert_ordered_lista_d(lista_d* l, int n);

lista_d insertion_sort_lista_d(lista_d l);

int no_doppioni_lista_d(lista_d l);

int no_doppioni_lista_d_patrignani(lista_d l);

int no_doppioni_sorted_lista_d(lista_d l);


#endif