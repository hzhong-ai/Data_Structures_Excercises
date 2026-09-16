#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 01: Regla de los Tres (Deep Copy)
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Implementar la Regla de los Tres para una clase que administra
//           un arreglo dinámico en el Heap.
// ============================================================================

class DynamicBuffer {
private:
    int* data = nullptr;
    size_t capacity = 0;

public:
    explicit DynamicBuffer(size_t cap = 0) : capacity(cap) {
        if (capacity > 0) {
            data = new int[capacity];
            for (size_t i = 0; i < capacity; ++i) data[i] = 0;
        }
    }

    void set(size_t index, int val) {
        if (index < capacity) data[index] = val;
    }

    int get(size_t index) const {
        if (index < capacity) return data[index];
        return -1;
    }

    size_t get_capacity() const { return capacity; }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: IMPLEMENTAR DESTRUCTOR, CONSTRUCTOR DE COPIA Y OPERATOR=
    // ========================================================================

    // 1. Destructor
    ~DynamicBuffer() {
        delete[] data;
        data = nullptr;
    }

    // 2. Constructor de Copia (Deep Copy)
    DynamicBuffer(const DynamicBuffer& otro) {
        capacity = otro.capacity;
        if (capacity > 0) {
            data = new int[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                data[i] = otro.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // 3. Operador de Asignación por Copia
    // TODO: Evita la fuga de memoria al reasignar el puntero. Pista: Verifica si (this != &otro) antes de borrar.
    DynamicBuffer& operator=(const DynamicBuffer& otro) {
        // TODO: Evita la fuga de memoria al reasignar el puntero. Pista: Verifica si (this != &otro) antes de borrar.
        if (this != &otro) {
            delete[] data;

            capacity = otro.capacity;
            if (capacity > 0) {
                data = new int[capacity];
                for (size_t i = 0; i < capacity; ++i) {
                    data[i] = otro.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }
};

int main() {
    std::cout << "--- [01_soluc] PRUEBA: Regla de los Tres ---\n";

    DynamicBuffer b1(4);
    b1.set(0, 42);
    b1.set(1, 84);

    // Constructor de copia
    DynamicBuffer b2 = b1;
    assert(b2.get(0) == 42);

    // Modificar b2 no altera b1 (Deep Copy)
    b2.set(0, 999);
    assert(b1.get(0) == 42);
    assert(b2.get(0) == 999);

    // Operador de asignación
    DynamicBuffer b3(2);
    b3 = b1;
    assert(b3.get(0) == 42);

    // Auto-asignación
    b3 = b3;
    assert(b3.get(0) == 42);

    std::cout << "✅ [PASS] 01_regla_de_tres_soluc.cpp completado exitosamente.\n";
    return 0;
}
