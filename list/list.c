#include "list.h"
#include <stdio.h>
#include <stdlib.h>

NODE* get(int position, NODE* list) {
    int index = 0;

    NODE* temp = list;
    while (index != position) {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
        index++;
    }

    return temp;
}

void add(int value, NODE** list) {
    NODE* new = malloc(sizeof(NODE));

    if (!new) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new->data = value;
    new->next = NULL;

    if (!*list) {
        new->previous = NULL;
        *list = new;
        return;
    }

    NODE* temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    new->previous = temp;
}

void free_list(NODE* list) {
    NODE* temp = list;
    while (temp != NULL) {
        NODE* next = temp->next;
        free(temp);
        temp = next;
    }
}
