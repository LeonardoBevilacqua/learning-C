#include <stdio.h>

int main()
{
    char sexo;

    printf("Entre com o sexo:");
    scanf("%c", &sexo);

    if (!(sexo == 'm'))
    {
        printf("qualquer coisa");
    }
    else
    {
        printf("masculino");
    }

    getchar();
}
