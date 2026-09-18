#include "LinkedList.h"

void LinkedList::alternatingSplit(LinkedList& a, LinkedList& b) {
    // Hint: Desconecta los nodos alternadamente hacia las listas A y B en lugar de crear copias o duplicar elementos.
    Node* current = head;
    while (current != nullptr) {
        a.push(current->data);
        current = current->next;
    }
}

int main() {
    LinkedList list;
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

    LinkedList a, b;
    list.alternatingSplit(a, b);

    assert(a.get(0) == 1 || a.get(0) == 5);
    assert(b.get(0) == 2 || b.get(0) == 4);

    a.clear();
    b.clear();
    list.clear();
    return 0;
}
