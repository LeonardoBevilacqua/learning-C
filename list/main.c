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
    NODE* my_list = NULL;

    add(10, &my_list);
    add(20, &my_list);
    add(30, &my_list);
    print_list(my_list);

    add(40, &my_list);
    print_list(my_list);

    NODE* test = get(3, my_list);
    if (test != NULL)
        printf("%d\n", test->data);
    test = find(10, my_list);
    if (test != NULL)
        printf("%d\n", test->data);

    free_list(my_list);

    return 0;
}
