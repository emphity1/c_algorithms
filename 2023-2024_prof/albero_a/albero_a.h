#ifndef _ALBERO_A_H
#define _ALBERO_A_H


typedef struct nodo_a {

   struct nodo_a* parent;
   struct nodo_a* left_child;
   struct nodo_a* right_sibling;
   int info;

} nodo_a;

typedef nodo_a* albero_a;  // facciamo coincidere l'albero 
                           // con il puntatore alla radice

nodo_a* aggiungi_figlio_albero_a(nodo_a** pn, int val);

int conta_nodi_albero_a(nodo_a* n);
int conta_nodi_albero_a2(nodo_a* n);

nodo_a* cerca_nodo_albero_a(nodo_a* n, int val);
nodo_a* cerca_nodo_albero_a2(nodo_a* n, int val);

int binario_albero_a(nodo_a* n);
int binario_albero_a2(nodo_a* n);
int binario_albero_a3(nodo_a* n);


void stampa_outline_a(nodo_a* n);



#endif
