#include <stdio.h>
#include <stdlib.h>
#include "pacman-clone.h"

struct map m;

void clear_map() {
    for (int i = 0; i < m.rows; i++) {
        free(m.vector[i]);
    }
    free(m.vector);
}

void alloc_map() {
    m.vector = malloc(sizeof(char*) * m.rows);
    for (int i = 0; i < m.rows; i++) {
        m.vector[i] = malloc(sizeof(char) * (m.columns + 1));
    }
}

void read_map() {
    FILE* file = fopen("map.txt", "r");
    if (file == 0) {
        printf("Error while readiing the map file\n");
        exit(1);
    }

    fscanf(file, "%d %d", &m.rows, &m.columns);

    alloc_map();

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", m.vector[i]);
    }

    fclose(file);
}

void print_map() {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", m.vector[i]);
    }
}

int finished() {
    return 0;
}

void move(char direction) {
    int x, y;

    // search the player position (may be converted to own function)
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            if (m.vector[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction) {
        case 'a':
            m.vector[x][y-1] = '@';
            break;
        case 'w':
            m.vector[x-1][y] = '@';
            break;
        case 's':
            m.vector[x+1][y] = '@';
            break;
        case 'd':
            m.vector[x][y+1] = '@';
            break;
    }

    m.vector[x][y] = '.';

}

int main() {
    read_map();

    do {

        print_map();

        char command;
        scanf(" %c", &command);
        move(command);

    } while (!finished());


    clear_map();
}
