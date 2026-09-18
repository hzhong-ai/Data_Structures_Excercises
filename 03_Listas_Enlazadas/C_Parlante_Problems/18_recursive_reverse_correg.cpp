#include "LinkedList.h"

void LinkedList::recursiveReverse() {
    // Hint: Piensa en cómo queda el puntero 'next' del primer nodo cuando se completa la inversión del resto de la lista y cómo afecta esto a la estructura final.

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* first = head;
    LinkedList rest;
    rest.head = first->next;

    rest.recursiveReverse();

    first->next->next = first;

    head = rest.head;
    rest.head = nullptr;
}

int main() {
    LinkedList list;
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

    list.recursiveReverse();

    assert(list.get(0) == 4);
    assert(list.get(1) == 3);
    assert(list.get(2) == 2);
    assert(list.get(3) == 1);

    list.clear();
    return 0;
}
