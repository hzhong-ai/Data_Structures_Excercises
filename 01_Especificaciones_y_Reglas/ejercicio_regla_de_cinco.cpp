#include <iostream>
#include <cassert>
#include <algorithm>

// ============================================================================
// EVALUACIÓN - SECCIÓN 01: Regla de los 3 / Regla de los 5
// OBJETIVO: Gestionar correctamente la memoria dinámica (Heap) y evitar 
//           copias superficiales (Shallow Copy) que producen Double Free.
// ============================================================================

class DinamicBuffer {
private:
    int* data = nullptr;
    size_t capacity = 0;

public:
    // Constructor con tamaño inicial
    explicit DinamicBuffer(size_t cap) : capacity(cap) {
        if (capacity > 0) {
            data = new int[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                data[i] = 0;
            }
        }
    }

    // Helper para establecer valores
    void set(size_t index, int val) {
        if (index < capacity) data[index] = val;
    }

    // Helper para leer valores
    int get(size_t index) const {
        if (index < capacity) return data[index];
        return -1;
    }

    size_t get_capacity() const { return capacity; }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: IMPLEMENTAR LA REGLA DE LOS TRES (DEEP COPY)
    // ========================================================================

    // 1. DESTRUCTOR
    // TODO: Libera la memoria del arreglo dinámico asignado en el Heap.
    ~DinamicBuffer() {
        // ESCRIBE TU CÓDIGO AQUÍ
        delete[] data;
        data = nullptr;
    }

    // 2. CONSTRUCTOR DE COPIA (Deep Copy)
    // TODO: Realiza una copia profunda de 'otro'. Asigna nueva memoria y copia sus elementos.
    DinamicBuffer(const DinamicBuffer& otro) {
        // ESCRIBE TU CÓDIGO AQUÍ
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

    // 3. OPERADOR DE ASIGNACIÓN POR COPIA
    // TODO: Evita la fuga de memoria al reasignar el puntero. Pista: Verifica si (this != &otro) antes de borrar.
    DinamicBuffer& operator=(const DinamicBuffer& otro) {
        // ESCRIBE TU CÓDIGO AQUÍ
        // TODO: Evita la fuga de memoria al reasignar el puntero. Pista: Verifica si (this != &otro) antes de borrar.
        if (this != &otro) {
            delete[] data; // Liberar memoria previa
            
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

// ============================================================================
// BATERÍA DE PRUEBAS AUTOMÁTICAS
// ============================================================================
int main() {
    std::cout << "--- [01] PRUEBA: Regla de los Tres (Deep Copy) ---\n";

    // Test 1: Creación y modificación
    DinamicBuffer b1(5);
    b1.set(0, 100);
    b1.set(1, 200);

    // Test 2: Constructor de copia
    DinamicBuffer b2 = b1; // Invoca Constructor de Copia
    assert(b2.get(0) == 100);
    assert(b2.get(1) == 200);

    // Modificar b2 no debe alterar b1 (Independencia de memoria / Deep Copy)
    b2.set(0, 999);
    assert(b1.get(0) == 100);
    assert(b2.get(0) == 999);

    // Test 3: Operador de asignación
    DinamicBuffer b3(2);
    b3 = b1; // Invoca operator=
    assert(b3.get(0) == 100);
    assert(b3.get(1) == 200);

    // Test 4: Auto-asignación (this != &otro)
    b3 = b3;
    assert(b3.get(0) == 100);

    std::cout << "✅ [PASS] Evaluación 01: Regla de los Tres completada exitosamente.\n";
    return 0;
}
