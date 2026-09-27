#include "Node.h"

struct Node* shuffleMerge(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (a != NULL || b != NULL) {
        if (a != NULL) {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        if (b != NULL) {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    return dummy.next;

int main(void) {
    struct Node* a = NULL;
    push(&a, 3); push(&a, 2); push(&a, 1);

    struct Node* b = NULL;
    push(&b, 13); push(&b, 7);

    struct Node* merged = shuffleMerge(a, b);

    assert(get(merged, 0) == 1);
    assert(get(merged, 1) == 7);
    assert(get(merged, 2) == 2);
    assert(get(merged, 3) == 13);
    assert(get(merged, 4) == 3);

    clear(&merged);
    return 0;
}
