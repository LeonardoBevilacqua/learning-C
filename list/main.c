#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(NODE* list) {
    NODE* temp = list;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE* head = malloc(sizeof(NODE));
    NODE* second = malloc(sizeof(NODE));
    NODE* third = malloc(sizeof(NODE));

    if (!head || !second || !third) {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;
    
    third->data =30;
    third->next = NULL;

    print_list(head);
    free_list(head);

    NODE* my_list = NULL;
    add(10, &my_list);
    add(20, &my_list);
    add(30, &my_list);
    print_list(my_list);
    add(40, &my_list);
    print_list(my_list);

    free_list(my_list);
    return 0;
}
