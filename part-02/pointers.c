#include <stdio.h>

void calculate(int* c) {
    printf("calculate %d %d\n", (*c), c);
    (*c)++;
    printf("calculate %d %d\n", (*c), c);
}

int main() {

    int c = 10;

    printf("main %d %d\n", c, &c);
    calculate(&c);
    printf("main %d %d\n", c, &c);
}
