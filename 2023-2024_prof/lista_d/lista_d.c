#include <stdlib.h>
#include <stdio.h>
#include "lista_d.h"


void insert_lista_d(lista_d* l, int n) {

   elem* new = (elem*)malloc(sizeof(elem));
   new->info = n;
   new->next = (*l);
   new->prev = NULL;
   if( (*l) != NULL  ) {   // la lista non era vuota
       (*l)->prev = new;
   }
   (*l) = new;
}

void insert_before_d(lista_d* l, int n, elem* i) {
    elem* new = (elem*)malloc(sizeof(elem));
    new->info = n;
    new->next = i;
    if ( i == (*l) ) {  // vuoi inserire prima del primo elemento
        i->prev = new;
        new->prev = NULL;
        (*l) = new;          // inserimento in testa
    } else {
        i->prev->next = new;
        new->prev = i->prev;
        i->prev = new;
    }

}


void add_after_d(lista_d* l, int n, elem* i) {
    elem* new = (elem*)malloc(sizeof(elem));
    new->info = n;
    new->prev = i;
    if( i->next == NULL ) {  // inserimento in coda
        new->next = NULL;
        i->next = new;
    } else {  // inserimento nel mezzo
        i->next->prev = new;
        new->next = i->next;
        i->next = new;
    }
}



void print_lista_d(lista_d l) {

    int primo = 1;
    printf("lista = "); 
	while( l != NULL) {
         if( !primo ) {
         	printf("<->");
         } 
         primo = 0;
         printf("[%d]",l->info);
         l = l->next;
	}
	printf("\n");
}

/* cancello la prima occorrenza dell'elemento n.
   Se n non esiste nella lista non faccio nulla. */

void cancella_lista_d(lista_d* l, int n) {

   elem* x = (*l);   // iteratore per scorrere la lista
   while( x != NULL ) {
      if( x->info == n ) {  // trovato elemento da cancellare

         // aggiorno la catena a monte 
         //
         if( x->prev == NULL ) { // x e' il primo elemento
            (*l) = x->next;   // equivalente a (*l) = (*l)->next; 
         } else {
            x->prev->next = x->next;
         }

         // aggiorno la catena a valle
         //
         if( x->next != NULL ) {  // x non e' l'ultimo elemento
            x->next->prev = x->prev;
         }
         free(x);
         return;
      }
      x = x->next;
   } 
}

/* inserimento in lista rispettando l'ordine e in maniera  
   stabile (cioè valori uguali saranno nella lista risutato esattamente
   nell'ordine con cui sono inseriti) */

void insert_ordered_lista_d(lista_d* l, int n) {

    if( (*l) == NULL ) {  // lista vuota => inserimento in testa
        insert_lista_d(l, n);
        printf("inserisco %d in testa alla lista\n",n);
        return;
    } else if( (*l)->info > n ) {  // inserimento in testa
        printf("inserisco %d in testa alla lista e prima di %d\n",n,(*l)->info);
        insert_lista_d(l, n);
        return;
    } 

    /* sarebbe equivalente ai due test sopra ma 
       non lo è perché, qualora il compilatore valuta
       le espressioni da destra verso sinistra, da' segmentation
       fault quando (*l) == NULL 

    if( (*l) == NULL || (*l)->info > n  ) {
        insert_lista_d(l,n);
        return;
    }
    */

  /*
             i   voglio un puntatore all'ultimo elemento della lista
             |   che ha un valore "val" <= del valore "n" da inserire 
             V             i->next
          *------*     *-----------------*
          |  val |---->| i->next->info   |   
          *------*     *-----------------*
  */



    elem* i = (*l);
    while( i->next != NULL ) {  // finché non arrivo all'ultimo
        if( i->next->info > n ) {
            add_after_d(l, n, i);
            printf("inserisco %d dopo di %d\n",n,i->info);
            return;
        }
        i = i->next;
    }
    /* se sei qui è perché i->next == NULL.
       il campo i->info l'abbiamo già controllato quando
       eravamo sull'elemento che precede i. */
    add_after_d(l, n, i);
    printf("inserisco %d dopo di %d in quanto e' finita la lista\n",n,i->info);
}

lista_d insertion_sort_lista_d(lista_d l) {

    lista_d out = NULL;
    elem* i = l;
    while( i != NULL) {
        insert_ordered_lista_d(&out,i->info);
        i = i->next;
    }
    return out;
}

int no_doppioni_lista_d(lista_d l) {
    int out = 1;  // suppongo che non ci siano doppioni
    elem* i = l;
    while( i != NULL && out == 1 ){
        elem* j = i->next;
        while( j != NULL && out == 1 ) {
            if ( i->info == j->info ) {
                out = 0;    // contiene un doppione
            }
            j = j->next; 
        }
        i = i->next;
    }
    return out;
}


int no_doppioni_lista_d_patrignani(lista_d l) {
    elem* i = l;
    while( i != NULL ){
        elem* j = i->next;
        while( j != NULL ) {
            if ( i->info == j->info ) {
                return 0;    // contiene un doppione
            }
            j = j->next; 
        }
        i = i->next;
    }
    return 1;
}

int no_doppioni_sorted_lista_d(lista_d l) {

    if(l == NULL) return 1;        // non ci sono doppioni
    if(l->next == NULL) return 1;  // non ci sono doppioni

    while ( l->next != NULL ) {
        if( l->info == l->next->info ) {
            return 0;  // c'è un doppione
        }
        l = l->next;
    }
    return 1;  // non c'è nessun doppione
}