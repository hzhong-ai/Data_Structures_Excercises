#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 02: Stack Dinámico con Redimensionamiento
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Implementar la reasignación de memoria al doble de capacidad.
// ============================================================================

template <typename T>
class ResizableStack {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    // TODO: Implementa reallocate(new_cap). Debe crear nuevo arreglo, copiar y liberar el anterior.
    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

public:
    explicit ResizableStack(size_t init_cap = 2) : capacity(init_cap) {
        data = new T[capacity];
    }

    ~ResizableStack() {
        delete[] data;
    }

    // TODO: Implementa push. Debe llamar a reallocate(capacity * 2) si size == capacity.
    void push(const T& val) {
        if (size == capacity) {
            reallocate(capacity * 2);
        }
        data[size++] = val;
    }

    void pop() {
        if (size > 0) size--;
    }

    T top() const {
        return data[size - 1];
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
};

int main() {
    std::cout << "--- [02_soluc] PRUEBA: Stack Redimensionable ---\n";

    ResizableStack<int> s(2);
    assert(s.get_capacity() == 2);

    s.push(100);
    s.push(200);
    assert(s.get_capacity() == 2);

    // Provoca reallocate al doble (capacidad pasa a 4)
    s.push(300);
    assert(s.get_capacity() == 4);
    assert(s.get_size() == 3);
    assert(s.top() == 300);

    std::cout << "✅ [PASS] 02_stack_dynamic_resize_soluc.cpp completado exitosamente.\n";
    return 0;
}
