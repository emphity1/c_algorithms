#ifndef _LISTA_S
#define _LISTA_S

typedef struct it {

   int info; 
   struct it* next;

} item;

typedef item* lista_s;   // da questo momento in poi usare "item*" 
                         // o "lista_s" e' lo stesso

/*  questa definizione qui sotto e' obbligatoria se la
    lista ha piu' di un attributo, altrimenti e' un po'
    prolissa

typedef struct lis {

   item* head;  // 1° attributo
   int size;    // 2* attributo

} lista;
*/

void insert_lista_s(lista_s* l, int n);

int somma_lista_s(lista_s l);

int massimo_lista_s(lista_s l);

void cancella_lista_s(lista_s* l, item* i);

void cancella_lista_s_elem(lista_s* l, int v);

item* search_lista_s(lista_s l, int n);

void print_lista_s(lista_s l);

void push_lista_s(lista_s* l, int v);

int pop_lista_s(lista_s* l);

int comuni_lista_s(lista_s l1, lista_s l2);

int comuni_lista_s_efficiente(lista_s* l1, lista_s* l2);


void merge_sort_lista_s(lista_s* l);

lista_s merge_lista_s(lista_s l1, lista_s l2);

lista_s copia_lista_s(lista_s l);

void dealloca_lista_s(lista_s* l);

lista_s inversa_lista_s(lista_s l);

lista_s accoda_lista_s(lista_s l1, lista_s l2);

int lunghezza_lista_s(lista_s l);

#endif