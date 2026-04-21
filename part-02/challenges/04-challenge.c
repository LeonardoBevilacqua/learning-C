#include <stdio.h>

void power(int* result, int a, int b) {
    *result = 1;
    for (int i = 0; i < b; i++) {
        *result *=  a;
    }
}

int main()
{
    int result = 0;
    int a = 2;
    int b = 3;
    power(&result, a, b);
    printf("%d ^ %d = %d\n", a, b, result);
}
