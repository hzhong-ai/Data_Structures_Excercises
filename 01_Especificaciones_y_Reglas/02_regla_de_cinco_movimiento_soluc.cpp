#include <cassert>
#include <cstddef>
#include <utility>

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

    // TODO: Transferir la propiedad de 'data' y 'size', dejando 'otro' en estado neutro.
    MoveArray(MoveArray&& otro) noexcept 
        : data(otro.data), size(otro.size) {
        // pon tu codigo aqui
        otro.data = nullptr;
        otro.size = 0;
    }

    // TODO: Liberar la memoria actual, robar punteros de 'otro' y dejarlo nulo.
    MoveArray& operator=(MoveArray&& otro) noexcept {
        // pon tu codigo aqui
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
    MoveArray a(5);
    int* original_ptr = a.get_data();

    MoveArray b = std::move(a);

    assert(b.get_data() == original_ptr);
    assert(b.get_size() == 5);
    assert(a.get_data() == nullptr);
    assert(a.get_size() == 0);

    MoveArray c(2);
    c = std::move(b);

    assert(c.get_data() == original_ptr);
    assert(b.get_data() == nullptr);

    return 0;
}
