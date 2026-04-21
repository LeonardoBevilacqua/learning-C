#include <stdio.h>

int sum(int* numbers, int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += numbers[i];
    }

    return result;
}

int main() {
    int numbers[3];
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    int total = sum(numbers, 3);
    printf("TOTAL is %d\n", total);
}
