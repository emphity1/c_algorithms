#include <stdlib.h>
#include <stdio.h>
#include "albero_b.h"


nodo* aggiungi_nodo_abr(nodo** ppn, int val) {

    nodo* new = NULL;
    if( (*ppn) == NULL ) {
        new = (nodo*)malloc(sizeof(nodo));
        new->parent = NULL;
        new->left = new->right = NULL;
        new->info = val;
        (*ppn) = new;
        return new;
    }
    if( (*ppn)->info == val ) {  // il nodo corrente contiene la chiave da aggiungere
        return (*ppn);   // se avessi coppie chiave/valore aggiornerei il valore
    }
    if( (*ppn)->info > val ) {   // devo aggiungere il nuovo nodo nel sottoalbero sx
        new = aggiungi_nodo_abr(&((*ppn)->left), val);
        if((*ppn)->left == new) {
            new->parent = (*ppn);
        }
    } else {   // devo aggiungere il nuovo nodo nel sottoalbero dx
        new = aggiungi_nodo_abr(&((*ppn)->right), val);
        if((*ppn)->right == new) {
            new->parent = (*ppn);
        }
    }
    return new;
}

nodo* aggiungi_nodo_abr2(nodo** ppn, int val) {
    nodo* new = NULL;
    if( (*ppn) == NULL ) {
        new = (nodo*)malloc(sizeof(nodo));
        new->parent = NULL;
        new->left = new->right = NULL;
        new->info = val;
        (*ppn) = new;
        return new;
    }
    nodo* px = NULL;    // parent di x
    int x_is_left = 0;  // true se x e' il figlio sinistro del parent
    nodo* x = (*ppn);  // iteratore per scendere nell'albero
    while( x != NULL ) {
        px = x;
        if( val < x->info ) {
            x = x->left;
            x_is_left = 1;
        }
        else if( val > x->info ) {
            x = x->right;
            x_is_left = 0;
        }
        else return x;
    }
    // l'iteratore x == NULL; px e' il parent a cui devo aggiungere il nodo
    // a sinistra o a destra dipendentemente da x_is_left
    new = (nodo*)malloc(sizeof(nodo));
    new->parent = px;
    new->left = new->right = NULL;
    new->info = val;
    if( x_is_left ) {
        px->left = new;
    } else {
        px->right = new;
    }
    return new;
}

/* 
   questa funzione qua sotto si userebbe cosi':
   "is_albero_b_empty(mio_albero)"
   ma e' piu' breve scrivere direttamente
   "mio_albero == NULL"
*/
int is_albero_b_empty(albero a) {
	return a == NULL;
}

int two_children(nodo* n) {
	return n->left != NULL && n->right != NULL;
}

void aggiungi_figlio_b(nodo* parent, nodo** pn, int val) {

    nodo* new = (nodo*)malloc(sizeof(nodo));
    new->parent = parent;
    new->left = new->right = NULL;
    new->info = val;
    (*pn) = new;
}

nodo* aggiungi_figlio_2(nodo* parent, int val) {

    nodo* new = (nodo*)malloc(sizeof(nodo));
    new->parent = parent;
    new->left = new->right = NULL;
    new->info = val;
    return new;
}

/* ritorna NULL se nessun nodo contiene il valore val.
   precondizione: n non e' mai null*/

nodo* cerca_albero_b_preordine_prolissa(nodo* n, int val) {

   if( n->info == val ) return n;

   nodo* sx = NULL;
   if( n->left != NULL) sx = cerca_albero_b_preordine(n->left, val);
   if( sx != NULL ) return sx;

   nodo* dx = NULL;
   if( n->right != NULL) dx = cerca_albero_b_preordine(n->right, val);
   return dx;
}

/* ritorna NULL se nessun nodo contiene il valore val. */

nodo* cerca_albero_b_preordine(nodo* n, int val) {

   if( n == NULL ) return NULL;
   printf("controllo il nodo %d\n", n->info);
   if( n->info == val ) return n;

   nodo* sx = cerca_albero_b_preordine(n->left, val);
   if( sx != NULL ) return sx;
   nodo* dx = cerca_albero_b_preordine(n->right, val);
   return dx;
}


