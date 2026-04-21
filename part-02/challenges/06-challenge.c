#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("teste.txt", "r");
    if (file == 0) {
        printf("Could not open teste.txt");
        exit(1);
    }

    fclose(file);
}
