#include <stdio.h>
#include <stdlib.h>

char map[5][10+1];
int rows;
int columns;

int main() {
    FILE* file = fopen("map.txt", "r");
    if (file == 0) {
        printf("Error while readiing the map file\n");
        exit(1);
    }

    fscanf(file, "%d %d", &rows, &columns);
    printf("Rows %d Columns %d\n", rows, columns);

    /////////////
    int** v = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        v[i] = malloc(sizeof(int) * 10);
    }
    v[0][0] = 10;
    v[1][2] = 12;
    printf("allocated int %d %d\n", v[0][0], v[1][2]);
    for (int i = 0; i < 5; i++) {
        free(v[i]);
    }
    free(v);
    /////////////

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%s\n", map[i]);
    }

    fclose(file);
}
