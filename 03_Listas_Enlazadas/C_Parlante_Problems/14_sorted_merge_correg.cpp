#include "LinkedList.h"

LinkedList LinkedList::sortedMerge(LinkedList& a, LinkedList& b) {
    LinkedList result;
    // Hint: Compara siempre el elemento frontal de ambas listas y traslada progresivamente el menor hacia la lista de destino.
    while (!a.isEmpty()) {
        result.push(a.pop());
    }
    while (!b.isEmpty()) {
        result.push(b.pop());
    }
    return result;
}

int main() {
    LinkedList a, b;
    a.push(10); a.push(5); a.push(2);
    b.push(7); b.push(3);

    LinkedList merged = LinkedList::sortedMerge(a, b);

    assert(merged.get(0) == 2);
    assert(merged.get(1) == 3);
    assert(merged.get(2) == 5);
    assert(merged.get(3) == 7);
    assert(merged.get(4) == 10);

    merged.clear();
    a.clear();
    b.clear();
    return 0;
}
