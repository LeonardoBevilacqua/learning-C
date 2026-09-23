#include <stdio.h>

int main()
{
    char sexo;

    printf("Entre com o sexo:");
    scanf("%c", &sexo);

    if (sexo == 'm' || sexo == 'f')
    {
        printf("Valido");
    }
    else
    {
        printf("não rolou");
    }

    getchar();
}
