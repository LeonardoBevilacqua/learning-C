#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman-clone.h"
#include "map.h"

MAP m;
POSITION player;

int where_ghost_should_move(int current_x, int current_y,
        int* to_x, int* to_y) {
    int options[4][2] = {
        { current_x, current_y+1 },
        { current_x+1, current_y },
        { current_x, current_y-1 },
        { current_x-1, current_y }
    };

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int position = rand() % 4;

        if (can_move(&m, options[position][0], options[position][1])) {
            *to_x = options[position][0];
            *to_y = options[position][1];

            return 1;
        }
    }

    return 0;
}

void ghosts() {
    MAP copy;

    copy_map(&copy, &m);

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            if (copy.vector[i][j] == GHOST) {
                int to_x, to_y;
                int found = where_ghost_should_move(i, j, &to_x, &to_y);

                if (found) {
                    move_in_map(&m, i, j, to_x, to_y);
                }
            }
        }
    }

    clear_map(&copy);
}

int finished() {
    POSITION pos;
    int found_player = search_map(&m, &pos, PLAYER);

    return !found_player;
}

int is_direction(char direction) {
    return direction == LEFT ||
        direction == UP ||
        direction == DOWN ||
        direction == RIGHT;
}

void move(char direction) {
    if (!is_direction(direction))
        return;

    int next_x = player.x;
    int next_y = player.y;

    switch (direction) {
        case LEFT:
            next_y--;
            break;
        case UP:
            next_x--;
            break;
        case DOWN:
            next_x++;
            break;
        case RIGHT:
            next_y++;
            break;
    }

    if (!can_move(&m, next_x, next_y))
        return;

    move_in_map(&m, player.x, player.y, next_x, next_y);
    player.x = next_x;
    player.y = next_y;
}

int main() {
    read_map(&m);
    search_map(&m, &player, PLAYER);

    do {

        print_map(&m);

        char command;
        scanf(" %c", &command);
        move(command);
        ghosts();

    } while (!finished());


    clear_map(&m);
}
