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

void print_map() {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", map[i]);
    }
}

int finished() {
    return 0;
}

void move(char direction) {
    int x, y;

    // search the player position (may be converted to own function)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (map[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction) {
        case 'a':
            map[x][y-1] = '@';
            break;
        case 'w':
            map[x-1][y] = '@';
            break;
        case 's':
            map[x+1][y] = '@';
            break;
        case 'd':
            map[x][y+1] = '@';
            break;
    }

    map[x][y] = '.';

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
