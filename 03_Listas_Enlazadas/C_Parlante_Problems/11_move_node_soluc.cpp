#include "LinkedList.h"

void LinkedList::moveNode(LinkedList& source) {
    // Hint: Reasigna únicamente el primer nodo de 'source' al frente de esta lista, manteniendo la coherencia de ambas cabezas.
}

int main() {
    LinkedList dest;
    dest.push(2);
    dest.push(1);

    LinkedList source;
    source.push(4);
    source.push(3);

    dest.moveNode(source);

    assert(dest.get(0) == 3);
    assert(dest.get(1) == 1);
    assert(dest.get(2) == 2);
    assert(source.get(0) == 4);

    dest.clear();
    source.clear();
    return 0;
}
