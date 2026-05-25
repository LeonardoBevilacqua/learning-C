#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node* previous[2];
    struct Node* next[2];
};
typedef struct Node NODE;

void print_node(NODE* node) {
    printf("Mem: %d - value: %c, previous: [%d, %d], next: [%d, %d]\n",
           node,
           node->value,
           node->previous[0], node->previous[1],
           node->next[0], node->next[1]
    );
}

/*
 * A - B - C - E - G
 *       |       |
 *       - D - F -
*/
int main() {
    // each node should be aware of previous and next
    NODE nodeA = { 'A' };
    NODE nodeB = { 'B', {&nodeA} };
    nodeA.next[0] = &nodeB;
    NODE nodeC = { 'C', {&nodeB} };
    nodeB.next[0] = &nodeC;
    NODE nodeD = { 'D', {&nodeB} };
    nodeB.next[1] = &nodeD;
    NODE nodeE = { 'E', {&nodeC} };
    nodeC.next[0] = &nodeE;
    NODE nodeF = { 'F', {&nodeD} };
    nodeD.next[0] = &nodeF;
    NODE nodeG = { 'G', {&nodeE, &nodeF} };

    print_node(&nodeA);
    print_node(&nodeB);
    print_node(&nodeC);
    print_node(&nodeD);
    print_node(&nodeE);
    print_node(&nodeF);
    print_node(&nodeG);
    // previous and next can have at most 2 possibilities
    // should navigate the list one item at the time until reach the destination
    // if previous/next has 2 possibilities, should pause to choose the next item

    return 0;
}
