#include "Node.h"

void moveNode(struct Node** destRef, struct Node** sourceRef) {
    if (*sourceRef == NULL) return;
    struct Node* temp = *sourceRef;
    *sourceRef = temp->next;
    temp->next = *destRef;
    *destRef = temp;

int main(void) {
    struct Node* dest = NULL;
    push(&dest, 2);
    push(&dest, 1);

    struct Node* source = NULL;
    push(&source, 4);
    push(&source, 3);

    moveNode(&dest, &source);

    assert(get(dest, 0) == 3);
    assert(get(dest, 1) == 1);
    assert(get(dest, 2) == 2);
    assert(get(source, 0) == 4);

    clear(&dest);
    clear(&source);
    return 0;
}
