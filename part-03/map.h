struct map {
    char** vector;
    int rows;
    int columns;
};

typedef struct map MAP;

void clear_map(MAP* m);
void read_map(MAP* m);
void alloc_map(MAP* m);
void print_map(MAP* m);

