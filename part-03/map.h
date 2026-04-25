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

void search_map(MAP*m, POSITION* p, char c);
void clear_map(MAP* m);
void read_map(MAP* m);
void alloc_map(MAP* m);
void print_map(MAP* m);

