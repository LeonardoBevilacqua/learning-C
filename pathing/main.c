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
 * A - B - C - E - G - H
 *       |             |
 *       - D - F - - - -
*/
int main() {
    // each node should be aware of previous and next
    NODE nodeA = { 'A', 0 };
    NODE nodeB = { 'B', {&nodeA, 0} };
    nodeA.next[0] = &nodeB;

    NODE nodeC = { 'C', {&nodeB, 0} };
    NODE nodeD = { 'D', {&nodeB, 0} };
    nodeB.next[0] = &nodeC;
    nodeB.next[1] = &nodeD;

    NODE nodeE = { 'E', {&nodeC, 0} };
    nodeC.next[0] = &nodeE;

    NODE nodeF = { 'F', {&nodeD}, 0 };
    nodeD.next[0] = &nodeF;

    NODE nodeG = { 'G', {&nodeE, &nodeF}, 0 };
    nodeE.next[0] = &nodeG;

    NODE nodeH = { 'H', {&nodeG, &nodeF}, 0 };
    nodeG.next[0] = &nodeH;
    nodeF.next[0] = &nodeH;

    NODE* temp = &nodeA;
    while(temp) {
        int path = 0;
        print_node(temp);
        if (temp->next[1]) {
            printf("Path 0 - %c or 1 - %c: ", temp->next[0]->value, temp->next[1]->value);
            if (!scanf("%d", &path) || path < 0 || path > 1) path = 0;
        }
        temp = temp->next[path];
    }
    // previous and next can have at most 2 possibilities
    // should navigate the list one item at the time until reach the destination
    // if previous/next has 2 possibilities, should pause to choose the next item

    return 0;
}
