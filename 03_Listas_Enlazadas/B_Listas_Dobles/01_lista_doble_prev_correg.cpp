#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-B: Lista Doble y Punteros 'prev'
// TIPO: _correg (Corregir Bug)
// OBJETIVO: Reparar la actualización de enlaces hacia atrás (prev).
// ============================================================================

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val, DNode* p = nullptr, DNode* n = nullptr) : data(val), prev(p), next(n) {}
};

class DoublyLinkedList {
private:
    DNode* head = nullptr;
    DNode* tail = nullptr;

public:
    ~DoublyLinkedList() {
        DNode* curr = head;
        while (curr != nullptr) {
            DNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void push_back(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        // ====================================================================
        // TAREA DEL ESTUDIANTE: IDENTIFICAR Y CORREGIR EL BUG EN PREV
        // ====================================================================
        // BUG: El recorrido hacia adelante funciona, pero hacia atrás se cuelga. Revisa la actualización del puntero 'prev'.
        
        tail->next = newNode;
        newNode->prev = tail; // <- CORRECCIÓN DEL ESTUDIANTE
        tail = newNode;
    }

    bool verify_forward(const int expected[], size_t count) const {
        const DNode* curr = head;
        for (size_t i = 0; i < count; ++i) {
            if (curr == nullptr || curr->data != expected[i]) return false;
            curr = curr->next;
        }
        return curr == nullptr;
    }

    bool verify_backward(const int expected_rev[], size_t count) const {
        const DNode* curr = tail;
        for (size_t i = 0; i < count; ++i) {
            if (curr == nullptr || curr->data != expected_rev[i]) return false;
            curr = curr->prev;
        }
        return curr == nullptr;
    }
};

int main() {
    std::cout << "--- [03-B_correg] PRUEBA: Lista Doble Prev Bug ---\n";

    DoublyLinkedList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);

    int fwd[] = {10, 20, 30};
    int bwd[] = {30, 20, 10};

    assert(dll.verify_forward(fwd, 3));
    assert(dll.verify_backward(bwd, 3));

    std::cout << "✅ [PASS] 01_lista_doble_prev_correg.cpp corregido exitosamente.\n";
    return 0;
}
