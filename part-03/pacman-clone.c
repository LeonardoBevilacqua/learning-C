#include <stdio.h>
#include <stdlib.h>
#include "pacman-clone.h"
#include "map.h"

MAP m;
POSITION player;

int finished() {
    return 0;
}

void move(char direction) {

    if (direction != 'a'
            && direction != 'w'
            && direction != 's'
            && direction != 'd')
        return;

    int next_x = player.x;
    int next_y = player.y;

    switch (direction) {
        case 'a':
            next_y--;
            break;
        case 'w':
            next_x--;
            break;
        case 's':
            next_x++;
            break;
        case 'd':
            next_y++;
            break;
    }

    if (next_x >= m.rows) 
        return;
    if (next_y >= m.columns) 
        return;
    if (m.vector[next_x][next_y] != '.')
        return;

    m.vector[next_x][next_y] = '@';
    m.vector[player.x][player.y] = '.';
    player.x = next_x;
    player.y = next_y;
}

int main() {
    read_map(&m);
    search_map(&m, &player, '@');

    do {

        print_map(&m);

        char command;
        scanf(" %c", &command);
        move(command);

    } while (!finished());


    clear_map(&m);
}
