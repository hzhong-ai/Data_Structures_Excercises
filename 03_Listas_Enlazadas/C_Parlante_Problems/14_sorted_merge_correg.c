#include "Node.h"

struct Node* sortedMerge(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a != NULL) tail->next = a;
    if (b != NULL) tail->next = b;
    return dummy.next;
}

int main(void) {
    struct Node* a = NULL;
    push(&a, 10); push(&a, 5); push(&a, 2);

    struct Node* b = NULL;
    push(&b, 7); push(&b, 3);

    struct Node* merged = sortedMerge(a, b);

    assert(get(merged, 0) == 2);
    assert(get(merged, 1) == 3);
    assert(get(merged, 2) == 5);
    assert(get(merged, 3) == 7);
    assert(get(merged, 4) == 10);

    clear(&merged);
    return 0;
}
