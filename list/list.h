#ifndef _LIST_H_
#define _LIST_H_

struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};
typedef struct Node NODE;

NODE* find(int value, NODE* list);
NODE* get(int position, NODE* list);
void add(int value, NODE** list);
void free_list(NODE* list);

#endif /* ifndef _LIST_H_ */
