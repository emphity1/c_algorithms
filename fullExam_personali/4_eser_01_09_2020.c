#include <stdlib.h>
#include <stdio.h>


/*
Cercare un NODO che è radice di un sottoalbero che ha 
esattamente la metà dei nodi dell'intero albero

*/


//conta tutti nodi dell'albero
int totale_nodi(nodi*a){
    if(a==NULL) return 0;
    return 1 + totale_nodi(a->left) + totale_nodi(a->right);
}



int cerca_sottoalbero(nodo*a,int nodi){
    if(a==NULL) return 0;
    if(totale_nodi(a) == nodi) return 1;

    return cerca_sottoalbero(a->left,nodi) || cerca_sottoalbero(a->right,nodi);
}


int verifica(nodo*a){
    if(a==NULL) return 0;
    int nodi = totale_nodi(a);
    if(nodi%2 == 1) return 0; //verifico che nodi totali sono pari

    return cerca_sottoalbero(a,nodi/2); //richiamo la funzione per calcolare cercare sottoalbero
}