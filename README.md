# Algoritmos e Estruturas de Dados 1

Foram desenvolvidos, em C, os seguintes projetos:

  * TP01: **Recursão**
  * TP02: **O Problema de Josephus**
  * TP03: **Ganhando uma Ilha**
  * TP04: **Distância Genômica**
  * TP05: **N-Rainhas**


 -> Conteúdo P2
 
   * Fila (Prioridade)
   * Algoritmos de Ordenação (Bubble, Selection, Insertion e Heapsort)
   * Árvores (Heap e Busca)
   * Enumeração (Subconjunto, Subsequência e Permutação)
   * Backtracking 

 -> Fila

 Uma fila é uma sequência de dados dinâmica. Ou seja, é uma sequência que permite operações de inserção e remoção, assim como listas e pilhas. No entanto, em uma fila, a inserção e a remoção ocorrem nos extremos opostos da sequência.

**FIFO** (first-in, first_out).

  * Pode ser implementada em vetor ou em uma lista.

- Utilizando vetor

Uma fila **q** é armazenada em um vetor de tamanho **n**, que pode ser alocado estática ou dinamicamente.

```c++
struct fila
{
  char *v;
  int ini; // Posição do próximo a ser removido
  int fim; // Posição que é possível a próxima inserção
};
```

(fim - ini) = número de elementos presentes na fila.

_Inserção_
```c++
q[fim++] = x;
// Semelhante a q[fim] = x; fim = fim + 1;
```

_Remoção_
```c++
x = q[ini++];
// Semelhante a x = q[ini]; ini = ini + 1;
```

Assim, tanto a inserção como a remoção podem ser feitas em O(1) - tempo constante.



- Implementação circular de fila em vetor

