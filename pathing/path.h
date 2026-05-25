#ifndef _PATH_H_
#define _PATH_H_

struct Node {
    char value;
    struct Node* previous[2];
    struct Node* next[2];
};
typedef struct Node NODE;

void navigate_nodes(NODE* starting_node);
void print_node(NODE* node);
void set_next(NODE* node, NODE* next[2]);
void set_previous(NODE* node, NODE* previous[2]);

#endif // !_PATH_H_
