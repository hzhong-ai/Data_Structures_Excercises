#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 02: Depuración de Cola Circular
// TIPO: _correg (Corregir Bug)
// OBJETIVO: Corregir un error donde pop() olvida decrementar size_.
// ============================================================================

class QueueBug {
private:
    int* data = nullptr;
    size_t head = 0;
    size_t size_ = 0;
    size_t capacity = 0;

public:
    explicit QueueBug(size_t cap = 5) : capacity(cap) {
        data = new int[capacity];
    }

    ~QueueBug() { delete[] data; }

    void push(int val) {
        if (size_ < capacity) {
            size_t tail = (head + size_) % capacity;
            data[tail] = val;
            size_++;
        }
    }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: CORREGIR EL BUG EN POP()
    // ========================================================================
    // BUG: Este pop() hace avanzar el puntero 'head' pero no decrementa 'size_',
    //      haciendo que la cola crea que sigue llena. Corrígelo.
    void pop() {
        if (size_ > 0) {
            head = (head + 1) % capacity;
            size_--; // <- CORRECCIÓN DEL ESTUDIANTE
        }
    }

    int front() const { return data[head]; }
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
};

int main() {
    std::cout << "--- [02_correg] PRUEBA: Corrección de Bug en Queue pop() ---\n";

    QueueBug q(3);
    q.push(1);
    q.push(2);

    assert(q.size() == 2);
    assert(q.front() == 1);

    q.pop();

    // Sin la corrección, q.size() seguiría siendo 2 en lugar de 1
    assert(q.size() == 1);
    assert(q.front() == 2);

    q.pop();
    assert(q.empty());

    std::cout << "✅ [PASS] 04_queue_head_tail_bug_correg.cpp corregido exitosamente.\n";
    return 0;
}
