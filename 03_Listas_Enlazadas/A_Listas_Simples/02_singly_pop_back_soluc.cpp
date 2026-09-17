#include <cassert>
#include <cstddef>

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

    // TODO: Implementar pop_back().
    // HINT: 
    // 1. Si la lista está vacía, retornar false.
    // 2. Si la lista tiene un solo elemento (head == tail), liberar el nodo, dejar head y tail en nullptr, actualizar size_ y retornar true.
    // 3. Si tiene más de un elemento, recorrer la lista hasta el penúltimo nodo (curr->next == tail), liberar 'tail', actualizar 'tail' a 'curr', colocar tail->next = nullptr, decrementar size_ y retornar true.
    bool pop_back() {
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    int back() const { return tail ? tail->data : -1; }
};

int main() {
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
    assert(!list.pop_back());

    return 0;
}
