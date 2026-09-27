#include "Node.h"

void insertNth(struct Node** headRef, int index, int data) {
    // Hint: Analiza qué ocurre si la inserción es en el índice 0 mediante *headRef y cómo conectar los nodos subsecuentes.
    if (index == 0) {
        push(headRef, data);
    } else {
        struct Node* current = *headRef;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = current;
        current->next = newNode;
    }
}

int main(void) {
    struct Node* head = NULL;

    insertNth(&head, 0, 13);
    insertNth(&head, 1, 42);
    insertNth(&head, 1, 5);

    assert(get(head, 0) == 13);
    assert(get(head, 1) == 5);
    assert(get(head, 2) == 42);

    clear(&head);
    return 0;
}
