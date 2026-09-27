#include "Node.h"

void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        struct Node* slow = source;
        struct Node* fast = source->next;

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

void mergeSort(struct Node** headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) return;

    struct Node* a;
    struct Node* b;

    frontBackSplit(*headRef, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, *headRef);
}

int main(void) {
    struct Node* head = NULL;
    push(&head, 2);
    push(&head, 8);
    push(&head, 5);
    push(&head, 1);
    push(&head, 4);

    mergeSort(&head);

    assert(get(head, 0) == 1);
    assert(get(head, 1) == 2);
    assert(get(head, 2) == 4);
    assert(get(head, 3) == 5);
    assert(get(head, 4) == 8);

    clear(&head);
    return 0;
}
