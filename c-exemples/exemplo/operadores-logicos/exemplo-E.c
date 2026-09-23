#include <stdio.h>

int main()
{
    int n;

    printf("Entre com um numero:");
    scanf("%d", &n);

    if (n > 20 && n < 90)
    {
        printf("O número esta na faixa de 20 e 90");
    }
    else
    {
        printf("não rolou");
    }

    getchar();
}
