#include "Node.h"

int count(struct Node* head, int searchFor) {
    struct Node* current = head;
    int c = 0;
    while (current != NULL) {
        current = current->next;
        // Hint: Revisa la condición de búsqueda y la posición del avance del puntero.
        if (current->data != searchFor) {
            c++;
        }
        current = current->next;
    }
    return c;
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    assert(count(head, 1) == 2);
    assert(count(head, 2) == 1);
    assert(count(head, 99) == 0);

    clear(&head);
    return 0;
}
