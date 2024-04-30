/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Izaz Zubayer (301386899) and Zoe Stanley (301427509)
 * Modified on: February 2024
 */

#ifndef STACK_H
#define STACK_H
 
class Stack {

    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;

                // Using a constructor here for the StackNode class
                // Description: Instantiates a StackNode object with a given data and null next
                StackNode(int data, StackNode * next = nullptr) : data(data), next(next) {};
                // no destructor required as all data is non-dynamic; nodes themselves handled in pop()
        };
        
/* Put your code here! */   
        StackNode * head;
        int elementCount;    
        

    public:

        // Constructors and Destructors

        // Default constructor
        // Description: Instantiates an empty SHSL list with a single empty Head node.
        // Postcondition: A stack is instantiated. 
        Stack();

        // Destructor
        // Description: called by 'delete'; frees any memory used by Stack elements 
        // + sets ptrs to null
        ~Stack();

        // Description: Function to return True if stack is empty and False if not.
        // Precondition: There is a stack to pass as a reference.
        // Postcondition: The stack is not modified and T/F is returned.
        bool isEmpty() const;

        // Description: Function to push a StackNode onto the stack at the end of SHSL list
        // Precondition: A stack exists and is passed by reference.
        // Postcondition: A new node is added to the stack with the value specified. 
        bool push(int & data);

        // Description: Function to pop most recent element from back of SHSL list
        // Precondition: the stack exists and is non-empty, or returns false
        // Postcondition: the most recent item is removed from the back of Stack and returns true
        int pop();


        // Description: Function to pop all items from the stack in FILO / LIFO manner from back. 
        // Precondition: Stack exists and is non-empty, or throws False
        // Postcondition: returns true when stack is empty but initiated. 
        void popAll();


        // Decription: Function to peek at the most recent item at the end (front of Stack) of SHSL list.
        // Precondition: Stack is not empty or else throws error.
        // Postcondition: FILO reference to most recent item returned.
        int peek() const;


};

#endif
