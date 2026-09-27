#include "Node.h"

int getNth(struct Node* head, int index) {
    // Hint: Evalúa qué ocurre al iterar modificando el puntero local y verifica la base del contador respecto a 'index'.
    int count = 0;
    while (head != NULL) {
        if (count == index) {
            return head->data;
        }
        count++;
        head = head->next;
    }
    return -1;
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 666);
    push(&head, 13);
    push(&head, 42);

    assert(getNth(head, 0) == 42);
    assert(getNth(head, 1) == 13);
    assert(getNth(head, 2) == 666);

    clear(&head);
    return 0;
}
