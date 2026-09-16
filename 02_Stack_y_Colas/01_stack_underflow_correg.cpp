#include <iostream>
#include <cassert>
#include <stdexcept>

// ============================================================================
// EVALUACIÓN - SECCIÓN 02: Stack y Corrección de Underflow
// TIPO: _correg (Corregir Bug)
// OBJETIVO: Prevenir la corrupción de size_t en pop() cuando la pila está vacía.
// ============================================================================

template <typename T>
class ArrayStack {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size; ++i) new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

public:
    explicit ArrayStack(size_t init_cap = 4) : capacity(init_cap) {
        data = new T[capacity];
    }

    ~ArrayStack() { delete[] data; }

    void push(const T& val) {
        if (size == capacity) reallocate(capacity * 2);
        data[size++] = val;
    }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: IDENTIFICAR Y CORREGIR EL BUG EN POP()
    // ========================================================================
    // BUG: Este pop() causa un Segmentation Fault cuando el Stack está vacío. Corrige el caso especial (Underflow).
    void pop() {
        // BUG: Este pop() causa un Segmentation Fault cuando el Stack está vacío. Corrige el caso especial (Underflow).
        if (empty()) {
            return; // Bloquea el underflow de size
        }
        size--;
    }

    T top() const {
        if (empty()) throw std::underflow_error("Stack vacío");
        return data[size - 1];
    }

    bool empty() const { return size == 0; }
    size_t get_size() const { return size; }
};

int main() {
    std::cout << "--- [02_correg] PRUEBA: Stack Underflow Bug ---\n";

    ArrayStack<int> s(2);
    s.push(10);
    s.push(20);

    s.pop();
    assert(s.top() == 10);
    s.pop();
    assert(s.empty());

    // TEST DEL BUG: Llamar pop() en pila vacía no debe corromper el tamaño
    s.pop();
    assert(s.empty());
    assert(s.get_size() == 0);

    std::cout << "✅ [PASS] 01_stack_underflow_correg.cpp corregido exitosamente.\n";
    return 0;
}
