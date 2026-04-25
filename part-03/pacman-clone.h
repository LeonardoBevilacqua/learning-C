#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

void move(char direction);
void ghosts();
int finished();
int is_direction(char direction);
int where_ghost_should_move(int current_x, int current_y, int* to_x, int* to_y);

