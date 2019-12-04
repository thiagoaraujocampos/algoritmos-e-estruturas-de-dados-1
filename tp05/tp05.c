// Thiago Araujo Campos
// Engenharia de Computação
// 769850


#include <stdio.h>
#include <stdlib.h>

int cont = 0;

// Verifica se a posição que passou por parâmentro pode ter uma rainha
int verifica(int **m, int col, int row, int n) {
  int i, j;
  // Verifica linha esquerda
  for (i = 0; i < col; i++)
    if (m[row][i])
      return 0;

  // Verifica diagonal superior esquerda
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (m[i][j])
      return 0;

  // Verifica diagonal inferior esquerda
  for (i = row, j = col; j >= 0 && i < n; i++, j--)
    if (m[i][j])
      return 0;

  return 1;
}

// Resolve o problema recursivamente
void resolveRainha(int **m, int col, int n) {
  // Caso base (quando a coluna chegar em N então acabou as colunas para verificar)
  if(col == n) {
    cont++; // Contador para verificar qnt de soluções
    return ;
  }
  // For para percorrer as N linhas de uma coluna
  for (int i = 0; i < n; i++) {    
    if (verifica(m, col, i, n)) {
      m[i][col] = 1; // Coloca uma rainha em m[i][col]
      // Recursão para próxima coluna
      resolveRainha(m, col+1, n);
      m[i][col] = 0; // Um backtracking removendo a queen da posição m[i][col]
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  // Aloca a matriz dinamicamente.
  int **m;
  m = (int **) malloc(n * sizeof(int *));
  for (int j = 0; j < n; j++)
    m[j] = (int *) malloc(n * sizeof(int));

  // Zera todas as posições da matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i][j] = 0;
    }
  }

  resolveRainha(m, 0, n);
  printf("%d\n", cont);

  // libera a matriz
  for (int i = 0; i < n; i++)
    free(m[i]);
  free(m);
  return 0;
}