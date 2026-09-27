#include "Node.h"

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            current = current->next;
        } else {
            current = current->next;
        }
    }
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);

    removeDuplicates(head);

    assert(get(head, 0) == 1);
    assert(get(head, 1) == 2);
    assert(get(head, 2) == 3);

    clear(&head);
    return 0;
}
