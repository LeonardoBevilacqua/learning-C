#include <stdio.h>
#include <stdlib.h>
#include "map.h";

int is_valid(MAP* m, int x, int y) {
    if (x >= m->rows)
        return 0;
    if (y >= m->columns)
        return 0;

    return 1;
}

int is_empty(MAP* m, int x, int y) {
    return m->vector[x][y] == EMPTY;
}

void move_in_map(MAP* m, int from_x, int from_y, int to_x,  int to_y) {
    char entity = m->vector[from_x][from_y];
    m->vector[to_x][to_y] = entity;
    m->vector[from_x][from_y] = EMPTY;
}

void search_map(MAP*m, POSITION* p, char c) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->columns; j++) {
            if (m->vector[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

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
