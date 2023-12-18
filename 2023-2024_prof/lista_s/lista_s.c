#include <stdlib.h>
#include <stdio.h>
#include "lista_s.h"


void insert_lista_s(lista_s* l, int n) {

   item* new = (item*)malloc(sizeof(item));
   new->info = n;
   new->next = (*l);
   (*l) = new;
}

int somma_lista_s(lista_s l) {

   int somma = 0;
   item* x = l;
   while( x != NULL) {
       somma = somma + x->info;
       x = x->next;
   }
   return somma;
}

int massimo_lista_s(lista_s l) {

    if( l == NULL) {
    	printf("funzine massimo_lista_s() lanciata su lista vuota\n");
    	exit(1);
    }
    
    int max = l->info;
    item* x = l->next;
    while( x != NULL ) {
        if( x->info > max ) {
        	max = x->info;
        }
        x = x->next;
    }
    return max;
}

item* search_lista_s(lista_s l, int n){

    item* x = l;
    while ( x != NULL ) {
        if ( x->info == n ) return x;
    	x = x->next;
    }
    return NULL;
}

/* Suppongo che i sia un puntatore ad un elemento presente
   nella lista puntata da l. */

void cancella_lista_s(lista_s* l, item* i) {
//void cancella_lista_s(item** l, item* i) {

    if( (*l) == NULL || i == NULL ){
        printf("Errore: cancellazione da una lista vuota o di un elemento NULL\n");
        exit(1);
    }

    if( i == (*l) ) {  // vuoi cancellare il primo elemento della lista
        (*l) = (*l)->next;
    }
    item* prec = (*l);
    while( prec->next != i) {
        prec = prec->next;
    }
    prec->next = i->next;
    free(i);
}

/* Cancella tutte le copie dell'elemento v all'interno
   della lista */

void cancella_lista_s_elem(lista_s* l, int v) {
   
    if( (*l) == NULL ){
        printf("Errore: cancellazione da una lista vuota\n");
        exit(1);
    }

    if( v == (*l)->info ) {  // vuoi cancellare il primo elemento della lista
        (*l) = (*l)->next;
    }
    item* prec = (*l);
    while( prec->next != NULL) {
        if( prec->next->info == v) {  // l'ho trovato!
             item* cancellami = prec->next;
             prec->next = prec->next->next;  // l'ho scavalcato
             free(cancellami);               // l'ho deallocato
        } else {
            prec = prec->next;
        }
    }
}

void push_lista_s(lista_s* l, int v) {
    insert_lista_s(l, v);
}

int pop_lista_s(lista_s* l) {

    if( (*l) == NULL ){
        printf("Errore: pop sa una pila vuota\n");
        exit(1);
    }

    item* cancellami = (*l);
    int output = cancellami->info;
    (*l) = (*l)->next;
    free(cancellami);
    return output;
}



void print_lista_s(lista_s l) {

    int primo = 1;
    printf("lista = "); 
	while( l != NULL) {
         if( !primo ) {
         	printf("->");
         } 
         primo = 0;
         printf("[%d]",l->info);
         l = l->next;
	}
	printf("\n");
}

int comuni_lista_s(lista_s l1, lista_s l2) {
    int out = 0;
    item* x = l1;  // all'inizio della prima lista 
    while( x != NULL ) {
        item* y = l2;
        while ( y != NULL ) {
            if( x->info == y->info ) {
                out = out + 1;
                break;
            }
            y = y->next;
        }
        x = x->next;
    }
    return out;
}

/* Attenzione: modifica le liste */

int comuni_lista_s_efficiente(lista_s* l1, lista_s* l2) {
    merge_sort_lista_s(l1);
    merge_sort_lista_s(l2);

    int out = 0;
    item* x = (*l1);
    item* y = (*l2);
    while( x != NULL && y != NULL ) {

        if( x->info == y->info ) {
            out++;
            x = x->next;
        } else if( x->info < y->info ) {
            x = x->next;
        } else {  // x->info > y->info
            y = y->next;
        }
    }
    return out;
}



void merge_sort_lista_s(lista_s* l) {
 
   if( (*l) == NULL ) return;
   if( (*l)->next == NULL ) return; // la lista ha un solo elemento => gia' ordinata
   int lunghezza = 0;
   item* x = (*l);
   while( x != NULL ){
       lunghezza++;
       x = x->next;
   }
   lunghezza = lunghezza/2;   // implicito arrotondamento in basso
   x = (*l);    // mi rimetto all'inizio della lista
   while( lunghezza > 1) {
        x = x->next;
        lunghezza--;
   }  // ora x punta all'ultimo elemento della prima sotto-lista
   lista_s l2 = x->next;  // la seconda lista inizia dopo l'ultimo
                          // elemento della prima
   x->next = NULL;        // termino la prima lista
   lista_s l1 = (*l);

   merge_sort_lista_s(&l1);
   merge_sort_lista_s(&l2);

   (*l) = merge_lista_s(l1,l2);  // attenzione riutilizziamo i blocchetti
}

/* Aggiungo un blocco in coda ad una lista 
   Parametri: l = la lista da modificare
              ultimo = puntatore all'ultimo elemento di l oppure NULL se l vuota
              blocco = puntatore al blocchetto da aggiungere alla lista
   Ritorna il puntatore all'ultimo elemento della lista
*/

lista_s add_blocco_to_lista_s(lista_s* l, lista_s ultimo, item* blocco) {

    if ( (*l) == NULL ) {  // la lista era vuota
       (*l) = blocco;
       blocco->next = NULL;
       return blocco;
    }
    ultimo->next = blocco;
    blocco->next = NULL;
    return blocco;
}


lista_s merge_lista_s(lista_s l1, lista_s l2) {

     lista_s out = NULL;
     lista_s ultimo = NULL;

     item* x = l1;
     item* y = l2;
     while ( x != NULL && y != NULL ) {
          if ( x->info <= y->info ) {    // sposto il blocchetto della prima
                                           // lista nella lista di output
               item* next_x = x->next;
               ultimo = add_blocco_to_lista_s(&out,ultimo,x);
               x = next_x;

          } else {                         // prendo il blocchetto dalla seconda lista
               item* next_y = y->next;
               ultimo = add_blocco_to_lista_s(&out,ultimo,y);
               y = next_y;
          }
     }
     while ( x != NULL ) {
           item* next_x = x->next;
           ultimo = add_blocco_to_lista_s(&out,ultimo,x);
           x = next_x;
     }
     while ( y != NULL ) {
           item* next_y = y->next;
           ultimo = add_blocco_to_lista_s(&out,ultimo,y);
           y = next_y;
     }

     return out;
}

lista_s copia_lista_s(lista_s l) {
    lista_s copia = NULL;
    while( l != NULL ){   // sto usando come iteratore il mio parametro
        insert_lista_s(&copia, l->info);
        l = l->next;
    }
    lista_s rovesciata = inversa_lista_s(copia);
    dealloca_lista_s(&copia);
    return rovesciata;
}

void dealloca_lista_s(lista_s* l) {
    if( (*l) == NULL ) return;
    dealloca_lista_s(&((*l)->next));
    free(*l);
}

lista_s inversa_lista_s(lista_s l) {
    lista_s inversa = NULL;
    while( l != NULL ){   // sto usando come iteratore il mio parametro
        insert_lista_s(&inversa, l->info);
        l = l->next;
    }
    return inversa;
}

lista_s accoda_lista_s(lista_s l1, lista_s l2);


int lunghezza_lista_s(lista_s l) {
    if( l == NULL ) return 0;
    return 1 + lunghezza_lista_s(l->next);
}
