#include "LinkedList.h"

void LinkedList::removeDuplicates() {
    // Hint: No avances el puntero de recorrido cuando elimines un nodo y recuerda liberar la memoria del duplicado.
    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            current->next = current->next->next;
        }
        current = current->next;
    }
}

int main() {
    LinkedList list;
    list.push(3);
    list.push(2);
    list.push(2);
    list.push(2);
    list.push(1);

    list.removeDuplicates();

    assert(list.get(0) == 1);
    assert(list.get(1) == 2);
    assert(list.get(2) == 3);

    list.clear();
    return 0;
}
