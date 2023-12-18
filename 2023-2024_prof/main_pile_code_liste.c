#include <stdlib.h>   // ora ho NULL
#include <stdio.h>    // ora ho printf
//#include "pila_di_interi/pila_di_interi.h"
//#include "coda_di_interi/coda_di_interi.h"
#include "lista_s/lista_s.h"
#include "lista_d/lista_d.h"


int main() {

  /* OPERAZIONI SU UNA LISTA SEMPLICEMENTE CONCATENATA DI INTERI */
   
  lista_s l = NULL;   // questa e' una lista vuota

  insert_lista_s(&l,1);
  insert_lista_s(&l,2);
  int i;
  for(i = 3 ; i < 20; i++) {
     insert_lista_s(&l,-i);
     if( i == 4)
        insert_lista_s(&l,-i);
  }
  print_lista_s(l);

  printf("la somma degli elementi della lista e' %d\n", somma_lista_s(l));
  printf("il massimo degli elementi della lista e' %d\n", massimo_lista_s(l));

  printf("la ricerca di -5 produce NULL? %d\n",search_lista_s(l,-5) == NULL);
  printf("la ricerca di +5 produce NULL? %d\n",search_lista_s(l,5) == NULL);

  item* x = l->next->next;
  cancella_lista_s(&l,x);
  print_lista_s(l);
  
  /*
  printf("cancello il -4\n");
  cancella_lista_s_elem(&l,-4);
  print_lista_s(l);

  printf("push di -4\n");
  push_lista_s(&l,-4);
  printf("push di 100\n");
  push_lista_s(&l,100);
  print_lista_s(l);

  printf("eseguo un pop e ottengo %d\n", pop_lista_s(&l));  
  print_lista_s(l);
  */

  lista_s l2 = NULL;
  insert_lista_s(&l2,1);
  insert_lista_s(&l2,-4);
  insert_lista_s(&l2,-5);
  insert_lista_s(&l2,50);
  printf("stampo la lista l2\n");
  print_lista_s(l2);

  printf("numero di elementi di l che sono anche in l2 = %d\n", comuni_lista_s(l,l2));
  printf("numero di elementi di l2 che sono anche in l = %d\n", comuni_lista_s(l2,l));

  printf("numero di elementi di l che sono anche in l2 (efficiente) = %d\n", comuni_lista_s_efficiente(&l,&l2));
  printf("numero di elementi di l2 che sono anche in l (efficiente) = %d\n", comuni_lista_s_efficiente(&l2,&l));




  for(i = 3 ; i < 10; i++) {
     insert_lista_s(&l,i);
  }
  print_lista_s(l);

  printf("merge sort di l\n");
  merge_sort_lista_s(&l);
  print_lista_s(l);

  printf("la lista rovesciata e': ");
  lista_s rovesciata = inversa_lista_s(l);
  print_lista_s(rovesciata);

  /* OPERAZIONI SU UNA LISTA DOPPIAMENTE CONCATENATA */

  printf("creo una lista doppiamente concatenata\n");
  lista_d ld = NULL;
  insert_lista_d(&ld, 1);
  insert_lista_d(&ld, 2);
  print_lista_d(ld);

  printf("inserisco 10 prima del primo elemento\n");
  insert_before_d(&ld, 10, ld);  
  print_lista_d(ld);

  printf("inserisco 100 prima del terzo elemento\n");
  insert_before_d(&ld, 100, ld->next->next);  
  print_lista_d(ld);

  printf("inserisco 200 dopo il primo elemento\n");
  add_after_d(&ld, 200, ld);  
  print_lista_d(ld);

  elem* temp = ld;
  while( temp->next != NULL ) temp = temp->next;

  printf("inserisco 300 dopo l'ultimo elemento\n");
  add_after_d(&ld, 300, temp);  
  print_lista_d(ld);

  printf("\nORDINAMENTO TRAMITE INSERTION SORT\n");
  
  lista_d ld2 = insertion_sort_lista_d(ld);
  print_lista_d(ld2);

  printf("\nINSERIMENTO IN ORDINE\n");

  lista_d l3 = NULL;
  insert_ordered_lista_d(&l3, 10);
  print_lista_d(l3);
  insert_ordered_lista_d(&l3, 8);
  print_lista_d(l3);
  insert_ordered_lista_d(&l3, 9);
  print_lista_d(l3);
  insert_ordered_lista_d(&l3, 12);
  print_lista_d(l3);
  insert_ordered_lista_d(&l3, 13);
  print_lista_d(l3);
  insert_ordered_lista_d(&l3, 10);
  print_lista_d(l3);

  printf("no_doppioni_lista_d(l3)=%d\n", no_doppioni_lista_d(l3));

  printf("no_doppioni_sorted_lista_d(l3)=%d\n", no_doppioni_sorted_lista_d(l3));

  /* prove per generare un segmentation fault

  int A[10];

  A[100] = 3;

  printf("A[100]=%d\n", A[100]);

  elem* punt = NULL;
  punt->next = NULL;
  */

/* OPERAZIONI SU UNA PILA DI INTERI */

/*
   pila* p = new_pila(4);
   push(p,1);
   //print(p);
   push(p,2);
   //print(p);
   push(p,3);
   //print(p);
   pop(p);
   //print(p);
   push(p,4);
   //print(p);
   push(p,5);
   //print(p);
   push(p,6);
   //print(p);
*/

/* OPERAZIONI SU UNA CODA DI INTERI */

  /*

   coda* c = new_coda(4);
   print_coda(c);

   enqueue(c,1);
   print_coda(c);
   enqueue(c,2);
   print_coda(c);
   printf("dequeue dell'elemento %d\n",dequeue(c));
   print_coda(c);
   printf("dequeue dell'elemento %d\n",dequeue(c));
   print_coda(c);
   int i;
   for( i = 3 ; i < 50; i++) {
      enqueue(c,i);
      print_coda(c);
   }

   */
}