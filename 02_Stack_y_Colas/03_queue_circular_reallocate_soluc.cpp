#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 02: Cola Circular Dinámica (Reallocate)
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Implementar la des-circularización del arreglo durante la reasignación.
// ============================================================================

template <typename T>
class CircularQueue {
private:
    T* data = nullptr;
    size_t head = 0;
    size_t size = 0;
    size_t capacity = 0;

    // TODO: Redimensiona y des-circulariza el arreglo en un nuevo bloque lineal.
    // Fórmula de acceso al elemento i en la cola circular: (head + i) % capacity
    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[(head + i) % capacity];
        }
        delete[] data;
        data = new_data;
        head = 0;
        capacity = new_cap;
    }

public:
    explicit CircularQueue(size_t cap = 3) : capacity(cap) {
        data = new T[capacity];
    }

    ~CircularQueue() { delete[] data; }

    void push(const T& val) {
        if (size == capacity) {
            reallocate(capacity * 2);
        }
        size_t tail = (head + size) % capacity;
        data[tail] = val;
        size++;
    }

    void pop() {
        if (size > 0) {
            head = (head + 1) % capacity;
            size--;
        }
    }

    T front() const { return data[head]; }
    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
};

int main() {
    std::cout << "--- [02_soluc] PRUEBA: Cola Circular Reallocate ---\n";

    CircularQueue<int> q(3);
    q.push(10);
    q.push(20);
    q.push(30);

    q.pop(); // Libera 10 (head avanza a 1)
    q.push(40); // Insertar circular en posición 0

    assert(q.front() == 20);

    // Forzar reallocate en estado circular
    q.push(50);

    assert(q.front() == 20);
    assert(q.get_size() == 4);

    q.pop(); assert(q.front() == 30);
    q.pop(); assert(q.front() == 40);
    q.pop(); assert(q.front() == 50);

    std::cout << "✅ [PASS] 03_queue_circular_reallocate_soluc.cpp completado exitosamente.\n";
    return 0;
}
