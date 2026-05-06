#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void add(int value, NODE** list) {
    NODE* new = malloc(sizeof(NODE));

    if (!new) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new->data = value;
    new->next = NULL;

    if (!*list) {
        *list = new;
        return;
    }

    NODE* temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void free_list(NODE* list) {
    NODE* temp = list;
    while (temp != NULL) {
        NODE* next = temp->next;
        free(temp);
        temp = next;
    }
}
