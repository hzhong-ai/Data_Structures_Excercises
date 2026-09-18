#include "LinkedList.h"

void LinkedList::sortedInsert(int data) {
    // Hint: Cuidado con desreferenciar punteros nulos cuando el elemento a insertar es el más grande o la lista está vacía.
    Node* newNode = new Node;
    newNode->data = data;

    if (head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    LinkedList list;

    list.sortedInsert(10);
    list.sortedInsert(5);
    list.sortedInsert(15);
    list.sortedInsert(7);

    assert(list.get(0) == 5);
    assert(list.get(1) == 7);
    assert(list.get(2) == 10);
    assert(list.get(3) == 15);

    list.clear();
    return 0;
}
