#include <stdio.h>
#include <stdlib.h>

int main() {
    // vector of 5 x 10. The '+ 1' is to include the end of line
    char map[5][10+1];

    FILE* file = fopen("map.txt", "r");
    if (file == 0) {
        printf("Error while readiing the map file\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%s\n", map[i]);
    }

    fclose(file);
}
