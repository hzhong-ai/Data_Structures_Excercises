#include <cassert>
#include <cstddef>

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

    // TODO: Corregir la copia superficial (Shallow Copy) para evitar el error de Double Free.
    // HINT: Reserva un nuevo bloque de memoria con 'new' y realiza una copia profunda (Deep Copy).
    SafeArray(const SafeArray& otro) {
        // pon tu codigo aqui
        // PSEUDOSOLUCIÓN / ERROR: Apunta al mismo bloque de memoria
        count = otro.count;
        values = otro.values;
    }

    // TODO: Implementar el operador de asignación evitando fugas de memoria y auto-asignación.
    // HINT: Libera 'values' previo a asignar, valida (this != &otro) y realiza Deep Copy.
    SafeArray& operator=(const SafeArray& otro) {
        // pon tu codigo aqui
        // PSEUDOSOLUCIÓN / ERROR: Copia superficial que causará conflicto al destruir
        count = otro.count;
        values = otro.values;
        return *this;
    }
};

void procesar_copia(SafeArray arr) {
    arr.set(0, 999);
}

int main() {
    SafeArray original(3);
    assert(original.get(0) == 10);

    procesar_copia(original);

    assert(original.get(0) == 10);

    return 0;
}
