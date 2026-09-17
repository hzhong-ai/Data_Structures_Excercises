#include <cassert>
#include <cstddef>

template <typename T>
class ResizableStack {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    // TODO: Implementar reallocate(new_cap). Debe alojar un nuevo arreglo, 
    // copiar los elementos actuales, liberar la memoria anterior y actualizar capacidad.
    void reallocate(size_t new_cap) {
    }

public:
    explicit ResizableStack(size_t init_cap = 2) : capacity(init_cap) {
        data = new T[capacity];
    }

    ~ResizableStack() {
        delete[] data;
    }

    // TODO: Implementar push. Debe invocar reallocate(capacity * 2) cuando size == capacity
    // e insertar el nuevo elemento.
    void push(const T& val) {
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
    ResizableStack<int> s(2);
    assert(s.get_capacity() == 2);

    s.push(100);
    s.push(200);
    assert(s.get_capacity() == 2);

    // Provoca reallocate al doble (capacidad pasa de 2 a 4)
    s.push(300);
    assert(s.get_capacity() == 4);
    assert(s.get_size() == 3);
    assert(s.top() == 300);

    return 0;
}
