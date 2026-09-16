#include <iostream>
#include <cassert>
#include <stdexcept>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-A: SinglyLinkedList pop_back() e Invariantes
// OBJETIVO: Eliminar el último elemento de una lista manteniendo head y tail.
// ============================================================================

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val, Node* n = nullptr) : data(val), next(n) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t size_ = 0;

public:
    SinglyLinkedList() = default;

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size_ = 0;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size_++;
    }

    // TODO: Implementa la eliminación del último elemento en la lista.
    // Asegúrate de actualizar 'tail' al penúltimo nodo y dejar 'head' y 'tail' en nullptr si la lista se vacía.
    bool pop_back() {
        if (head == nullptr) return false;

        // Caso 1: Solo 1 nodo
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size_ = 0;
            return true;
        }

        // Caso 2: Más de 1 nodo (Localizar el penúltimo)
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }

        delete tail;
        tail = curr;
        tail->next = nullptr;
        size_--;
        return true;
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    int back() const { return tail ? tail->data : -1; }
    int front() const { return head ? head->data : -1; }
};

int main() {
    std::cout << "--- [03-A] PRUEBA: SinglyLinkedList pop_back() ---\n";

    SinglyLinkedList list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    assert(list.size() == 3);
    assert(list.back() == 300);

    assert(list.pop_back());
    assert(list.size() == 2);
    assert(list.back() == 200);

    assert(list.pop_back());
    assert(list.pop_back());

    assert(list.empty());
    assert(!list.pop_back());

    std::cout << "✅ [PASS] Evaluación 03-A (pop_back) completada exitosamente.\n";
    return 0;
}
