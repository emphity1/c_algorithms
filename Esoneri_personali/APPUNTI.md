


# Altezza dell'albero != altezza nodo-radice

- Vista pre-ordine
  Processo nodo poi i suoi figli
- Vista post-ordine
  Processo prima i figli poi il nodo

Se albero binario:
- Vista simmetrica
  Figlio sx, nodo, figlio dx


# Codici base

Cerca_Preordine(n,v)
  if n==null
    return 0
  if n.info == v
    return 1
  l = Cerca_Preordine(n.left,v)
  r = Cerca_Preordine(n.right,v)
  return l or |

Cerca_Postordine(n,v)
  if n==null
    return 0
  if Cerca_Postordine(n.left,v)
    return 1
  if Cerca_Postordine(n.right,v)
    return 1
  return n.info == v


Ricerca_Simmetrica(n,v)
  if n==null
    return 0
  if Ricerca_Simmetrica(n.left,v)
    return 1
  if n.info == v
    return 1
  return Ricerca_Simmetrica(n.right,v)


  # ABR #
  
  - Valori a sx di X sono minori di X, quelli a destra di X sono maggiori di X stesso

  Per trovare val minimo o massimo di un ABR scendo in fondo a SX o DX

  while(x.left != NULL)
    x = x.left
  return x


 Per Trovare un nodo con campo info k:

 rec_tree_search(x,k)
   if (x==NULL) || (k==x.key)
     return x
  if(k < x.key)
    return  rec_tree_search(x.left,k)
  else
    return  rec_tree_search(x.right, k)
