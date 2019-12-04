// Thiago Araujo Campos
// 769850

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa
{
    int posicao;
    Pessoa *prox;
};

Pessoa *inicio = NULL;

void insereLista(int x)
{                                // Cria um auxiliar para percorrer a lista
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa)); // Criando o novo espaço da lista
    p->posicao = x;

    if (inicio == NULL) {
        inicio = p;
    }

    p->prox = inicio->prox;
    inicio->prox = p;
    inicio = p;
}

void removeLista(Pessoa *p)
{
    Pessoa *aux;

    aux = p->prox;
    p->prox = aux->prox;

    if(aux->prox == aux) {
        inicio = NULL;
    }

    free(aux); // Libera o próximo elemento do elemento solicidado
}

void imprimeLista()
{
    Pessoa *aux = inicio; //Cria auxiliar para percorrer a lista desde o inicio

    do
    { // Printa a posição do elemento, passa para o próximo e verifica se esse é != de inicio
        printf("%d ", aux->posicao);
        aux = aux->prox;
    } while (aux != inicio);

    printf("\n");
}

int resolveJosephus(int n, int m)
{
    Pessoa *aux;

    for (int i = 1; i <= n; i++) // Insere as pessoas do problema de Josephus na lista
    {
        insereLista(i);
    }

    inicio = inicio->prox;

    while (inicio->prox != inicio) // Enquanto o elemento não estiver sozinho na lista (apontando para ele mesmo)
    {
        aux = inicio; // aux começa de p para procurar o próximo a ser eliminado

        for (int i = 1; i < m; i++)
        {
            aux = aux->prox;
        }

        if (aux->prox == inicio) // caso o próximo seja ele mesmo (caso do suícidio) pula um a mais
        {
            aux = aux->prox;
        }

        inicio = (aux->prox)->prox; //Define o p para o candidato á cometer o próximo assasinato (proxímo do último eliminado)
        removeLista(aux);           //Remove da lista o que foi assasinado
    }

    int resultado = (*inicio).posicao; // Salvo o resultado para o return
    removeLista(inicio);               // Removo p para liberar a lista

    return resultado; // Retorno a pessoa que sobreviveu
}

int main()
{
    int nroexecs;

    scanf("%d", &nroexecs);
    int *n = malloc(nroexecs * sizeof(int));
    int *p = malloc(nroexecs * sizeof(int));

    for (int i = 0; i < nroexecs; i++)
    {
        scanf("%d", &n[i]);
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < nroexecs; i++)
    {
        printf("Usando n=%d, m=%d, resultado=%d\n", n[i], p[i], resolveJosephus(n[i], p[i]));
    }

    return 0;
}