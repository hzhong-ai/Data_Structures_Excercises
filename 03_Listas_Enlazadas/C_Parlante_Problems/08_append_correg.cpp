#include "LinkedList.h"

void LinkedList::append(LinkedList& other) {
    // Hint: Revisa el caso en que esta lista esté vacía y asegúrate de reiniciar el puntero de la lista 'other'.
    Node* current = head;
    while (current != nullptr) {
        current = current->next;
    }
    current->next = other.head;
}

int main() {
    LinkedList listA;
    listA.push(2);
    listA.push(1);

    LinkedList listB;
    listB.push(4);
    listB.push(3);

    listA.append(listB);

    assert(listB.isEmpty());
    assert(listA.get(0) == 1);
    assert(listA.get(1) == 2);
    assert(listA.get(2) == 3);
    assert(listA.get(3) == 4);

    listA.clear();
    listB.clear();
    return 0;
}