nodo* cerca_albero_b_postordine(nodo* n, int val){

   if( n == NULL ) return NULL;

   nodo* sx = cerca_albero_b_postordine(n->left, val);
   if( sx != NULL ) return sx;
   nodo* dx = cerca_albero_b_postordine(n->right, val);
   if( dx != NULL )  return dx;

   printf("controllo il nodo %d\n", n->info);

   if( n->info == val ) return n;
   else return NULL;
}


nodo* cerca_albero_b_simmetrica(nodo* n, int val){

   if( n == NULL ) return NULL;

   nodo* sx = cerca_albero_b_simmetrica(n->left, val);
   if( sx != NULL ) return sx;

   printf("controllo il nodo %d\n", n->info);
   
   if( n->info == val ) return n;

   nodo* dx = cerca_albero_b_simmetrica(n->right, val);
   return dx;
}

int conta_nodi_albero_b(nodo* n) {
    if( n == NULL) return 0;
    /*
    int sx = conta_nodi_albero_b(n->left);
    int dx = conta_nodi_albero_b(n->right);
    return 1 + sx + dx; 
    */
    return 1 + conta_nodi_albero_b(n->left) + conta_nodi_albero_b(n->right);
}

int cammino_albero_b(nodo* n) {

    if( n == NULL ) return 1;   // l'albero vuoto e' un cammino

    if( n->left != NULL && n->right != NULL ) return 0;  // non sono un cammino

    // se sei qui uno dei figli o entrambi i figli sono NULL

    return cammino_albero_b(n->left) && cammino_albero_b(n->right); 
}

int altezza_albero_b(nodo* n) {
    
    if( n == NULL) return -1;

    int l = altezza_albero_b(n->left);
    int r = altezza_albero_b(n->right);
    if( l > r )
        return l+1;
    return r+1;      // l <= r
}

int altezza_albero_b_2_ricorri(nodo* n, int prof) {

    if( n == NULL ) return -1;
    if( n->left == NULL && n->right == NULL ) return prof;
    int l = altezza_albero_b_2_ricorri(n->left, prof+1);
    int r = altezza_albero_b_2_ricorri(n->right, prof+1);
    if( l > r) return l;
    return r;
}

int altezza_albero_b_2(nodo* n) {
    return altezza_albero_b_2_ricorri(n,0);  // la lancio sulla radice che ha prof. 0
}

int altezza_albero_b_3(nodo* n) {

    if( n == NULL ) return -1;

    if( n->left == NULL && n->right == NULL ) {
        // sono una foglia, mi calcolo l'altezza e la ritorno
        nodo* p = n->parent;
        int prof = 0;
        while(p != NULL) {
            prof++;
            p = p->parent;
        }
        return prof;
    }
    int l = altezza_albero_b_3(n->left);
    int r = altezza_albero_b_3(n->right);
    if( l > r) return l;
    return r;
}


int somma_albero_b(nodo* n) {
    if( n == NULL) return 0;
    return n->info + somma_albero_b(n->left) + somma_albero_b(n->right);
}

float media_albero_b(nodo* n) {

   if ( n == NULL) {
       printf("Errore: funzione media_albero_b() lanciata su un albero vuoto\n");
       exit(1);
   }
   int c = conta_nodi_albero_b(n);
   int s = somma_albero_b(n);
   return (float)s/(float)c;
}

void media_albero_b_2_ricorri(nodo* n, int* pc, int* ps) {
    if( n == NULL) return;
    (*pc) = (*pc) + 1;
    (*ps) = (*ps) + n->info;
    media_albero_b_2_ricorri(n->left, pc, ps);
    media_albero_b_2_ricorri(n->right, pc, ps);
}

float media_albero_b_2(nodo* n) {
   int c = 0, s = 0;
      if ( n == NULL) {
       printf("Errore: funzione media_albero_b() lanciata su un albero vuoto\n");
       exit(1);
   }
   media_albero_b_2_ricorri(n, &c, &s);
   return (float)s/(float)c;
}

/* riporta l'altezza dell'albero completo radicato ad n
   oppure -2 se l'albero radicato ad n non e' completo */

