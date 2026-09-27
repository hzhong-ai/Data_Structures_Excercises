#include "Node.h"

void alternatingSplit(struct Node* source, struct Node** aRef, struct Node** bRef) {
    struct Node* current = source;
    while (current != NULL) {
        struct Node* next = current->next;
        current->next = *aRef;
        *aRef = current;
        current = next;
        
        if (current != NULL) {
            next = current->next;
            current->next = *bRef;
            *bRef = current;
            current = next;
        }
    }
}
int main(void) {
    struct Node* list = NULL;
    push(&list, 5);
    push(&list, 4);
    push(&list, 3);
    push(&list, 2);
    push(&list, 1);

    struct Node* a = NULL;
    struct Node* b = NULL;
    alternatingSplit(list, &a, &b);

    assert(get(a, 0) == 1 || get(a, 0) == 5);
    assert(get(b, 0) == 2 || get(b, 0) == 4);

    clear(&a);
    clear(&b);
    clear(&list);
    return 0;
}
