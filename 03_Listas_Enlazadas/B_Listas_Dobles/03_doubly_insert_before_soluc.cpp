#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-B: Inserción General insert_before()
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Insertar un nuevo nodo inmediatamente ANTES del nodo 'position'.
// ============================================================================

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val, DNode* p = nullptr, DNode* n = nullptr) : data(val), prev(p), next(n) {}
};

// TODO: Implementa insert_before(position, value). Inserta un nodo con 'value' antes de 'position'.
void insert_before(DNode* position, int value) {
    if (position == nullptr) return;

    DNode* newNode = new DNode(value, position->prev, position);

    if (position->prev != nullptr) {
        position->prev->next = newNode;
    }
    position->prev = newNode;
}

int main() {
    std::cout << "--- [03-B_soluc] PRUEBA: Inserción insert_before() ---\n";

    DNode* n1 = new DNode(10);
    DNode* n2 = new DNode(30, n1);
    n1->next = n2;

    // Insertar 20 antes de n2 (30)
    insert_before(n2, 20);

    // Estado: 10 <-> 20 <-> 30
    DNode* inserted = n1->next;
    assert(inserted != nullptr && inserted->data == 20);
    assert(inserted->prev == n1);
    assert(inserted->next == n2);
    assert(n2->prev == inserted);

    delete n1;
    delete inserted;
    delete n2;

    std::cout << "✅ [PASS] 03_doubly_insert_before_soluc.cpp completado exitosamente.\n";
    return 0;
}
