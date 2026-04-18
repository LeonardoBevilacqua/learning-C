#include <stdio.h>

void soma(int* num, int a, int b) {
    *num = a + b;
}

int main()
{
    int result = 0;
    int a = 5;
    int b = 7;

    soma(&result, a, b);
    printf("%d + %d = %d", a, b, result);
}