int completo_albero_b_ricorri(nodo* n) {

    if( n == NULL) return -1;
    int l = completo_albero_b_ricorri(n->left);
    int r = completo_albero_b_ricorri(n->right);
    if ( l == -2 || r == -2 )  {  // se uno dei due figli non e' completo
        return -2;                // allora io non sono completo
    }
    // se arrivi qui entrambi i figli sono alberi completi
    if( l == r ) {   // se hanno la stessa altezza
        return l+1;  // ritorno l'altezza +1
    } else {
        return -2;   // segnalo al mio genitore che io non sono un albero completo
    }
}


int completo_albero_b(nodo* n) {
    /*
    if( completo_albero_b_ricorri(n) != -2 )
        return 1;
    else
        return 0;
    */
    return completo_albero_b_ricorri(n) != -2;
}

void dealloca_albero_b(nodo** n) {

   if (*n == NULL) return;
   dealloca_albero_b( &((*n)->left) );
   dealloca_albero_b( &((*n)->right) );
   // ora il nodo (*n) ha (*n)->left == NULL e (*n)->right == NULL
   free(*n);
   (*n) = NULL; // cosi' chi mi ha lanciato si ritrova col puntatore = NULL
}

void parentetica_simmetrica(nodo* n) {
    if( n == NULL ) {
        //printf("()");
        return;
    }
    printf("(");
    parentetica_simmetrica(n->left);
    printf("%d",n->info);
    parentetica_simmetrica(n->right);
    printf(")");    
}

void parentetica_preordine(nodo* n) {
    if( n == NULL ) {
        printf("()");
        return;
    }
    printf("(");
    printf("%d",n->info);
    parentetica_preordine(n->left);
    parentetica_preordine(n->right);
    printf(")");    
}

void stampa_outline_ricorri(nodo* n, int prof) {
    if( n == NULL ) return;
    int i;
    for(i = 0; i < prof; i++){
        printf("  ");
    }
    printf("%d\n",n->info);
    stampa_outline_ricorri(n->right,prof+1);
    stampa_outline_ricorri(n->left,prof+1);
}

void stampa_outline(nodo* n) {
    stampa_outline_ricorri(n, 0);
}

int ho_due_figli(nodo* n) {
    if( n == NULL ) return 0;
    return n->left != NULL && n->right != NULL;
}


int due_figli_albero_b(nodo* n) {

    if( n == NULL ) return 0;
    int l = due_figli_albero_b(n->left);
    int r = due_figli_albero_b(n->right);
    if( ho_due_figli(n) ) {
        return 1 + l + r;
    } else {
        return l + r;
    }
    // equivalentemente "return ho_due_figli(n) + l + r;"
}

int sono_una_foglia(nodo* n) {
    if( n == NULL ) return 0;
    return n->left == NULL && n->right == NULL;
}

int conta_foglie_albero_b(nodo* n) {

    if( n == NULL ) return 0;
    int l = conta_foglie_albero_b(n->left);
    int r = conta_foglie_albero_b(n->right);
    if( sono_una_foglia(n) ) {
        return 1 + l + r;
    } else {
        return l + r;
    }
    // equivalentemente "return ho_due_figli(n) + l + r;"
}

item* calcola_lista_da_root_a(nodo* n) {

    if( n == NULL ) return NULL;
    item* l = (item*)malloc(sizeof(item));   // alloco un elemento della lista
    l->info = n->info;
    l->next = NULL;

    while (n->parent != NULL) {
        n = n->parent;
        insert_lista_s(&l, n->info);
    }
    return l;
}

/* Assumiamo che l'albero abbia tutti i nodi con diversi
   valori del campo info. Se non fosse cosi' avrei bisogno
   di liste di nodi e non di liste di interi */

int parentela_albero_b(nodo* n1, nodo* n2){

    item* l1 = calcola_lista_da_root_a(n1);
    item* l2 = calcola_lista_da_root_a(n2);
    while (l1->info == l2->info) {
         item* temp = l1;
         l1 = l1->next;
         free(temp);
         temp = l2;
         l2 = l2->next;
         free(temp);
    }
    int lunghezza1 = lunghezza_lista_s(l1);
    int lunghezza2 = lunghezza_lista_s(l2);
    dealloca_lista_s(&l1);
    dealloca_lista_s(&l2);

    return lunghezza1+lunghezza2;
}