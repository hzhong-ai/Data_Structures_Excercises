#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-B: Eliminación O(1) en Lista Doble (erase_node)
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Desconectar y eliminar un nodo conocido 'p' en tiempo O(1).
// ============================================================================

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val, DNode* p = nullptr, DNode* n = nullptr) : data(val), prev(p), next(n) {}
};

// TODO: Implementa erase_node(p). Asume que p no es nullptr y actualiza los punteros de sus vecinos.
void erase_node(DNode* p) {
    if (p == nullptr) return;

    if (p->prev != nullptr) {
        p->prev->next = p->next;
    }
    if (p->next != nullptr) {
        p->next->prev = p->prev;
    }

    delete p;
}

int main() {
    std::cout << "--- [03-B_soluc] PRUEBA: Eliminación O(1) erase_node ---\n";

    DNode* n1 = new DNode(10);
    DNode* n2 = new DNode(20, n1);
    n1->next = n2;
    DNode* n3 = new DNode(30, n2);
    n2->next = n3;

    // Estado inicial: 10 <-> 20 <-> 30
    assert(n1->next == n2 && n2->next == n3);

    // Eliminar n2 en O(1)
    erase_node(n2);

    // Estado resultante: 10 <-> 30
    assert(n1->next == n3);
    assert(n3->prev == n1);

    delete n1;
    delete n3;

    std::cout << "✅ [PASS] 02_doubly_erase_node_soluc.cpp completado exitosamente.\n";
    return 0;
}
