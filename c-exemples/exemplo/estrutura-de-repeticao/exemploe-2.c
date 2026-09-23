#include <stdio.h>

int main()
{
    int n, r; // declaração das variaveis
    char resp = 'S'; // variavel de iteração começa com valor S
    while (resp == 'S') // Código dentro do bloco deve ser executado até a condição ser FALSA
    {
        scanf("%d", &n); // Entrada
        r = n * 3; // Processamento
        printf("\n%d\n", r); // Saida

        printf("Deseja continuar?\n");
        scanf(" %c", &resp);
    }
    getchar();
}
