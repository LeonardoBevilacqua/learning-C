#include <stdio.h>

int main()
{
    int i, n, r; // declaração das variaveis
    i = 1; // variavel de iteração começa com valor 1
    while (i <= 5) // Código dentro do bloco deve ser executado até a condição ser FALSA
    {
        scanf("%d", &n); // Entrada
        r = n * 3; // Processamento
        printf("\n%d\n", r); // Saida
        i++; // ++ equivalente a i = i + 1
    }
    getchar();
}
