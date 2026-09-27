#include "Node.h"

void sortedInsert(struct Node** headRef, int data) {
    // Hint: Cuidado con desreferenciar punteros nulos cuando el elemento a insertar es el más grande o cuando *headRef es NULL.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*headRef == NULL || (*headRef)->data >= data) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    struct Node* current = *headRef;

    while (current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main(void) {
    struct Node* head = NULL;

    sortedInsert(&head, 10);
    sortedInsert(&head, 5);
    sortedInsert(&head, 15);
    sortedInsert(&head, 7);

    assert(get(head, 0) == 5);
    assert(get(head, 1) == 7);
    assert(get(head, 2) == 10);
    assert(get(head, 3) == 15);

    clear(&head);
    return 0;
}
