#include "doublylinkedlist.h"

Node*::DoublyLinkedList::createNewNode(int value, Node *before, Node *after){
    
    Node* temp;
    
    temp = new Node;
    
    temp->data = value;
    temp->next = after;
    temp->prev = before;
    
    return temp;
}


void DoublyLinkedList::addItem(int value){
    
    if(top == NULL){
        
        top = createNewNode(value, top, top);
        bottom = top;
        
    }else{
    
        bottom->next = createNewNode(value, bottom , bottom->next);
        bottom = bottom->next;
    }
}

void DoublyLinkedList::printItems(){
    Node* cursor = top;
    while(cursor != NULL){
        std::cout << cursor->data << std::endl;
        cursor = cursor->next;
    }
}

void DoublyLinkedList::addItemInOrder(int value, bool asc){
    if(top == NULL){
        
        top = createNewNode(value, top, top);
        bottom = top;
        
    }else{
        
        // Acending order
        if(asc){
            Node* cursor = top;
            while(cursor->next != NULL && value > cursor->data){
                cursor = cursor->next;
            }
            
            cursor->next = createNewNode(value, cursor, cursor->next);
        }
        
    }
}









