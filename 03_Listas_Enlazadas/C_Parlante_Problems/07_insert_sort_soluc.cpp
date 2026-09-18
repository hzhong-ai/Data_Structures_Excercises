#include "LinkedList.h"

void LinkedList::insertSort() {
    // Hint: Puedes ir desvinculando cada nodo de la lista original e insertarlo en una lista auxiliar ordenada mediante sortedInsert().
}

int main() {
    LinkedList list;
    list.push(15);
    list.push(5);
    list.push(10);
    list.push(7);

    list.insertSort();

    assert(list.get(0) == 5);
    assert(list.get(1) == 7);
    assert(list.get(2) == 10);
    assert(list.get(3) == 15);

    list.clear();
    return 0;
}
