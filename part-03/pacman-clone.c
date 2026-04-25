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

    m.vector[player.x][player.y] = '.';

    switch (direction) {
        case 'a':
            m.vector[player.x][player.y-1] = '@';
            player.y--;
            break;
        case 'w':
            m.vector[player.x-1][player.y] = '@';
            player.x--;
            break;
        case 's':
            m.vector[player.x+1][player.y] = '@';
            player.x++;
            break;
        case 'd':
            m.vector[player.x][player.y+1] = '@';
            player.y++;
            break;
    }
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
