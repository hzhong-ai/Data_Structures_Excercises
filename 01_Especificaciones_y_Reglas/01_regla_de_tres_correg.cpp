#include <cassert>
#include <cstddef>

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

    ~DynamicBuffer() {
        delete[] data;
    }

    // TODO: Corregir copia superficial (shallow copy). Realizar reserva en el heap.
    // HINT: Reserva memoria con 'new' y copia elemento por elemento para lograr Deep Copy.
    DynamicBuffer(const DynamicBuffer& otro) {
        capacity = otro.capacity;
        data = otro.data;
    }

    // TODO: Implementar asignación segura evitando fugas de memoria y auto-asignación.
    // HINT: Libera 'data' previo a asignar, valida (this != &otro) y copia el buffer.
    DynamicBuffer& operator=(const DynamicBuffer& otro) {
        capacity = otro.capacity;
        data = otro.data;
        return *this;
    }
};

int main() {
    DynamicBuffer b1(4);
    b1.set(0, 42);
    b1.set(1, 84);

    DynamicBuffer b2 = b1;
    assert(b2.get(0) == 42);

    b2.set(0, 999);
    assert(b1.get(0) == 42);
    assert(b2.get(0) == 999);

    DynamicBuffer b3(2);
    b3 = b1;
    assert(b3.get(0) == 42);

    b3 = b3;
    assert(b3.get(0) == 42);

    return 0;
}
