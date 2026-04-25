#include <stdio.h>
#include <stdlib.h>
#include "pacman-clone.h"
#include "map.h"

MAP m;
POSITION player;

int finished() {
    return 0;
}

int is_direction(char direction) {
    return direction == 'a' ||
        direction == 'w' ||
        direction == 's' ||
        direction == 'd';
}

void move(char direction) {
    if (!is_direction(direction))
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

    if (!is_valid(&m, next_x, next_y))
        return;
    if (!is_empty(&m, next_x, next_y))
        return;

    move_in_map(&m, player.x, player.y, next_x, next_y);
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
