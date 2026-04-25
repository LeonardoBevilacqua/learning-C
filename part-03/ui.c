#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "map.h"

char ghost_draw[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char wall_draw[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char player_draw[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char power_draw[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char empty_draw[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void print_part(char draw[4][7], int part) {
    printf("%s", draw[part]);
}

void print_map(MAP* m) {
    for (int i = 0; i < m->rows; i++) {

        for (int part = 0; part < 4; part++) {

            for (int j = 0; j < m->columns; j++) {
                switch (m->vector[i][j]) {
                    case GHOST:
                        print_part(ghost_draw, part);
                        break;
                    case PLAYER:
                        print_part(player_draw, part);
                        break;
                    case POWER:
                        print_part(power_draw, part);
                        break;
                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        print_part(wall_draw, part);
                        break;
                    case EMPTY:
                        print_part(empty_draw, part);
                        break;
                }
            }

            printf("\n");

        }

    }
}
