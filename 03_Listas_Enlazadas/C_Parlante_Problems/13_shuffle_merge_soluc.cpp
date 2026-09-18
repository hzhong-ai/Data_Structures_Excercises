#include "LinkedList.h"

LinkedList LinkedList::shuffleMerge(LinkedList& a, LinkedList& b) {
    LinkedList result;
    // Hint: Alterna la extracción de nodos entre 'a' y 'b'. Si una lista se agota, conecta directamente los nodos restantes de la otra.
    return result;
}

int main() {
    LinkedList a, b;
    a.push(3); a.push(2); a.push(1);
    b.push(13); b.push(7);

    LinkedList merged = LinkedList::shuffleMerge(a, b);

    assert(merged.get(0) == 1);
    assert(merged.get(1) == 7);
    assert(merged.get(2) == 2);
    assert(merged.get(3) == 13);
    assert(merged.get(4) == 3);

    assert(a.isEmpty());
    assert(b.isEmpty());

    merged.clear();
    a.clear();
    b.clear();
    return 0;
}
