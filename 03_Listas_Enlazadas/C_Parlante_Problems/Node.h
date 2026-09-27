#ifndef NODE_H
#define NODE_H

#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

struct Node {
    int data;
    struct Node* next;
};

static inline void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    assert(newNode != NULL);
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

static inline void clear(struct Node** headRef) {
    struct Node* current = *headRef;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

static inline int get(struct Node* head, int index) {
    struct Node* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    assert(current != NULL);
    return current->data;
}

#endif
