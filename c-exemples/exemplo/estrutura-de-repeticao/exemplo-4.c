#include <stdio.h>

int main()
{
    int i, n, r;
    i = 1;
    do
    {
        scanf("%d", &n);
        r = n * 3;
        printf("\n%d\n", r);
        i++;
    } while (i <= 5);

    getchar();
}
