#include <stdio.h>
#include <stdlib.h>

#define WATER 0
#define LAND 1

#define MAX_COLS 1024

void *malloc_safe(unsigned nbytes)
{
    void *p;
    p = malloc(nbytes);
    if (p == NULL)
    {
    printf("Nao foi possível alocar!\n");
	exit(EXIT_FAILURE);
    }
    return p;
}


int** create_matrix(int n_rows, int n_cols){
    int** m = NULL;
    m = malloc_safe(n_rows*(sizeof(int*)));
    for (int i = 0; i < n_rows; ++i)
	m[i] = malloc_safe(n_cols*sizeof(int));
    return m;
}



void destroy_matrix(int **m, int n_rows){
    for (int i = 0; i < n_rows; ++i) {
	free(m[i]);
    }
    free(m);
}


void read_input(int* m[], int *n_rows, int *n_cols){
    char line[MAX_COLS];
    for (int i = 0; i < *n_rows; ++i) {
	fgets(line, MAX_COLS, stdin);
	for (int j = 0; j < *n_cols; ++j) {
	    if(line[j] == '0')
		m[i][j] = WATER;
	    else if(line[j] == '1')
		m[i][j] = LAND;
	    else{
		printf("Wrong char in buffer\n");
		printf("%s\n", line);
		exit(EXIT_FAILURE);
	    }
	}
    }
}


void print_matrix(int m[][MAX_COLS], int n_rows, int n_cols){
    printf("Print %d x %d matrix\n", n_rows, n_cols);
    for (int i = 0; i < n_rows; ++i) {
	for (int j = 0; j < n_cols; ++j) {
	    printf("%d", m[i][j]);
	}
	printf("\n");
    }
    printf("\n");
}

int verifica_ilha(int **m, int **visitada, int row, int col, int n_rows, int n_cols)
{
    int cont = 1;
    visitada[row][col] = 1;

    if (col != 0 && m[row][col - 1] == 1 && visitada[row][col - 1] != 1) // Olha esquerda
    {
        cont += verifica_ilha(m, visitada, row, col-1, n_rows, n_cols);
    }
    if (col != (n_cols-1) && m[row][col + 1] == 1 && visitada[row][col + 1] != 1) // Olha direita
    {
        cont += verifica_ilha(m, visitada, row, col+1, n_rows, n_cols);
    }
    if (row != (n_rows-1) && m[row + 1][col] == 1 && visitada[row + 1][col] != 1) // Olha baixo
    {
        cont += verifica_ilha(m, visitada, row+1, col, n_rows, n_cols);
    }
    if (row != 0 && m[row - 1][col] == 1 && visitada[row - 1][col] != 1) // Olha cima
    {
        cont += verifica_ilha(m, visitada, row-1, col, n_rows, n_cols);
    }

    return cont;
}

int search_max_area(int **m, int n_rows, int n_cols)
{
    int maior = 0, ver_ilha;
    int **visitada = create_matrix(n_rows, n_cols);
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (m[i][j] == 1 && visitada[i][j] != 1)
            {
                ver_ilha = verifica_ilha(m, visitada, i, j, n_rows, n_cols);
                if (ver_ilha > maior)
                {
                    maior = ver_ilha;
                }
            }
        }
    }
    return maior;
}


int main(void){
    int n_rows = 0, n_cols = 0;
    scanf("%d %d\n", &n_rows, &n_cols);
    int **m = create_matrix(n_rows, n_cols);
    read_input(m, &n_rows, &n_cols);
    int area = search_max_area(m, n_rows, n_cols);
    printf("%d", area);
    /*Função para desalocar a matriz.*/
    destroy_matrix(m, n_rows);    
    return 0;
}
