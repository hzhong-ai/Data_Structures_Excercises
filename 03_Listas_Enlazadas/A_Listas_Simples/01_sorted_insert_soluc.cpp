#include <cassert>
#include <cstddef>

struct Node {
    int data;
    Node* next;
    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};

// TODO: Implementar la inserción ordenada de 'newNode' en la lista enlazada apuntada por 'headRef'.
// HINT: Rastrear el nodo anterior ('prev') y el actual ('current') para insertar en la posición correcta.
// Manejar correctamente el caso límite en que el nodo deba insertarse en la cabeza (prev == nullptr).
void SortedInsert(Node** headRef, Node* newNode) {
    // TODO
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    SortedInsert(&head, new Node(30));
    SortedInsert(&head, new Node(10));
    SortedInsert(&head, new Node(40));
    SortedInsert(&head, new Node(20));

    int expected[] = {10, 20, 30, 40};
    Node* curr = head;
    int i = 0;

    while (i < 4) {
        assert(curr != nullptr);
        assert(curr->data == expected[i]);
        curr = curr->next;
        i++;
    }

    assert(curr == nullptr);

    freeList(head);
    return 0;
}

