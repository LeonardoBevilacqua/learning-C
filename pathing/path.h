#ifndef _PATH_H_
#define _PATH_H_

#define MAX_PATHS 2

struct Node {
    char value;
    struct Node* previous[MAX_PATHS];
    struct Node* next[MAX_PATHS];
};
typedef struct Node NODE;

NODE create_node(const char value);
void connect_next_nodes(NODE* node, NODE* next[MAX_PATHS]);
void connect_previous_nodes(NODE* node, NODE* previous[MAX_PATHS]);
void navigate_nodes(NODE* starting_node);
void print_node(const NODE* node);

#endif // !_PATH_H_
