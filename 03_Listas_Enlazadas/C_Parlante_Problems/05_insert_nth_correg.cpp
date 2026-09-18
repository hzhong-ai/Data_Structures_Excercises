#include "LinkedList.h"

void LinkedList::insertNth(int index, int data) {
    // Hint: Analiza qué ocurre si la inserción es en el índice 0 y cómo no perder los nodos subsecuentes.
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    current->next = newNode;
}

int main() {
    LinkedList list;

    list.insertNth(0, 13);
    list.insertNth(1, 42);
    list.insertNth(1, 5);

    assert(list.get(0) == 13);
    assert(list.get(1) == 5);
    assert(list.get(2) == 42);

    list.clear();
    return 0;
}
