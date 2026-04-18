#include <stdio.h>

int main()
{
    int number = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= 10; i++) {
        int result = number * i;
        printf("%d x %d = %d\n", number, i, result);
    }
}
