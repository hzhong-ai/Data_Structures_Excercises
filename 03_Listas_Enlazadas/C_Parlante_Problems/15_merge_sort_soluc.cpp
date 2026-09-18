#include "LinkedList.h"

void LinkedList::mergeSort() {
    // Hint: Divide la lista en dos usando frontBackSplit(), ordénalas recursivamente y combínalas mediante sortedMerge().
}

int main() {
    LinkedList list;
    list.push(2);
    list.push(8);
    list.push(5);
    list.push(1);
    list.push(4);

    list.mergeSort();

    assert(list.get(0) == 1);
    assert(list.get(1) == 2);
    assert(list.get(2) == 4);
    assert(list.get(3) == 5);
    assert(list.get(4) == 8);

    list.clear();
    return 0;
}
