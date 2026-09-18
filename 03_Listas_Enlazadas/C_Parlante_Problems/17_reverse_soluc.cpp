#include "LinkedList.h"

void LinkedList::reverse() {
    // Hint: Mantén el rastro de los nodos anterior, actual y siguiente para invertir el sentido de las conexiones iterativamente.
}

int main() {
    LinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);

    list.reverse();

    assert(list.get(0) == 3);
    assert(list.get(1) == 2);
    assert(list.get(2) == 1);

    list.clear();
    return 0;
}
