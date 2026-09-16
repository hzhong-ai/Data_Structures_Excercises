#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-B: Lista Doblemente Enlazada (Bug en 'prev')
// OBJETIVO: Detectar y reparar un bug sutil en la actualización de 'prev'.
// ============================================================================

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val, DNode* p = nullptr, DNode* n = nullptr)
        : data(val), prev(p), next(n) {}
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

    // Insertar al final con bug sutil en prev
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
        
        // BUG ORIGINAL: Se olvidaba asignar newNode->prev = tail;
        newNode->prev = tail; // <- CORRECCIÓN DEL ESTUDIANTE
        
        tail = newNode;
    }

    // Inversión recursiva adaptada a listas dobles
    void reverse_recursive(DNode** headRef) {
        if (headRef == nullptr || *headRef == nullptr) return;

        DNode* curr = *headRef;
        DNode* temp = curr->prev;

        // Intercambiar next y prev de cada nodo
        curr->prev = curr->next;
        curr->next = temp;

        if (curr->prev == nullptr) {
            *headRef = curr; // Nuevo head
            return;
        }

        DNode* nextNode = curr->prev;
        reverse_recursive(&nextNode);
    }

    // Recorrido hacia adelante
    bool verify_forward(const int expected[], size_t count) const {
        const DNode* curr = head;
        for (size_t i = 0; i < count; ++i) {
            if (curr == nullptr || curr->data != expected[i]) return false;
            curr = curr->next;
        }
        return curr == nullptr;
    }

    // Recorrido hacia atrás (Se cuelga o falla si prev está mal asignado)
    bool verify_backward(const int expected_rev[], size_t count) const {
        const DNode* curr = tail;
        for (size_t i = 0; i < count; ++i) {
            if (curr == nullptr || curr->data != expected_rev[i]) return false;
            curr = curr->prev; // ⚡ Si prev está en nullptr, falla aquí
        }
        return curr == nullptr;
    }
};

int main() {
    std::cout << "--- [03-B] PRUEBA: Lista Doblemente Enlazada (Bug en prev) ---\n";

    DoublyLinkedList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);

    int fwd[] = {10, 20, 30, 40};
    int bwd[] = {40, 30, 20, 10};

    // 1. Verificación hacia adelante
    assert(dll.verify_forward(fwd, 4));

    // 2. Verificación hacia atrás (Demuestra el bug si prev no fue enlazado)
    assert(dll.verify_backward(bwd, 4));

    std::cout << "✅ [PASS] Evaluación 03-B: Lista Doble y punteros 'prev' verificados correctamente.\n";
    return 0;
}
