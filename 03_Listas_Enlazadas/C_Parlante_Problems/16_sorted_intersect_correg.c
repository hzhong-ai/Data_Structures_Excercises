#include "Node.h"

struct Node* sortedIntersect(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            push(&(tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    return dummy.next;
}

int main(void) {
    struct Node* a = NULL;
    push(&a, 6); push(&a, 4); push(&a, 2); push(&a, 1);

    struct Node* b = NULL;
    push(&b, 5); push(&b, 4); push(&b, 2);

    struct Node* intersect = sortedIntersect(a, b);

    assert(get(intersect, 0) == 2);
    assert(get(intersect, 1) == 4);

    clear(&intersect);
    clear(&a);
    clear(&b);
    return 0;
}
