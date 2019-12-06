#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct fila Fila;
// typedef char type;
typedef int type;

struct fila {
  type *v;
  int ini;
  int fim;
};
Fila *criaFila() {
  int size = N;
  Fila *q;
  q = (Fila *)malloc(sizeof(Fila));
  q->v = (type *)malloc(size * sizeof(type));
  q->ini = N / 2;
  q->fim = N / 2;
  return q;
}
void insereFila(Fila *q, type x) {
  q->v[q->fim++] = x;
  // (q->fim)++;
  // if (q->fim == N)
  // q->fim = 0;
  q->fim = (q->fim) % N;
}
type removeFila(Fila *q) {
  type x;
  x = q->v[q->ini++];
  // (q->ini)++;
  // if (q->ini == N)
  // q->ini = 0;
  q->ini = (q->ini) % N;
  return x;
}
int filaVazia(Fila *q) { 
  return q->fim == q->ini; 
}
int filaCheia(Fila *q) {
  // return (q->fim + 1 == q->ini || (q->fim + 1 == N && q->ini == 0));
  return (q->fim + 1) % N == q->ini;
}
void imprimeFila(Fila *q) {
  int i;
  if (q->ini <= q->fim)
    for (i = q->ini; i < q->fim; i++)
      printf("%c ", q->v[i]);
  else // q->fim < q->ini
  {
    for (i = q->ini; i < N; i++)
      printf("%c ", q->v[i]);
    for (i = 0; i < q->fim; i++)
      printf("%c ", q->v[i]);
  }
  printf("\n");
}
int tamFila(Fila *q) {
  if (q->ini <= q->fim)
    return q->fim - q->ini;
  return (N - q->ini) + (q->fim - 0);
}
Fila *liberaFila(Fila *q) {
  free(q->v);
  free(q);
  return NULL;
}