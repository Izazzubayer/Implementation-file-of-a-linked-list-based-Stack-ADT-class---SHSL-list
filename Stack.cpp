
/* 
 * Stack.cpp
 *
 * Description: Implementation file of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Izaz Zubayer (301386899) and Zoe Stanley (301427509)
 * Modified on: February 2024
 */


#include <iostream>
#include <stdexcept>
#include "Stack.h"
using std::cout;
using std::endl;


// Default constructor
// Description: Instantiates an empty SHSL list with a single empty Head node.
// Postcondition: A stack is instantiated with 0 elements and a null head.
Stack::Stack() : head(nullptr), elementCount(0) {}

// Destructor
// Description: called by 'delete'; frees any memory used by Stack elements 
// + sets ptrs to null
Stack::~Stack() {
    while(!isEmpty()) {
        pop();  // Pop must effectively handle node memory
    }
}


// Description: Function to return True if stack is empty and False if not.
// Precondition: There is a stack to pass as a reference.
// Postcondition: The stack is not modified and T/F is returned.
bool Stack::isEmpty() const {
    return (elementCount == 0);

}

// Description: Function to push a StackNode onto the stack at the end of SHSL list
// Precondition: A stack exists and is passed by reference.
// Postcondition: A new node is added to the stack with the value specified. 
bool Stack::push(int & data) {
    
    // Create new Node
    StackNode * newNode = new StackNode(data);

    // Check if head == null, if so, add there
    if (head == nullptr) {
        head = newNode;
        elementCount++;
        return true; // end function

    } else {

        // Make temporary current node to travers
        StackNode * current = head;

        // Find end of list
        while (current->next != nullptr) {
            current = current->next;
        }
        // Add here; update count
        current->next = newNode;
        elementCount++;
    }
    return true;
}

// Description: Function to pop most recent element from back of SHSL list
// Precondition: the stack exists and is non-empty, or returns false
// Postcondition: the most recent item is removed from the back of Stack and returns true
int Stack::pop() {

    // Check if stack is empty and show error if so
    if (elementCount == 0) {
        throw std::out_of_range("Stack is empty, nothing to pop here.");

    }
    // Check if head is only object and pop head if so, reset to null
    if (head->next == nullptr) {
        int value = head->data;
        delete head;
        head = nullptr;
        elementCount--;
        return value;
    }
    // Instantiate traversing curr node and find second-last node by checking next-next
    StackNode * current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    // Remove last node and decrement elementCount
    int value = current->next->data;
    delete current->next;
    current->next = nullptr;
    elementCount--;

    // return value of popped node
    return value;

}

// Description: Function to pop all items from the stack in FILO / LIFO manner from back. 
// Precondition: Stack exists and is non-empty, or throws False
// Postcondition: returns true when stack is empty but initiated. 
void Stack::popAll() {
    
    // Check if empty and throw error message if so
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty, nothing to pop here.");
        return;
    }
    // If non-empty, pop until empty. 
    while (!isEmpty()) {
        pop();
    }
    return;
}


// Decription: Function to peek at the most recent item at the end (front of Stack) of SHSL list.
// Precondition: Stack is not empty or else throws error.
// Postcondition: FILO reference to most recent item returned.
int Stack::peek() const {

    // check if empty
    if (isEmpty()) {
        cout << "Stack is empty, nothing to peek at." << endl;
    }

    // If head is only elem
    if (head->next == nullptr) {
        return head->data;
    }

    // traverse to end and return value
    StackNode * current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->data;

}; // end of implementation file