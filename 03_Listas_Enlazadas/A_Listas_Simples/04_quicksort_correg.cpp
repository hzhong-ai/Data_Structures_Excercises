#include <cassert>
#include <cstddef>

struct Node {
    int data;
    Node* next;
    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};

// Devuelve el último nodo de la lista
Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

// TODO: Corregir los 3 BUGS en la función de partición para QuickSort.
//
// BUG 1 (Pérdida de Enlace al Mover Nodos): Al mover un nodo menor al pivote a la sublista
//       'newHead', se olvida aislar el nodo (falta 'curr->next = nullptr' o reconexión limpia),
//       dejando punteros colgantes que generan ciclos.
//
// BUG 2 (Desconexión del Pivote): El pivote debe quedar aislado al final de la partición 
//       (pivot->next = nullptr) antes de unirse recursivamente. Al no aislarlo,
//       mantiene enlaces hacia la sublista derecha y duplica elementos.
//
// BUG 3 (Actualización de newEnd): Cuando un nodo es mayor que el pivote, debe enviarse
//       al final de 'newEnd'. La función actual no actualiza el puntero 'newEnd' al nuevo nodo,
//       perdiendo el rastreo de la cola.

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot;

    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*newHead == nullptr) *newHead = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) prev->next = curr->next;
            Node* tmp = curr->next;

            // BUG 1 y 3: Se añade a la cola pero no se corta curr->next ni se actualiza *newEnd
            tail->next = curr;
            tail = curr;

            curr = tmp;
        }
    }

    if (*newHead == nullptr) *newHead = pivot;
    *newEnd = tail;

    // BUG 2: Falta aislar el pivote (*pivot->next = nullptr* o corte explícito)
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node *newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

Node* quickSort(Node* head) {
    return quickSortRecur(head, getTail(head));
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Lista desordenada: 30 -> 10 -> 40 -> 20 -> 50
    Node* head = new Node(30, new Node(10, new Node(40, new Node(20, new Node(50)))));

    head = quickSort(head);

    // Salida esperada: 10 -> 20 -> 30 -> 40 -> 50
    int expected[] = {10, 20, 30, 40, 50};
    Node* curr = head;
    for (int val : expected) {
        assert(curr != nullptr);
        assert(curr->data == val);
        curr = curr->next;
    }
    assert(curr == nullptr);

    freeList(head);
    return 0;
}
