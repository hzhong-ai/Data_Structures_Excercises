#include <cassert>
#include <cstddef>

template <typename T>
class CircularQueue {
private:
    T* data = nullptr;
    size_t head = 0;
    size_t size = 0;
    size_t capacity = 0;

    // TODO: Redimensionar y des-circularizar el arreglo en un nuevo bloque lineal.
    // HINT: Mapear cada elemento i con la fórmula de acceso circular: (head + i) % capacity,
    // copiar al nuevo buffer en orden lineal, actualizar 'head' a 0 y liberar la memoria anterior.
    void reallocate(size_t new_cap) {
    }

public:
    explicit CircularQueue(size_t cap = 3) : capacity(cap) {
        data = new T[capacity];
    }

    ~CircularQueue() { delete[] data; }

    void push(const T& val) {
        if (size == capacity) {
            reallocate(capacity * 2);
        }
        size_t tail = (head + size) % capacity;
        data[tail] = val;
        size++;
    }

    void pop() {
        if (size > 0) {
            head = (head + 1) % capacity;
            size--;
        }
    }

    T front() const { return data[head]; }
    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
};

int main() {
    CircularQueue<int> q(3);
    q.push(10);
    q.push(20);
    q.push(30);

    q.pop();    // Libera 10 (head avanza al índice 1)
    q.push(40); // Inserción circular en el índice 0

    assert(q.front() == 20);

    // Provoca reallocate al estar en estado envuelto (wrapped)
    q.push(50);

    assert(q.front() == 20);
    assert(q.get_size() == 4);

    q.pop(); assert(q.front() == 30);
    q.pop(); assert(q.front() == 40);
    q.pop(); assert(q.front() == 50);

    return 0;
}
