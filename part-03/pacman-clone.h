#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

void move(char direction);
void ghosts();
void explode();
void explode_by_direction(int x, int y, int sum_x, int sum_y, int amount);
int finished();
int is_direction(char direction);
int where_ghost_should_move(int current_x, int current_y, int* to_x, int* to_y);

