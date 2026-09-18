#include "LinkedList.h"

LinkedList LinkedList::sortedIntersect(const LinkedList& a, const LinkedList& b) {
    LinkedList result;
    // Hint: Aprovecha que ambas listas están ordenadas para avanzar en paralelo sin modificar el contenido de 'a' y 'b'.
    return result;
}

int main() {
    LinkedList a, b;
    a.push(6); a.push(4); a.push(2); a.push(1);
    b.push(5); b.push(4); b.push(2);

    LinkedList intersect = LinkedList::sortedIntersect(a, b);

    assert(intersect.get(0) == 2);
    assert(intersect.get(1) == 4);

    intersect.clear();
    a.clear();
    b.clear();
    return 0;
}
