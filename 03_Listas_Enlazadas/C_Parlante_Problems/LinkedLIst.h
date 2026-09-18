#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cassert>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Utilidades básicas e infraestructura de pruebas
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    bool isEmpty() const { return head == nullptr; }
    Node* getHead() const { return head; }
    void setHead(Node* newHead) { head = newHead; }

    int get(int index) const {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        assert(current != nullptr);
        return current->data;
    }

    // =========================================================================
    // DECLARACIONES DE LOS 18 PROBLEMAS DE PARLANTE
    // =========================================================================
    
    // 01-06: Básicos
    int count(int searchFor);
    int getNth(int index);
    void deleteList();
    int pop();
    void insertNth(int index, int data);
    void sortedInsert(int data);

    // 07-12: Intermedios
    void insertSort();
    void append(LinkedList& other);
    void frontBackSplit(LinkedList& front, LinkedList& back);
    void removeDuplicates();
    void moveNode(LinkedList& source);
    void alternatingSplit(LinkedList& a, LinkedList& b);

    // 13-18: Avanzados
    static LinkedList shuffleMerge(LinkedList& a, LinkedList& b);
    static LinkedList sortedMerge(LinkedList& a, LinkedList& b);
    void mergeSort();
    static LinkedList sortedIntersect(const LinkedList& a, const LinkedList& b);
    void reverse();
    void recursiveReverse();
};

#endif
