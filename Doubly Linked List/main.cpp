//
//  main.cpp
//  Doubly Linked List
//
//  Created by Guled on 2/24/16.
//

#include <iostream>
#include "doublylinkedlist.h"

int main(int argc, const char * argv[]) {

    DoublyLinkedList list = DoublyLinkedList();
    DoublyLinkedList newlist = DoublyLinkedList();
    
    list.addItem(1);
    list.addItem(2);
    list.addItem(3);
    list.addItemInOrder(4, true);
    list.printItems();
    
    newlist = list;
    newlist.printItems();

    return 0;
}
