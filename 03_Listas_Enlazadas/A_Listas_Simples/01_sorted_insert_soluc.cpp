#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-A: Listas Simples (SortedInsert)
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Implementar inserción ordenada en una lista simplemente enlazada.
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
    Node* current = *headRef;
    Node* prev = nullptr;

    while (current != nullptr && current->data < newNode->data) {
        prev = current;
        current = current->next;
    }

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
    std::cout << "--- [03-A_soluc] PRUEBA: SortedInsert en Lista Simple ---\n";

    Node* head = nullptr;
    SortedInsert(&head, new Node(30));
    SortedInsert(&head, new Node(10));
    SortedInsert(&head, new Node(40));
    SortedInsert(&head, new Node(20));

    int expected[] = {10, 20, 30, 40};
    Node* curr = head;
    for (int val : expected) {
        assert(curr != nullptr);
        assert(curr->data == val);
        curr = curr->next;
    }
    assert(curr == nullptr);

    freeList(head);
    std::cout << "✅ [PASS] 01_sorted_insert_soluc.cpp completado exitosamente.\n";
    return 0;
}
