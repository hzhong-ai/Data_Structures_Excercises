#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-A: Listas Simplemente Enlazadas (SortedInsert)
// OBJETIVO: Implementar la inserción ordenada en una lista enlazada simple.
// ============================================================================

struct Node {
    int data;
    Node* next;
    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};

// ============================================================================
// TAREA DEL ESTUDIANTE: IMPLEMENTAR LA INSERCIÓN ORDENADA
// ============================================================================
// TODO: Implementa la inserción ordenada. Pista: Necesitas rastrear el nodo 'previo' y el 'actual'.
void SortedInsert(Node** headRef, Node* newNode) {
    // TODO: Implementa la inserción ordenada. Pista: Necesitas rastrear el nodo 'previo' y el 'actual'.
    // (O alternativamente utilizar el puntero doble iterador struct node** currentRef)

    Node* current = *headRef;
    Node* prev = nullptr;

    // Buscar la posición correcta de inserción
    while (current != nullptr && current->data < newNode->data) {
        prev = current;
        current = current->next;
    }

    // Insertar al inicio o si la lista está vacía
    if (prev == nullptr) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    std::cout << "--- [03-A] PRUEBA: Lista Simple (SortedInsert) ---\n";

    Node* head = nullptr;

    SortedInsert(&head, new Node(30));
    SortedInsert(&head, new Node(10));
    SortedInsert(&head, new Node(40));
    SortedInsert(&head, new Node(20));

    // Verificación
    int expected[] = {10, 20, 30, 40};
    Node* curr = head;
    for (int val : expected) {
        assert(curr != nullptr);
        assert(curr->data == val);
        curr = curr->next;
    }
    assert(curr == nullptr);

    freeList(head);
    std::cout << "✅ [PASS] Evaluación 03-A (SortedInsert) completada exitosamente.\n";
    return 0;
}
