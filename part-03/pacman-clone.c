#include <stdio.h>
#include <stdlib.h>

char** map;
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

    map = malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        map[i] = malloc(sizeof(char) * (columns + 1));
    }

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%s\n", map[i]);
    }

    fclose(file);

    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}
