#include <cassert>
#include <cstddef>

class DoublyLinkedList {
private:
    struct DNode {
        int data;
        DNode* prev = nullptr;
        DNode* next = nullptr;
    };

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

    // TODO: Corregir el bug en la reconexión hacia atrás en push_back().
    // BUG: El recorrido hacia adelante funciona correctamente, pero el recorrido hacia atrás
    // falla o causa lecturas de memoria inválida porque se omite la actualización de 'newNode->prev'.
    // HINT: Asegurar que 'newNode->prev' apunte a 'tail' antes de actualizar 'tail = newNode'.
    void push_back(int val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        // BUG: Falta asignar newNode->prev = tail;
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
    DoublyLinkedList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);

    int fwd[] = {10, 20, 30};
    int bwd[] = {30, 20, 10};

    assert(dll.verify_forward(fwd, 3));
    assert(dll.verify_backward(bwd, 3));

    return 0;
}
