#include <stdio.h>
#include <stdlib.h>
#include "pacman-clone.h"

char** map;
int rows;
int columns;

void clear_map() {
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}

void alloc_map() {
    map = malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        map[i] = malloc(sizeof(char) * (columns + 1));
    }
}

void read_map() {
    FILE* file = fopen("map.txt", "r");
    if (file == 0) {
        printf("Error while readiing the map file\n");
        exit(1);
    }

    fscanf(file, "%d %d", &rows, &columns);

    alloc_map();

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", map[i]);
    }

    fclose(file);
}

int main() {
    read_map();

    for (int i = 0; i < 5; i++) {
        printf("%s\n", map[i]);
    }

    clear_map();
}
