#include "LinkedList.h"

int LinkedList::pop() {
    // Hint: Revisa el orden de liberación de memoria y valida que la lista contenga nodos antes de operar.
    Node* temp = head;
    delete temp;
    head = head->next;
    return temp->data;
}

int main() {
    LinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);

    assert(list.pop() == 1);
    assert(list.pop() == 2);
    assert(list.pop() == 3);

    list.clear();
    return 0;
}
