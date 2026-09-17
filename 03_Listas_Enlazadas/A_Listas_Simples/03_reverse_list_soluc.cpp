#include <cassert>
#include <cstddef>

struct Node {
    int data;
    Node* next;
    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};

// TODO: Implementar la inversión de una lista simplemente enlazada in-place.
// HINT: 
// 1. Rastrear tres punteros durante el recorrido: 'prev' (inicialmente nullptr),
//    'current' (inicialmente *headRef) y 'next_node' (para guardar current->next).
// 2. En cada iteración, invertir el enlace: current->next = prev.
// 3. Avanzar 'prev' a 'current' y 'current' a 'next_node'.
// 4. Al finalizar el bucle, actualizar *headRef al nuevo primer nodo ('prev').
void ReverseList(Node** headRef) {
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Crear lista original: 10 -> 20 -> 30 -> 40 -> nullptr
    Node* head = new Node(10, new Node(20, new Node(30, new Node(40))));

    // Invertir lista
    ReverseList(&head);

    // Salida esperada: 40 -> 30 -> 20 -> 10 -> nullptr
    int expected[] = {40, 30, 20, 10};
    Node* curr = head;
    for (int val : expected) {
        assert(curr != nullptr);
        assert(curr->data == val);
        curr = curr->next;
    }
    assert(curr == nullptr);

    freeList(head);
    return 0;
}
