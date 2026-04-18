#include <stdio.h>

void power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result = result * a;
    }

    printf("%d ^ %d = %d\n", a, b, result);
}

int main()
{
    power(2, 3);
}
