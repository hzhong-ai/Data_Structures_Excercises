#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-A: Detección de Ciclos (Algoritmo de Floyd)
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Usar punteros lento (slow) y rápido (fast) para detectar si hay ciclo.
// ============================================================================

struct Node {
    int data;
    Node* next;
    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};

// TODO: Implementa la detección de ciclo mediante la Liebre y la Tortuga (Floyd's Cycle Finding)
bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Hay ciclo!
        }
    }

    return false;
}

int main() {
    std::cout << "--- [03-A_soluc] PRUEBA: Detección de Ciclos de Floyd ---\n";

    // Test 1: Lista sin ciclo (1 -> 2 -> 3 -> nullptr)
    Node* n3 = new Node(3);
    Node* n2 = new Node(2, n3);
    Node* n1 = new Node(1, n2);

    assert(!hasCycle(n1));

    // Test 2: Crear ciclo (3 -> 2)
    n3->next = n2;
    assert(hasCycle(n1));

    // Limpieza manual de ciclo para evitar bucle infinito en delete
    n3->next = nullptr;
    delete n1; delete n2; delete n3;

    std::cout << "✅ [PASS] 03_detect_cycle_floyd_soluc.cpp completado exitosamente.\n";
    return 0;
}
