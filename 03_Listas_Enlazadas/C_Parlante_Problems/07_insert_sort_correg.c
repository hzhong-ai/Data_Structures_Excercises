#include "Node.h"

void insertSort(struct Node** headRef) {
    struct Node* result = NULL;
    struct Node* current = *headRef;

    while (current != NULL) {
        if (result == NULL || result->data >= current->data) {
            current->next = result;
            result = current;
        } else {
            struct Node* r = result;
            while (r->next != NULL && r->next->data < current->data) {
                r = r->next;
            }
            current->next = r->next;
            r->next = current;
        }

        current = current->next;
    }

    *headRef = result;
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 15);
    push(&head, 5);
    push(&head, 10);
    push(&head, 7);

    insertSort(&head);

    assert(get(head, 0) == 5);
    assert(get(head, 1) == 7);
    assert(get(head, 2) == 10);
    assert(get(head, 3) == 15);

    clear(&head);
    return 0;
}
