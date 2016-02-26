#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "node.h"
#include <iostream>
#include <cstdlib>

class DoublyLinkedList {
    
public:
    DoublyLinkedList(){ top = NULL; bottom = NULL; }
    DoublyLinkedList(const DoublyLinkedList &doublylist);
    
    void addItem(int value);
    void addItemInOrder(int value, bool asc);
    void printItems();
    
private:
    Node* top;
    Node* bottom;
    Node* createNewNode(int value, Node* before, Node* after);
    
};





#endif