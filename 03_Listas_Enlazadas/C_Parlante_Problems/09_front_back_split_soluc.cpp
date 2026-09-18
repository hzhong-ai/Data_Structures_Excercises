#include "LinkedList.h"

void LinkedList::frontBackSplit(LinkedList& front, LinkedList& back) {
    // Hint: Utiliza la técnica de dos punteros (uno lento y uno rápido) para ubicar el punto medio de la lista.
}

int main() {
    LinkedList list;
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

    LinkedList front, back;
    list.frontBackSplit(front, back);

    assert(front.get(0) == 1);
    assert(front.get(1) == 2);
    assert(front.get(2) == 3);
    assert(back.get(0) == 4);
    assert(back.get(1) == 5);

    front.clear();
    back.clear();
    list.clear();
    return 0;
}
