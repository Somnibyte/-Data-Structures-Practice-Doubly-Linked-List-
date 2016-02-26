#include "doublylinkedlist.h"

Node*::DoublyLinkedList::createNewNode(int value, Node *before, Node *after){
    
    Node* temp;
    
    temp = new Node;
    
    temp->data = value;
    temp->next = after;
    temp->prev = before;
    
    return temp;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &doublylist){
    
    // Create new sentinel
    Node* newTop = NULL;
    
    // Keeps track of node that was added previously
    Node* lastAdded = newTop;
    
    // Keep track of the last item we added
    Node* newBottom = newTop;
    
    // A pointer to go through the original list
    Node* cursor = doublylist.top;

    
    while(cursor != NULL){
        
        // Are we at the beginning?
        if(cursor == top){
            // Create a new node for the newtop
            newTop = createNewNode(cursor->data, newTop, cursor->next);
            // Connect the next nodes "back pointer" to the where newtop is pointing to
            newTop->next->prev = newTop;
            // Move the cursor two places (becuase newTop's "next" has already been established)
            cursor = cursor->next->next;
            
            // Move the newBottom
            newBottom = newTop->next;
            
            // Keep track of the new node
            lastAdded = newTop->next;
        }
        
        
        // If we are not in the beginning continue the normal process
        newBottom->next = createNewNode(cursor->data, lastAdded, cursor->next);
        newBottom = newBottom->next->next;
        lastAdded = newBottom->prev;
        newBottom->prev = lastAdded;
        
    }
  
    
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