![Fila circular](https://www.researchgate.net/profile/Renan_Ferreira3/publication/277151084/figure/fig19/AS:391833613029382@1470431821526/Figura-319-Fila-Circular-No-sistema-de-comunicacao-utilizado-Max-20.png)

_Inserção_
```c++
q[fim++] = c;
fim = fim % n; //if(fim == n) fim = 0;
```

_Remoção_
```c++
x = q[ini++];
ini = ini % n;
```

_Fila vazia_
```c++
ini == fim;
```

_Fila cheia_
```c++
(fim + 1) % n == ini
```

_Tamanho da fila_
```c++
if(fim >= ini) 
  tam = fim - ini
else
  tam = (n-ini) + fim;
```

 - Implementação de fila em lista encadeada

  Como fila é **FIFO** é interessante manter o ponteiro para a primeira célula da fila e outro para a última.

  * código na pasta _conteúdo_ (é basicamente uma fila mesmo)

  - Implementação para o problema das distâncias

```c++
int *distancias(int **A, int n, int x)
{
  int i, y;
  int *dist;
  int *q;
  int ini, fim;
  dist = malloc(n * sizeof(int));
  /* inicializa a fila */
  q = malloc(n * sizeof(int));
  ini = 0;
  fim = 0;
  /* inicializa todos como não encontrados, exceto pelo x */
  for (i = 0; i < n; i++)
    dist[i] = -1;
  dist[x] = 0;
  /* colocando x na fila */
  q[fim++] = x;
  /* enquanto a fila dos ativos (encontrados mas não visitados) não estiver vazia */
  while (fim != ini)
  {
    /* remova o mais antigo da fila */
    y = q[ini++];
    /* para cada vizinho deste que ainda não foi encontrado */
    for (i = 0; i < n; i++)
      if (A[y][i] == 1 && dist[i] == -1)
      {
        /* calcule a distância do vizinho e o coloque na fila */
        dist[i] = dist[y] + 1;
        q[fim++] = i;
      }
    }
  free(q);
  return dist;
}
```
Análise:

- Matriz de adjacência
  Para representar uma rede de n vértices: O(n²)

  * Facilidade em saber se dois vértices são vizinhos
  * Desperdicio de memória
  * O(n) para olhar todos vizinhos mesmo com poucos

- Lista de adjacência

Alternativa para matriz de adjacência. Cria-se um vetor (ou lista) para cada vértice e à cada vértice associa-se uma lista de seus vizinhos.

 * Economia de memória quando a rede é esparsa (O(n+m))
   n - número de nós e m - número de conexões
 * Tempo para visitar todos nós é proporcional ao número de vizinhos i.
 * Em redes densas o uso de memória e número de operações é quadrático 
 * Maior uso de memória para cada conexão (comparando com a matriz de adjacência)
 * É necessário percorrer todas as lista quando precisamos verificar quais nós possuem conexão para um nó j


 - Filas de prioridade

 Filas de prioridade são um tipo abstrato de dados em que cada elemento está associado a um valor que indica sua prioridade. (generaliza tanto filas quanto pilhas)

  * Pode ser de máximo ou de mínimo
  * Máximo: O elemento com maior prioridade é o que possui um valor mais alto de prioridade
  * Mínimo: O elemento com menor prioridade é o que possui um valor mais alto de prioridade

Operações: 

  * Inserção de um elemento com um certo valor de prioridade
  * Edição de prioridade de um elemento (pouco comum)
  * Remoção de elemento com maior (ou menor) prioridade.

> Utilizando fila em vetor

_Remoção_
```c++
x = q[ini++]
```
_Inserção_
```c++
for (int i = fim - 1; i >= ini && v[i] < x; i--)
  v[i + 1] = v[i];
v[i + 1] = x;
fim++;
```
Na inserção é necessário encontrar a posição correta do elemento e deslocar os elementos com prioridade mais baixa.
O(n) no pior caso.

-> Árvores e árvores binárias

  * Para cada ligação (aresta) da árvore (i,j):
    * O nó i é dito pai do nó j.
    * O nó j é dito filho do nó i.
  * A raiz de uma árvore é o único nó que não é filho do outro.
  * Uma folha (ou nó terminal) é um nó que não possui filhos
  * A altura de uma árvore é definida como o maior caminho da raiz até uma folha.
  * Uma árvore M-ária é uma que todos possuem M filhos, com exceção das folhas.

**Árvores binárias**

  * M = 2: possúi dois filhos (um da esquerda e um da direita) ou é uma árvore vazia.

  ![Arvore bin](https://i.imgur.com/bZHAvGw.png)

Na representação de árvore binária cada nó é uma estrutura com:

  * Um conteúdo;
  * Um apontador para o filho da esquerda;
  * Um apontador para o filho da direita;
  * Um apontador para o pai (opcional).

- Implementação:

```c++
// Registro
typedef int type;

typedef struct noh
{
  type conteudo;
  struct noh *pai; // opcional
  struct noh *esq;
  struct noh *dir;
} Noh;

typedef Noh *Arvore;
```

Operações elementares

  * Inserir nó folha
  * Romover nó folha
  * Combinar duas árvores L e R

_Inserção de um nó folha_
```c++
Arvore insere(Arvore T, Noh* node, type cont, int left){
  Noh* newNode = criaNoh(cont);
  if (node == NULL)
    return newNode;
  if (left)
    node->esq = newNode;
  else
    node->dir = newNode;
  return T;
}
```

_Altura de uma árvore_
```c++
int altura(Arvore r)
{
  int hesq, hdir;
  if (r == NULL)
    return -1;
  hesq = altura(r->esq);
  hdir = altura(r->dir);
  if (hesq > hdir)
    return hesq + 1;
  return hdir + 1;
}
```

- Percursos em árvore

  * Percurso em pré-ordem (r-e-d)

    1. Nó raiz
    2. Subárvore da esquerda
    3. Subárvore da direita

  ```c++
  void preOrdem(Arvore r)
  {
    if(r != NULL)
    {
      printf("%d\n", r->conteudo);
      preOrdem(r->esq);
      preOrdem(r->dir);
    }
  }
  ```

  * Percurso em ordem (e-r-d)

    1. Subárvore da esquerda
    2. Nó raiz
    3. Subárvore da direita
  
  ```c++
  void emOrdemR(Arvore r)
  {
    if (r != NULL)
    { 
      emOrdemR(r->esq);
      printf("%d ", r->conteudo);
      emOrdemR(r->dir);
    }
  }
  ```

  * Percurso em pós-ordem (e-d-r)

    1. Subárvore da esquerda
    2. Subárvore da direita
    3. Nó raiz

  ```c++
  void posOrdem(Arvore r)
  {
    if (r != NULL)
    { 
      posOrdem(r->esq);
      posOrdem(r->dir);
      printf("%d ", r->conteudo);
    }
  }
  ```

-> Implementação de uma fila de prioridade utilizando _heap_

  Uma heap de máximo é uma árvore binária completa (ou quase-completa) cujos nós respeitam a seguinte propriedade

  > O valor da prioridade de um nó não é menor do que a prioridade de seus filhos
  
    Um ávore binária completa possui 2^p em cada nível p. 
    Uma árvore binária com h níveis possui m = 2^(h+1) - 1 nós

  Cada posição i (vetor) corresponde ao nó i da heap de forma que a raiz seja o nó i = 0 e:
    
     * O filho da esquerda está na pos 2i + 1
     * O filho da direita está na pos 2i + 2

     ```c++
    #define PAI(i) ((i - 1) / 2)
    #define FILHO_ESQ(i) (2 * i + 1)
    #define FILHO_DIR(i) (2 * i + 2)
     ```

    * Se o FILHO_ESQ(i) ≥ m, então i não possui filho esquerdo.
    * Se o FILHO_DIR(i) ≥ m, então i não possui filho direito.

  o número de níveis de uma heap com m elementos é ⌊log(m)⌋

  > Note que é possível, usando o mesmo raciocínio, encontrar o nível de um índice i qualquer no vetor fazendo ⌊log(i + 1)⌋

**Operações sobre heap**

- Sobe heap O(log(m))
  
  * Utilizada para inserir um novo elemento em uma heap (também pode construir uma heap a partir de um vetor)

  * O elemento é adicionado na primeira posição vazia do vetor m e então aplica-se o Sobe heap para encontrar posição correta do elemento.

  ```c++
  void sobeHeap(int v[], int m)
  {
    int f = m;
    while (f > 0 && v[PAI(f)] < v[f])
    {
      troca(&v[f], &[PAI(f)]);
      f = PAI(f);
    }
  }
  ```
  ```c++
  int insereHeap(int v[], int m, int x)
  {
    v[m] = x;
    sobeHeap(v, m);
    return m + 1;
  }
  ```

- Desce heap O(log(m))

  * Utilizada para remover o elemento de maior prioridade em uma heap de máximo

  ```c++
  void desceHeap(int v[], int m, int k)
  {
    int p = k, f;
    while (FILHO_ESQ(p) < m && (v[FILHO_ESQ(p)] > v[p] || (FILHO_DIR(p) < m && v[FILHO_DIR(p)] > v[p])))
    {
      f = FILHO_ESQ(p); // Existe?
      if (FILHO_DIR(p) < m && [FILHO_DIR(p)] > v[f])
        f = FILHO_DIR(p);
      troca(&v[p], &v[f]);
      p = f;
    }
  }
  ```

  ```c++
  int removeHeap(int v[], int m, int *x)
  {
    *x = v[0];
    troca(&v[0], &v[m - 1]);
    desceHeap(v, m, 0);
    return m - 1;
  }
  ```

  
-> Algoritmos de ordenação

  **Insertion sort** O(n²)

  * Varre o vetor do início ao fim e, a cada novo elemento encontrado, o coloca na posição correta.

  ```c++
  void insertionSort(int v[], int n)
  {
    int i, j, aux;
    for(j = 1; j < n; j++)
    {
      aux = v[j];
      for (i = j - 1; i >= 0 && aux < v[i]; i--)
        v[i + i] = v[i];
      v[i + 1] = aux;
    }
  }
  ```
    * obs: no início de cada operação do laço o vetor v[0,...,j-1] está ordenado

  **Melhorando o Insertion sort**

  * Uma forma de melhorar é usar um valor de sentinela para v[0] de forma que a condição i>=0 não seja necessária.

  ```c++
  void insertionSort(int v[], int n)
  {
    int i, j, aux;
    for (i = n-2; i >= 0 && v[i] > v[i+1]; --i)
    {
      aux = v[i];
      v[i] = v[i+1];
      v[i+1] = aux;
    }
    for (j = 1; j < n; j++)
    {
      aux = v[j];
        for (i = j - 1; aux < v[i]; i--)
          v[i + 1] = v[i];
        v[i + 1] = aux; 
    }
  }
  ```

  **Bubble sort** O(n²)

  * Varre o vetor diversas vezes, invertendo os elementos vizinhos fora de ordem (troca)

  ```c++
  void bubbleSort1(int v[], int n)
  {
    int i, aux, mudou = 1;
    while (mudou == 1)
    {
      mudou = 0;
      for (i = 1; i < n; i++)
        if (v[i - 1] > v[i])
        {
          aux = v[i - 1];
          v[i - 1] = v[i];
          v[i] = aux;
          mudou = 1;
       }
    }
  }

  void bubbleSort2(int v[], int n)
  {
    int j, i, aux;
    for (j = 0; j < n; j++)
      for (i = 1; i < n; i++)
        if (v[i - 1] > v[i])
        {
          aux = v[i - 1];
          v[i - 1] = v[i];
          v[i] = aux;
        }
  }
  ```

  **Melhorando o Insertion sort**

  ```c++
  void bubbleSort(v[], int n)
  {
    int j, i, aux, ut, l;
    l = n;
    for (j = 0; j < n; j++)
    {
      ut = 0;
      for (i = 1; i < l; i++)
        if (v[i - 1] > v[i])
        {
          aux = v[i - 1];
          v[i - 1] = v[i];
          v[i] = aux;
          ut = i; 
        }
      l = ut;
    }
  }
  ```

  **Selection sort** O(n²)

  * Varre o vetor do início ao fim, buscando o menor valor do subvetor que ainda não está ordenado e coloca-o na posição corrente.

  ```c++
  void selectionSort(int v[], int n)
  {
    int i, j, ind_min, aux;
    for (i = 0; i < n - 1; i++)
    {
      ind_min = i;
      for (j = i + 1; j < n; j++)
        if (v[j] < v[ind_min])
          ind_min = j;
        aux = v[i];
        v[i] = v[ind_min];
        v[ind_min] = aux;
    }
  }
  ```
    * obs: no início de cada iteração o vetor v[0,...,i-1] está ordenado.

  **Heapsort** O(n*logn)

  * A ideia do algoritmo de ordenação por seleção eficiente (heapsort) surge da união da ordenação por seleção e da estrutura de dados heap.

  ```c++
  void heapsort1(int v[], int n)
  {
    int i, m = n;
    for (i = 1; i < n; i++) // Constroi heap
      sobreHeap(v, i);
    for (m = n - 1; m > 0; m--)
    {
      troca(&v[0], &v[m]); // Coloca máximo no final
      desceHeap(v, m, 0); // Restaurando o heap
    }
  }
  ```

  - _Heapify_ O(m)

    * A operação heapify é interessante na manipulação de heaps, transformando um vetor de tamanho m em um heap em O(m) operações.

  ```c++
  for (i = m / 2 - 1; i >= 0; i--)
    desceHeap(v, m, i);
  ```
  
  Usando essa ideia para melhora o Heapsort:

  ```c++
  // O(nlogn)
  void heapsort2(int v[], int n)
  {
    int i, m = n;
    for (i = n / 2; i >= 0; i--) // construindo o Heap em tempo O(n)
      desceHeap(v, n, i);
    for (m = n - 1; m > 0; m--)
    {
      troca(&v[0], &v[m]); // colocando o máximo no final
      desceHeap(v, m, 0); // restaurando o Heap
    }
  }
  ```

  -> Problemas da seleção e contagem de inversões

  TRABALHO GENOMA

  -> Tabela de Simbolos

  ```c++
  int buscaBinaria(Item v[], int n, Chave x)
  {
    int e, m, d;
    e = -1;
    d = n;
    while (e < d - 1)
    {
      m = (e + d) / 2;
      if (v[m].chave < x)
        e = m;
      else 
        d = m;
    }
    return d;
  }

  int *busca(int v[], int n, int x)
  {
    int i;
    i = buscaBinaria(v, n, x);
    if (v[i] == x)
      return &v[i];
    return NULL;
  }
  ```

-> Árvore binária de busca

  ![Arvore bin busca](https://i.imgur.com/IuPzb9U.png)

  * Seja x uma chave associada a um nó de uma árvore binária. Uma árvore binária de busca é uma árvore binária em que os elementos da subárvore de esquerda possuem chave menor ou igual a x e os elementos da subárvore da direita possuem elementos maiores que x.

  _Resumo das operações em tabela de símbolos_
  ![tabela](https://i.imgur.com/o4lJPkX.png)

-> Enumeração, permutações e subconjuntos

  * Para a solução de certos problemas combinatórios é necessário enumerar explicitamente todos os objetos de um determinado tipo. Em geral, o número de objetos a serem enumerados é muito grande. Mas, certas vezes, é o melhor a fazer, ou, ao menos, serve como ponto de partida.