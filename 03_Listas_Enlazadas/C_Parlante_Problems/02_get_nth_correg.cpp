#include "LinkedList.h"

int LinkedList::getNth(int index) {
    // Hint: Evalúa qué ocurre con el puntero 'head' al iterar y verifica la base del contador respecto a 'index'.
    int count = 1;
    while (head != nullptr) {
        if (count == index) {
            return head->data;
        }
        count++;
        head = head->next;
    }
    return -1;
}

int main() {
    LinkedList list;
    list.push(666);
    list.push(13);
    list.push(42);

    assert(list.getNth(0) == 42);
    assert(list.getNth(1) == 13);
    assert(list.getNth(2) == 666);

    list.clear();
    return 0;
}
