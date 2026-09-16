#include <iostream>
#include <cassert>

// ============================================================================
// EVALUACIÓN - SECCIÓN 01: Corrección de Copia Superficial (Shallow Copy Bug)
// TIPO: _correg (Corregir Bug)
// OBJETIVO: Reparar la clase para que el pase por valor o copia no cause Double Free.
// ============================================================================

class SafeArray {
private:
    int* values = nullptr;
    size_t count = 0;

public:
    explicit SafeArray(size_t n) : count(n) {
        if (count > 0) {
            values = new int[count];
            for (size_t i = 0; i < count; ++i) values[i] = 10 * (i + 1);
        }
    }

    ~SafeArray() {
        delete[] values;
    }

    int get(size_t i) const { return values[i]; }
    void set(size_t i, int v) { values[i] = v; }
    size_t size() const { return count; }

    // ========================================================================
    // TAREA DEL ESTUDIANTE: IDENTIFICAR Y REPARAR EL BUG DE DOUBLE FREE
    // ========================================================================
    // BUG: La clase usaba la copia por defecto del compilador (Shallow Copy),
    //      haciendo que dos objetos apunten al mismo bloque de memoria. Al destruirse,
    //      se producía un Double Free. Implementa Deep Copy para corregirlo.

    SafeArray(const SafeArray& otro) {
        count = otro.count;
        if (count > 0) {
            values = new int[count];
            for (size_t i = 0; i < count; ++i) {
                values[i] = otro.values[i];
            }
        } else {
            values = nullptr;
        }
    }

    SafeArray& operator=(const SafeArray& otro) {
        if (this != &otro) {
            delete[] values;

            count = otro.count;
            if (count > 0) {
                values = new int[count];
                for (size_t i = 0; i < count; ++i) {
                    values[i] = otro.values[i];
                }
            } else {
                values = nullptr;
            }
        }
        return *this;
    }
};

// Función auxiliar que pasa por valor (Dispara la copia)
void procesar_copia(SafeArray arr) {
    arr.set(0, 999);
}

int main() {
    std::cout << "--- [01_correg] PRUEBA: Corrección de Copia Superficial ---\n";

    SafeArray original(3);
    assert(original.get(0) == 10);

    // Si el estudiante no corrigió la copia, esta llamada destruye los datos de 'original'
    procesar_copia(original);

    // Verificamos que 'original' mantenga sus valores intactos tras la función
    assert(original.get(0) == 10);

    std::cout << "✅ [PASS] 03_copia_superficial_double_free_correg.cpp corregido exitosamente.\n";
    return 0;
}
