#include "path.h"
#include <stdio.h>

// private
static int is_valid_position(const int position) {
    return position >= 0 && position <= 1;
}

static int handle_path(const NODE* node) {
    if (!node->next[1]) return 0; 

    printf("Path 0 - %c or 1 - %c: ", node->next[0]->value, node->next[1]->value);

    int path = 0;
    if (!scanf("%d", &path) || !is_valid_position(path)) path = 0;
    return path;
}

// public
NODE create_node(const char value) {
    NODE node = {
        .value = value,
        .next = { NULL, NULL },
        .previous = { NULL, NULL }
    };

    return node;
}

void navigate_nodes(NODE* starting_node) {
    NODE* temp = starting_node;
    while(temp) {
        print_node(temp);
        temp = temp->next[handle_path(temp)];
    }
}

void print_node(const NODE* node) {
    printf("Mem: %p - value: %c, previous: [%p, %p], next: [%p, %p]\n",
           node,
           node->value,
           node->previous[0], node->previous[1],
           node->next[0], node->next[1]
    );
}

void connect_next_nodes(NODE* node, NODE* next[MAX_PATHS]) {
    node->next[0] = next[0];
    node->next[1] = next[1];
}

void connect_previous_nodes(NODE* node, NODE* previous[MAX_PATHS]) {
    node->previous[0] = previous[0];
    node->previous[1] = previous[1];
}
