#include "LinkedList.h"

int LinkedList::count(int searchFor) {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        // Hint: Revisa el operador de comparación y la ubicación del avance del puntero.
        if (current->data != searchFor) {
            count++;
            current = current->next;
        }
    }
    return count;
}

int main() {
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(1);
    list.push(3);

    assert(list.count(1) == 2);
    assert(list.count(2) == 1);
    assert(list.count(99) == 0);

    list.clear();
    return 0;
}
