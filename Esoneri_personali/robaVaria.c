


/* Struttura dati a cui fare riferimento*/
typedef struct lis {
    struct lis* prev;
    struct lis* next;
    int info;
} litem;

//questa funzione verifica se la lista passata come
//parametro é crescente
int is_crescente(list* p){
    int out=1;  //verificata
    litem* l = p->head;

    if(l==NULL) return 0;
    while(l!=NULL){
        if(l->info >= l->next->info) {  
            out=0;
        }
    l=l->next;
    }
    return out;


    //Conta quanti nodi di un albero binario hanno campo info uguale alla
    // distanza del nodo dalla radice

int distanza(nodo* n, int d){
    if(n == NULL) return 0;
    int count = 0;
    if(n->info == d) count ++;
    return count + distanza(n->right, d+1) + distanza(n->left, d+1);
}

int verifica(nodo* n) {
    return quanti_info_pari_lunghezza_radice_ric(n, 0);
}

//Confronta primo e ultimo elemento lista
int uguali(list* p) {
    litem* lista=p->head;
    if(lista==NULL) return 0;
    int first=lista->info;
    while(lista->next->next!=NULL){
        lista=lista->next;
        int last=lista->next+->info;  
        }
        if(first==last) return 1;
        return 0;
    }

//Conta i nodi che hanno figli foglie
int is_foglia (node* n) {
    if(n==NULL) return 0;
    if(n->sx==NULL && n->dx==NULL) return 1;
    return 0;
}

int conta_nodi_figli_foglia(nodo* n){
    if(n==NULL) return 0;
    int out=0;
    if(is_foglia(n->left) && is_foglia(n->right)) out++;
    return out+conta_nodi_figli_foglia(n->left) + conta_nodi_figli_foglia(n->right);
}


//Controlla se tutti i nodi hanno campo info uguale all’altezza del nodo
//
//ATTENZIONE
int verifica(nodo* n, int p) {
    if(n==NULL) return 0;
    int out=1;
    if(n->info!=p) out=0; 
    return out && verifica(n->left,p+1) && verifica(n->right,p+1);
}
int altezza(nodo* n){
    if(n==NULL) return -1;
    int l=altezza(n->left);
    int r=altezza(n->right);
    if(l>r) return l+1;
    return r+1;
}

int verifica(nodo* n, int h ) {
    if(n==NULL) return 0;
    int out=1;
    if(n->info!=h) out=0; 
    return out && verifica(n->left,h) && verifica(n->right,h);
}

int verifica_ric(nodo*n){
    int h = altezza(n);
    return verifica(n,h);
}