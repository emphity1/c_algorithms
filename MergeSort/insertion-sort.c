#include <stdlib.h>
#include <stdio.h>
#include "insertion-sort.h"


void insertion_sort(int* A, int size) {

	int i;
	for ( i = 1; i < size ; i++) { 

        // debugging e logging
        int k;
        for(k = 0; k < size; k++) {
        	if( k == i ) {
        		printf("[%d]",A[k]);
        	} else {
        		printf(" %d ",A[k]);
        	}
        }
        printf("\n");

		int key = A[i];
		int j = i-1;
		while( j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			j = j - 1;
		}
        A[j+1] = key;
    }

}

/* L'elemento che considero e' quello in posizione next.
   Assumo che tutto l'array da 0 a next-1 sia gia' ordinato.
   Inserisco l'elemento in posizione next nell'array ordinato 
   e chiamo ricorsivamente con la posizione next+1. */

void insertion_sort_ric(int* A, int size, int next) {

    if( next == size ) return; // caso base: ho finito

	int key = A[next];
	int j = next-1;
	while( j >= 0 && A[j] > key) {
		A[j+1] = A[j];
		j = j - 1;
	}
    A[j+1] = key;
    insertion_sort_ric(A, size, next+1);
}