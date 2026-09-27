#include "Node.h"

int pop(struct Node** headRef) {
    // Hint: Revisa el orden de liberación de memoria con free() y valida la actualización de *headRef.
    struct Node* temp = *headRef;
    int res = temp->data;
    *headRef = (*headRef)->next;
    free(temp);
    return res;
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    assert(pop(&head) == 1);
    assert(pop(&head) == 2);
    assert(pop(&head) == 3);
    assert(head == NULL);

    clear(&head);
    return 0;
}
