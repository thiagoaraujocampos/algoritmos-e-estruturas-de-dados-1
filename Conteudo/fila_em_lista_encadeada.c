#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct celula {
  type conteudo;
  struct celula *prox;
} Celula;

typedef struct fila Fila;
struct fila {
  Celula *ini;
  Celula *fim;
  int tam; // Armazenando o número de elementos.
};

Fila *criaFila() {
  Fila *q;
  q = (Fila *)malloc(sizeof(Fila));
  q->ini = NULL;
  q->fim = NULL;
  q->tam = 0;
  return q;
}
void insereFila(Fila *q, type x) {
  Celula *nova;
  nova = (Celula *)malloc(sizeof(Celula));
  nova->conteudo = x;
  nova->prox = NULL;
  if (q->fim == NULL) // fila vazia
  {
    q->ini = nova;
    q->fim = nova;
  } else {
    q->fim->prox = nova;
    q->fim = nova;
  }
  (q->tam)++;
}
type removeFila(Fila *q) {
  type x;
  Celula *morta;
  morta = q->ini;
  x = morta->conteudo;
  q->ini = morta->prox;
  if (q->ini == NULL) // fila ficou vazia
    q->fim = NULL;
  free(morta);
  (q->tam)--;
  return x;
}
int filaVazia(Fila *q) { return q->fim == NULL; }
int filaCheia(Fila *q) {
  Celula *p;
  p = malloc(sizeof(Celula));
  if (p == NULL)
    return 1;
  free(p);
  return 0;
}
void imprimeFila(Fila *q) {
  Celula *p;
  p = q->ini;
  while (p != NULL) {
    printf("%c ", p->conteudo);
    p = p->prox;
  }
  printf("\n");
}
int tamFila(Fila *q) {
  // Celula *p;
  // int tam = 0;
  // p = q->ini;
  // while (p != NULL)
  // {
  // tam++;
  // p = p->prox;
  // }
  // return tam;
  return q->tam;
}
Fila *liberaFila(Fila *q) {
  Celula *p, *morta;
  p = q->ini;
  while (p != NULL) {
    morta = p;
    p = p->prox;
    free(morta);
  }
  free(q);
  return NULL;
}