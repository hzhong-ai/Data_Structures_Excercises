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

    void push_back(int val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // TODO: Corregir los 3 BUGS en el algoritmo de Insertion Sort para listas dobles.
    //
    // BUG 1 (Pérdida de Puntero al Avanzar): Al extraer 'curr' para moverlo hacia atrás,
    //       se modifica 'curr->next' antes de guardar el puntero al siguiente nodo no procesado,
    //       haciendo imposible continuar el bucle principal.
    //
    // BUG 2 (Desconexión 'prev' al Insertar): Al insertar 'curr' antes del nodo objetivo,
    //       se asignan los enlaces 'next', pero se olvida actualizar el puntero 'prev' del
    //       nodo desplazado, rompiendo la navegación hacia atrás.
    //
    // BUG 3 (Desactualización de Tail): Cuando el último elemento de la lista es desplazado
    //       hacia la izquierda, 'tail' sigue apuntando a él en su posición antigua, dejando
    //       la cola desalineada.
    void insertion_sort() {
        if (!head || !head->next) return;

        DNode* curr = head->next;

        while (curr != nullptr) {
            // BUG 1: Falta guardar el puntero 'next_node' antes de mover 'curr'
            DNode* target = curr->prev;

            // Buscar la posición correcta hacia la izquierda
            while (target != nullptr && target->data > curr->data) {
                target = target->prev;
            }

            // Si se necesita mover el nodo 'curr'
            if (target != curr->prev) {
                // Desconectar 'curr' de su posición actual
                curr->prev->next = curr->next;
                if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                } else {
                    // BUG 3: Se omite actualizar 'tail = curr->prev' al mover el último nodo
                }

                // Reinsertar 'curr' después de 'target' (o en la cabeza si target es nullptr)
                if (target == nullptr) {
                    curr->next = head;
                    curr->prev = nullptr;
                    head->prev = curr;
                    head = curr;
                } else {
                    curr->next = target->next;
                    curr->prev = target;
                    // BUG 2: Falta actualizar target->next->prev = curr si target->next existe
                    target->next = curr;
                }
            }

            // BUG 1: El avance usa 'curr->next', que ya fue sobrescrito durante la recolocación
            curr = curr->next;
        }
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
    dll.push_back(40);
    dll.push_back(10);
    dll.push_back(30);
    dll.push_back(20);

    // Estado inicial:  40 <-> 10 <-> 30 <-> 20
    // Tras ordenado:   10 <-> 20 <-> 30 <-> 40
    dll.insertion_sort();

    int fwd[] = {10, 20, 30, 40};
    int bwd[] = {40, 30, 20, 10};
    assert(dll.verify_forward(fwd, 4));
    assert(dll.verify_backward(bwd, 4));

    return 0;
}
