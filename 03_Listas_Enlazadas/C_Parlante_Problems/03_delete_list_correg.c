#include "Node.h"

void deleteList(struct Node** headRef) {
    // Hint: Asegúrate de guardar la referencia al siguiente nodo antes de liberar la memoria del nodo actual y actualiza el puntero original a NULL.
    struct Node* current = *headRef;
    struct Node* next;

    while (current != NULL) {
        free(current);
        next = current->next;
        current = next;
    }

    *headRef = NULL;
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    deleteList(&head);
    assert(head == NULL);

    clear(&head);
    return 0;
}
