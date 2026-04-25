#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h";

void copy_map(MAP* new, MAP* origin) {
    new->rows = origin->rows;
    new->columns = origin->columns;

    alloc_map(new);
    for (int i = 0; i < origin->rows; i++) {
        strcpy(new->vector[i], origin->vector[i]);
    }
}

int can_move(MAP* m, char entity, int x, int y) {
    return is_valid(m, x, y) &&
        !is_wall(m, x, y) &&
        !is_entity(m, entity, x, y);
}

int is_entity(MAP* m, char entity, int x, int y) {
    return m->vector[x][y] == entity;
}

int is_wall(MAP* m, int x, int y) {
    return m->vector[x][y] == VERTICAL_WALL ||
        m->vector[x][y] == HORIZONTAL_WALL;
}

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

int search_map(MAP*m, POSITION* p, char c) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->columns; j++) {
            if (m->vector[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }

    return 0;
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

