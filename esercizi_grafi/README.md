
# Per compilare:

- gcc main.c grafo_liste.c grafo_matrice.c grafo_oggetti.c lista_d.c -o NomeEseguibile




Per scorrere un grafo si marcano i nodi di 1/0 o colore per non ciclare all'infinito.
Prima si "svuota" il grafo facendo una passata di tutti i nodi e marcandoli di 0(nel caso ci fosse qualche 1).

Se voglio scorrere la lista dei nodi:

x = g.nodi
while x!=NULL
  x.info.color == 0 
  x=x.next


# BFS (Breadth first search) - vista in ampiezza

Prima si visitano i nodi vicino, poi man mano quelli piu lontani.
I nodi raggiunti vengono marcati e messi in coda(marcandoli)

# DFS (Depth first search) - vista in profondità

Si percorre il grafo fino a che si trovano nodi non visitati
Una volta visitati tutti i vicino, si torna indietro verso nodo iniziale per verificare che non ci siano nodi adiacenti non visitati.

//resetto il flag di tutti nodi
DFS(g,v)
 for i=0 to g.A.length-1
  color[i] = 0
DFS_visit(g,v,color)

DFS_visit(g,i,color)
 color[i] = 1;
 x=g.A.[i]
 while(x!=NULL)
  v = x.key      //v è l'indice di un nodo adiacente ad i
  if color[v] == 0
    DFS_visit(g,v,color)
  x=x.next

# per un crafo non necessariamente connesso

DFS_non_connesso(g)
 for i=0 to g.A.length-1
   color[i]=0
 for i=0 to g.A.length-1
   if color[i] == 0
     DFS_visit(g,i,color)