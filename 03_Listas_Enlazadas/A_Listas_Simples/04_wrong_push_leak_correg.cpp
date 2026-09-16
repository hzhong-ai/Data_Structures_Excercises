#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-A: Depuración de Inserción (WrongPush Leak)
// TIPO: _correg (Corregir Bug)
// OBJETIVO: Corregir paso por valor de la cabeza y evitar fugas de memoria.
// ============================================================================

struct Node {
    int data;
    Node* next;
    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};

// ============================================================================
// TAREA DEL ESTUDIANTE: CORREGIR EL BUG DE PASO POR VALOR DE LA CABEZA
// ============================================================================
// BUG: Esta función recibía 'Node* head' por valor. La inserción se perdía en la pila
//      y producía fuga de memoria. Corrige el parámetro para que reciba 'Node** headRef'.

void Push(Node** headRef, int data) {
    Node* newNode = new Node(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    std::cout << "--- [03-A_correg] PRUEBA: Corrección de WrongPush ---\n";

    Node* head = nullptr;

    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);

    assert(head != nullptr);
    assert(head->data == 30);
    assert(head->next->data == 20);
    assert(head->next->next->data == 10);

    freeList(head);
    std::cout << "✅ [PASS] 04_wrong_push_leak_correg.cpp corregido exitosamente.\n";
    return 0;
}
