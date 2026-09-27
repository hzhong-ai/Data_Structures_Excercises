#include <cassert>
#include <cstddef>

class QueueBug {
private:
    int* data = nullptr;
    size_t head = 0;
    size_t size_ = 0;
    size_t capacity = 0;

public:
    explicit QueueBug(size_t cap = 5) : capacity(cap) {
        data = new int[capacity];
    }

    ~QueueBug() { delete[] data; }

    void push(int val) {
        if (size_ < capacity) {
            size_t tail = (head + size_) % capacity;
            data[tail] = val;
            size_++;
        }
    }

    void pop() {
        if (size_ > 0) {
            head = (head + 1) % capacity;
            size_--;
        }
    }

    int front() const {
        return size_ > 0 ? data[head] : -1;
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
};

int main() {
    QueueBug q(3);
    q.push(1);
    q.push(2);

    assert(q.size() == 2);
    assert(q.front() == 1);

    // Test de avance y decremento de size_
    q.pop();
    assert(q.size() == 1);
    assert(q.front() == 2);

    q.pop();
    assert(q.empty());

    // Test de comportamiento en estado vacío
    assert(q.front() == -1);

    return 0;
}
