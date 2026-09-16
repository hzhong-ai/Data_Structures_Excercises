#include <iostream>
#include <cassert>
#include <utility>

// ============================================================================
// EVALUACIÓN - SECCIÓN 01: Regla de los Cinco (Move Semantics)
// TIPO: _soluc (Proponer Solución)
// OBJETIVO: Implementar Constructor de Movimiento y Asignación por Movimiento
//           robando recursos sin duplicar memoria.
// ============================================================================

class MoveArray {
private:
    int* data = nullptr;
    size_t size = 0;

public:
    explicit MoveArray(size_t sz) : size(sz) {
        if (size > 0) {
            data = new int[size];
            for (size_t i = 0; i < size; ++i) data[i] = static_cast<int>(i + 1);
        }
    }

    ~MoveArray() {
        delete[] data;
    }

    size_t get_size() const { return size; }
    int* get_data() const { return data; }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: IMPLEMENTAR MOVE CONSTRUCTOR Y MOVE ASSIGNMENT
    // ========================================================================

    // 1. Constructor de Movimiento (Move Constructor)
    // TODO: Roba el puntero 'data' y el 'size' de 'otro'. Deja 'otro.data' en nullptr.
    MoveArray(MoveArray&& otro) noexcept 
        : data(otro.data), size(otro.size) {
        otro.data = nullptr;
        otro.size = 0;
    }

    // 2. Operador de Asignación por Movimiento (Move Assignment)
    // TODO: Libera la memoria actual, roba los recursos de 'otro' y limpia 'otro'.
    MoveArray& operator=(MoveArray&& otro) noexcept {
        if (this != &otro) {
            delete[] data;

            data = otro.data;
            size = otro.size;

            otro.data = nullptr;
            otro.size = 0;
        }
        return *this;
    }
};

int main() {
    std::cout << "--- [01_soluc] PRUEBA: Regla de los Cinco (Move Semantics) ---\n";

    MoveArray a(5);
    int* original_ptr = a.get_data();

    // Mover a -> b
    MoveArray b = std::move(a);

    assert(b.get_data() == original_ptr); // Mismo puntero físico (sin copia)
    assert(b.get_size() == 5);
    assert(a.get_data() == nullptr);     // Fuente limpiada
    assert(a.get_size() == 0);

    // Asignación por movimiento
    MoveArray c(2);
    c = std::move(b);

    assert(c.get_data() == original_ptr);
    assert(b.get_data() == nullptr);

    std::cout << "✅ [PASS] 02_regla_de_cinco_movimiento_soluc.cpp completado exitosamente.\n";
    return 0;
}
