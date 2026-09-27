#include "Node.h"

void recursiveReverse(struct Node** headRef) {
    // Hint: Piensa en cómo queda el puntero 'next' del primer nodo cuando se completa la inversión del resto de la lista y cómo afecta esto a la estructura final.

    if (*headRef == NULL || (*headRef)->next == NULL) {
        return;
    }

    struct Node* first = *headRef;
    struct Node* rest = first->next;

    recursiveReverse(&rest);

    first->next->next = first;
    first->next = NULL;

    *headRef = first;
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    recursiveReverse(&head);

    assert(get(head, 0) == 4);
    assert(get(head, 1) == 3);
    assert(get(head, 2) == 2);
    assert(get(head, 3) == 1);

    clear(&head);
    return 0;
}
