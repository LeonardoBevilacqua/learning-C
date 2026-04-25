void clear_map();
void alloc_map();
void read_map();
void print_map();
void move(char direction);
int finished();

struct map {
    char** vector;
    int rows;
    int columns;
};
