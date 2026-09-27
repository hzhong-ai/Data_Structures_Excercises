#include "Node.h"

void append(struct Node** aRef, struct Node** bRef) {
    struct Node* current = *aRef;
    if (current == NULL) {
        *aRef = *bRef;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *bRef;
    }
    *bRef = NULL;
}

int main(void) {
    struct Node* a = NULL;
    push(&a, 2);
    push(&a, 1);

    struct Node* b = NULL;
    push(&b, 4);
    push(&b, 3);

    append(&a, &b);

    assert(b == NULL);
    assert(get(a, 0) == 1);
    assert(get(a, 1) == 2);
    assert(get(a, 2) == 3);
    assert(get(a, 3) == 4);

    clear(&a);
    clear(&b);
    return 0;
}
