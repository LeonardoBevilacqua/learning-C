#include <stdio.h>
#include <stdlib.h>
#include "map.h";

void clear_map(MAP* m) {
    // (*m).rows == m->rows
    for (int i = 0; i < m->rows; i++) {
        free(m->vector[i]);
    }
    free(m->vector);
}

void read_map(MAP* m) {
    FILE* file = fopen("map.txt", "r");
    if (file == 0) {
        printf("Error while readiing the map file\n");
        exit(1);
    }

    fscanf(file, "%d %d", &m->rows, &m->columns);

    alloc_map(m);

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", m->vector[i]);
    }

    fclose(file);
}

void alloc_map(MAP* m) {
    m->vector = malloc(sizeof(char*) * m->rows);
    for (int i = 0; i < m->rows; i++) {
        m->vector[i] = malloc(sizeof(char) * (m->columns + 1));
    }
}

void print_map(MAP* m) {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", m->vector[i]);
    }
}
