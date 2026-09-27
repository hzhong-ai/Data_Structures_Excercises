#include "Node.h"

void reverse(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* current = *headRef;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;

int main(void) {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    reverse(&head);

    assert(get(head, 0) == 3);
    assert(get(head, 1) == 2);
    assert(get(head, 2) == 1);

    clear(&head);
    return 0;
}
