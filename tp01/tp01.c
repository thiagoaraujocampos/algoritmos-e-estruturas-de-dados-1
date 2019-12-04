// Thiago Araujo Campos 769850
// Engenharia de Computação


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromoR(int i, int f, char *s)
{
    //Implemente esta função recursiva.
    if(f <= i){
        return 1;
    } else {
        if (s[f] != s[i]) {
            return 0;
        } else {
            return palindromoR(i+1, f-1, s);
        }
    }
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    printf("\"");
    printf("%s", s);
    printf("\" ");

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str) 
{
    //Implemente esta função recursiva.
    if(*str != '\0'){
        inversaR(str+1);
        printf("%c", *str);
    }
 }

void inversa(char *s)
{
    printf("inversa de \"");
    printf("%s", s);
    printf("\" = ");

    inversaR(s);

    printf("\n");
}

unsigned long stirlingR(unsigned long n, unsigned long k)
{
    //Implemente esta função recursiva.
    if(n == 0 && k == 0) {
        return 1;
    } else if (n == 0 || k == 0) {
        return 0;
    } else {
        return (n-1)*stirlingR(n-1, k) + stirlingR(n-1, k-1);
    }
}

void stirling(unsigned long n, unsigned long k)
{
    printf("Numero de Stirling [%lu, %lu]:", n, k);
    printf("%lu\n", stirlingR(n, k));
}

void padraoR(unsigned int x)
{
    //Implemente esta função recursiva.
    if (x <= 0) {
        printf("%d%d",x,x);
    } else {
        printf("%d",x);
        padraoR(x-1);
        printf("%d",x);
    }
}

void padrao(unsigned int x)
{
    printf("Testando o padrao para n = %d.\n", x);
    padraoR(x);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int t;

    scanf("%d", &t);

    // if (argc != 2 || (t = atoi(argv[1])) < 1 || t > 4)
    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar fibonacci]\n");
        printf("tp01_recursao 4 [para testar pisoLog]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        palindromo("");
        palindromo("1");
        palindromo("77");
        palindromo("505");
        palindromo("1111");
        palindromo("2112");
        palindromo("369963");
        palindromo("10101");
        palindromo("1001001");
        palindromo("12");
        palindromo("12451");
        palindromo("100011");
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        inversaR("");
        inversa("ab");
        inversa("gato");
        inversa("minerva");
    }
    else if (t == 3)
    {
        printf("\nTestando stirling()\n\n");
	stirling(0, 0);
	stirling(0, 3);
	stirling(5, 0);
	stirling(2, 2);
	stirling(5, 1);
	stirling(5, 2);
	stirling(7, 6);
	stirling(9, 3);
	stirling(10, 3);
	stirling(10, 5);
    }
    else if (t == 4)
    {
        printf("\nTestando padrao()\n\n");
	padrao(0);
	padrao(1);
	padrao(5);
	padrao(10);
	padrao(100);        
    }

    return 0;
}
