#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 03-A: SinglyLinkedList pop_back()
// TIPO: _soluc (Proponer Solución)
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

    // TODO: Implementa pop_back(). Si la lista queda vacía, deja head y tail en nullptr.
    bool pop_back() {
        if (head == nullptr) return false;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size_ = 0;
            return true;
        }

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
};

int main() {
    std::cout << "--- [03-A_soluc] PRUEBA: SinglyLinkedList pop_back() ---\n";

    SinglyLinkedList list;
    list.push_back(100);
    list.push_back(200);

    assert(list.size() == 2);
    assert(list.back() == 200);

    assert(list.pop_back());
    assert(list.size() == 1);
    assert(list.back() == 100);

    assert(list.pop_back());
    assert(list.empty());

    std::cout << "✅ [PASS] 02_singly_pop_back_soluc.cpp completado exitosamente.\n";
    return 0;
}
