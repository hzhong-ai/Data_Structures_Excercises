#include <iostream>
#include <cassert>
#include <stdexcept>

// ============================================================================
// EVALUACIÓN - SECCIÓN 02: Stack (Pila con Arreglos Dinámicos)
// OBJETIVO: Identificar y corregir un error de Underflow en el método pop().
// ============================================================================

template <typename T>
class ArrayStack {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

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
    explicit ArrayStack(size_t init_cap = 4) : capacity(init_cap) {
        data = new T[capacity];
    }

    ~ArrayStack() {
        delete[] data;
    }

    void push(const T& val) {
        if (size == capacity) {
            reallocate(capacity * 2);
        }
        data[size++] = val;
    }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: IDENTIFICAR Y CORREGIR EL BUG EN POP()
    // ========================================================================
    // BUG: Este pop() causa un Segmentation Fault cuando el Stack está vacío. Corrige el caso especial (Underflow).
    void pop() {
        // BUG: Este pop() causa un Segmentation Fault cuando el Stack está vacío. Corrige el caso especial (Underflow).
        // CÓDIGO CON BUG (Descomentar/Modificar para corregir):
        // size--; // <- Si size ya es 0, size pasa a ser 18446744073709551615 (underflow de size_t)!
        
        if (empty()) {
            std::cout << "⚠️ Advertencia: Intento de pop() en Stack vacío bloqueado (Underflow evitado).\n";
            return; // o lanzar std::underflow_error("Stack vacío");
        }
        size--;
    }

    T top() const {
        if (empty()) {
            throw std::underflow_error("Stack vacío");
        }
        return data[size - 1];
    }

    bool empty() const {
        return size == 0;
    }

    size_t get_size() const {
        return size;
    }
};

// ============================================================================
// BATERÍA DE PRUEBAS AUTOMÁTICAS
// ============================================================================
int main() {
    std::cout << "--- [02] PRUEBA: Stack y Corrección de Bug de Underflow ---\n";

    ArrayStack<int> s(2);
    s.push(10);
    s.push(20);
    s.push(30); // Provoca reallocate

    assert(s.get_size() == 3);
    assert(s.top() == 30);

    s.pop();
    assert(s.top() == 20);
    s.pop();
    assert(s.top() == 10);
    s.pop();

    assert(s.empty());

    // TEST DEL BUG: Llamar a pop() cuando la pila está vacía no debe provocar
    // Underflow de size_t ni Segmentation Fault.
    s.pop(); // ¡Esta línea causaba el desastre!
    assert(s.empty());
    assert(s.get_size() == 0);

    std::cout << "✅ [PASS] Evaluación 02: Pila y manejo de Underflow verificado.\n";
    return 0;
}
