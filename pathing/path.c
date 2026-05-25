#include "path.h"
#include <stdio.h>

// private
int is_valid_position(int position) {
    return position >= 0 && position <= 1;
}

int handle_path(NODE* node) {
    if (!node->next[1]) return 0; 

    printf("Path 0 - %c or 1 - %c: ", node->next[0]->value, node->next[1]->value);

    int path = 0;
    if (!scanf("%d", &path) || !is_valid_position(path)) path = 0;
    return path;
}

// public
void navigate_nodes(NODE* starting_node) {
    NODE* temp = starting_node;
    while(temp) {
        print_node(temp);
        temp = temp->next[handle_path(temp)];
    }
}

void print_node(NODE* node) {
    printf("Mem: %d - value: %c, previous: [%d, %d], next: [%d, %d]\n",
           node,
           node->value,
           node->previous[0], node->previous[1],
           node->next[0], node->next[1]
    );
}

void set_next(NODE* node, NODE* next[2]) {
    node->next[0] = next[0];
    node->next[1] = next[1];
}

void set_previous(NODE* node, NODE* previous[2]) {
    node->previous[0] = previous[0];
    node->previous[1] = previous[1];
}
