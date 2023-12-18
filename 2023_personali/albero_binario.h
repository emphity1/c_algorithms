#ifndef _ALBERO_BINARIO_H
#define _ALBERO_BINARIO_H

typedef struct nodo_struct {

	struct nodo_struct* parent;
	struct nodo_struct* left;
	struct nodo_struct* right;
	int info;

} nodo_albero;

typedef nodo_albero* albero; //cosi uso albero anzichè nodo_albero*

// per creare un albero vuoto: albero mio_albero = NULL;
// per creare un albero vuoto: nodo_albero* mio_albero = NULL;
// per creare un albero vuoto: struct nodo_struct* mio_albero = NULL;

nodo_albero* aggiungi_figlio_sinistro(nodo_albero* n, int value);
nodo_albero* aggiungi_figlio_destro(nodo_albero* n, int value);

//int cerca_preordine(albero a, int v);
//int cerca_postordine(albero a, int v);
//void stampa_figli(albero a);
//int cerca_nodo(albero a, int v );
//int* cammino_abr(albero a,int v);
//void stampa(albero a); //dueNodiuguali.c

//void verificaFoglie(albero a, int v); //contaEverificaFoglie.c

//int albero_altezza_foglie(albero a);
//void somma_conta_nodi(albero a);
//void stampa(albero a,int v);

//void verifica(albero a);

//void stampa(albero a); //esisteFoglia destra

//discendenti luglio 2022 B
//void stampaDisc(albero a); //discendenti

//eser.c
//void stampaNodi_figlioSolo(albero a);


//distanzaNodo.c
//void verifica(albero a); 
//void stampa_nodi_trovati(albero a);

//void verifica_profondita(albero a, int v);


//void cerca_nodi_figlio_solo(albero a,int v); //cerca_figli.c

//void verifica_test1(albero a);


void info_altezza(albero a); //esame-15-02-2023.c

#endif