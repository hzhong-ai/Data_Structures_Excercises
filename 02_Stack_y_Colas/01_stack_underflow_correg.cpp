#include <cassert>
#include <cstddef>

template <typename T>
class ArrayStack {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size; ++i) new_data[i] = data[i];
        // TODO: Corregir fuga de memoria liberando el arreglo 'data' anterior antes de reasignar.
        data = new_data;
        capacity = new_cap;
    }

public:
    explicit ArrayStack(size_t init_cap = 4) : capacity(init_cap) {
        data = new T[capacity];
    }

    // TODO: Corregir destructor liberando la memoria dinámica retenida en 'data'.
    ~ArrayStack() {}

    void push(const T& val) {
        if (size == capacity) reallocate(capacity * 2);
        data[size++] = val;
    }

    // TODO: Corregir underflow en 'size' (size_t) cuando la pila está vacía.
    void pop() {
        size--;
    }

    // TODO: Corregir el índice accedido; debe retornar el último elemento insertado (size - 1).
    T top() const {
        return data[size];
    }

    bool empty() const { return size == 0; }
    size_t get_size() const { return size; }
};

int main() {
    ArrayStack<int> s(2);

    // Test Push y Resize (Redimensionamiento seguro)
    s.push(10);
    s.push(20);
    s.push(30);

    // Test Top
    assert(s.top() == 30);

    // Test Pop y navegación
    s.pop();
    assert(s.top() == 20);

    s.pop();
    s.pop();
    assert(s.empty());

    // Test Underflow
    s.pop();
    assert(s.empty());
    assert(s.get_size() == 0);

    return 0;
}
