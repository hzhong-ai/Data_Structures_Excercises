#include <cassert>
#include <cstddef>

class DinamicBuffer {
private:
    int* data = nullptr;
    size_t capacity = 0;

public:
    explicit DinamicBuffer(size_t cap) : capacity(cap) {
        if (capacity > 0) {
            data = new int[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                data[i] = 0;
            }
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

    // TODO: Libera la memoria del arreglo dinámico asignado en el Heap.
    ~DinamicBuffer() {
        // pon tu codigo aqui
        delete[] data;
        data = nullptr;
    }

    // TODO: Realiza una copia profunda de 'otro'. Asigna nueva memoria y copia sus elementos.
    DinamicBuffer(const DinamicBuffer& otro) {
        // pon tu codigo aqui
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

    // TODO: Evita la fuga de memoria al reasignar el puntero. Verifica si (this != &otro) antes de borrar.
    DinamicBuffer& operator=(const DinamicBuffer& otro) {
        // pon tu codigo aqui
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
    DinamicBuffer b1(5);
    b1.set(0, 100);
    b1.set(1, 200);

    DinamicBuffer b2 = b1;
    assert(b2.get(0) == 100);
    assert(b2.get(1) == 200);

    b2.set(0, 999);
    assert(b1.get(0) == 100);
    assert(b2.get(0) == 999);

    DinamicBuffer b3(2);
    b3 = b1;
    assert(b3.get(0) == 100);
    assert(b3.get(1) == 200);

    b3 = b3;
    assert(b3.get(0) == 100);

    return 0;
}
