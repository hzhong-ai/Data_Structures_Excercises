#include "LinkedList.h"

void LinkedList::deleteList() {
    // Hint: Asegúrate de guardar la referencia al siguiente nodo antes de liberar la memoria del nodo actual.
    Node* current = head;
    while (current != nullptr) {
        delete current;
        current = current->next;
    }
}

int main() {
    LinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);

    list.deleteList();
    assert(list.getHead() == nullptr);

    list.clear();
    return 0;
}
