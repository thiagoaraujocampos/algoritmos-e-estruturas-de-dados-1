// Thiago Araujo Campos 
// 769850
// Engenharia de Computação

#include <stdio.h>
#include <stdlib.h>

int mutacao(int v[], int n) {
  int i, j, aux, cont = 0;
  for (j = 1; j < n; j++) {
    aux = v[j];
    for (i = j - 1; i >= 0 && aux < v[i]; i--) {
      v[i + 1] = v[i];
      cont++;
    }
    v[i + 1] = aux; 
  }
  return cont;
}

int main(void) {
  int n;
  scanf("%d", &n);
  int genoma[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &genoma[i]);
  }
  printf("%d\n", mutacao(genoma, n));
  return 0;
}
