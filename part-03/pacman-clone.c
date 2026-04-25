#include <stdio.h>
#include <stdlib.h>
#include "pacman-clone.h"
#include "map.h"

MAP m;

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
    read_map(&m);

    do {

        print_map(&m);

        char command;
        scanf(" %c", &command);
        move(command);

    } while (!finished());


    clear_map(&m);
}
