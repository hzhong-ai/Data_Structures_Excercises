#include "Node.h"

void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        struct Node* slow = source;
        struct Node* fast = source;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

int main(void) {
    struct Node* list = NULL;
    push(&list, 5);
    push(&list, 4);
    push(&list, 3);
    push(&list, 2);
    push(&list, 1);

    struct Node* front = NULL;
    struct Node* back = NULL;
    frontBackSplit(list, &front, &back);

    assert(get(front, 0) == 1);
    assert(get(front, 1) == 2);
    assert(get(front, 2) == 3);
    assert(get(back, 0) == 4);
    assert(get(back, 1) == 5);

    clear(&front);
    clear(&back);
    return 0;
}
