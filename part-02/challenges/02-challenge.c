#include <stdio.h>

void soma(int numbers[10]) {
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += numbers[i];
    }

    printf("Sum of the numbers is %d", result);
}

int main()
{
    int numbers[10];
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;
    numbers[5] = 6;
    numbers[6] = 7;
    numbers[7] = 8;
    numbers[8] = 9;
    numbers[9] = 10;

    soma(numbers);
}
