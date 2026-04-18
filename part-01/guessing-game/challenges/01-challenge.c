#include <stdio.h>

int main()
{
    int x, y, result;

    printf("First number: ");
    scanf("%d", &x);

    printf("Second number: ");
    scanf("%d", &y);

    result = x * y;

    printf("The multiplication of %d and %d is %d", x, y, result);
}
