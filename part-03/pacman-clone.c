#include <stdio.h>

int main() {
    // vector of 5 x 10
    char map[5][10];

    map[0][0] = '|';
    map[4][9] = '@';

    printf("%c %c\n", map[0][0], map[4][9]);
}
