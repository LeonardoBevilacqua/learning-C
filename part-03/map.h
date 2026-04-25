#define PLAYER '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define POWER 'P'

struct map {
    char** vector;
    int rows;
    int columns;
};

typedef struct map MAP;

struct position {
    int x;
    int y;
};

typedef struct position POSITION;

int search_map(MAP*m, POSITION* p, char c);
void clear_map(MAP* m);
void read_map(MAP* m);
void alloc_map(MAP* m);
void print_map(MAP* m);
void move_in_map(MAP* m, int from_x, int from_y, int to_x,  int to_y);
void copy_map(MAP* new, MAP* origin);
int can_move(MAP* m, char entity, int x, int y);
int is_entity(MAP* m, char entity, int x, int y);
int is_wall(MAP* m, int x, int y);
int is_valid(MAP* m, int x, int y);
int is_empty(MAP* m, int x, int y);
