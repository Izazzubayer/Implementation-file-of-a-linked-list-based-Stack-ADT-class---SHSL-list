/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Izaz Zubayer (301386899) and Zoe Stanley (301427509)
 * Modified on: February 2024
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;



// Description: Constructor
Queue::Queue() {
    elements = new int[capacity];
}

// Description: Destructor
Queue::~Queue() {
    delete[] elements;
}

// Description: Copy Constructor
Queue::Queue(const Queue& object) { 
    capacity = object.capacity;
    elementCount = object.elementCount;
    frontindex = object.frontindex;
    backindex = object.backindex;

    elements = new int[capacity];
    for (unsigned int i = 0; i < capacity; i++) {
        elements[i] = object.elements[i];
    }
}

// Description: Overloaded Assignment Operator
//Precondition: Queue is not empty
//Postcondition: Queue is assigned to another queue
Queue& Queue::operator=(const Queue& object) {
    if (this != &object) {
        delete[] elements;

        capacity = object.capacity;
        elementCount = object.elementCount;
        frontindex = object.frontindex;
        backindex = object.backindex;

        elements = new int[capacity];
        for (unsigned int i = 0; i < capacity; i++) {
            elements[i] = object.elements[i];
        }
    }
    return *this;
}


// Description: Helper method to resize the array smaller.
// Precondition: Queue is less than a 1/4 full after dequeue.
// Postcondition: Queue is halved in size, or reset to INITIAL_CAPACITY if not. 
void Queue::resizeSmall() {

    // New capacity 
    unsigned int updatedCapacity = capacity / 2;

    // ensure not smaller
    if (updatedCapacity < INITIAL_CAPACITY) {
        updatedCapacity = INITIAL_CAPACITY;
    }

    // Resize and copy
    int * newElements = new int[updatedCapacity];
    for (unsigned int i = 0; i < elementCount; i++) {
        newElements[i] = elements[(frontindex + i) % capacity];
    }
    frontindex = 0;
    backindex = elementCount;

    // edge case: empty Queue
    if (elementCount == 0) {
        backindex = 0;
    }

    // Update capacity
    capacity = updatedCapacity;

    // Deleting old array and assigning new array
    delete[] elements;
    elements = newElements;

}

// Description: Helper method to resize the array larger.
// Precondition: Queue is full, and new element is to be added.
// Postcondition: Queue is doubled in size with same elements.
void Queue::resizeLarge() {

    // Double the array
    unsigned int updatedCapacity = capacity * 2;

    // Resize and copy
    int * newElements = new int[updatedCapacity];
    for (unsigned int i = 0; i < elementCount; i++) {
        newElements[i] = elements[(frontindex + i) % capacity];
    }

    frontindex = 0;
    backindex = elementCount;
    
    // edge case: empty Queue
    if (elementCount == 0) {
        backindex = 0;
    }

    capacity = updatedCapacity;

    delete[] elements;
    elements = newElements;
    
}


// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1) amortized
void Queue::enqueue(int newElement) {
    if (elementCount == capacity) {
        resizeLarge();  //Double the array
    }

    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
    elementCount++;
}


// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1) amortized
void Queue::dequeue() { 
    
    // Confirm the queue is not empty.
    if (isEmpty()) { cout << "Empty queue, cannot dequeue." << endl; return; }

    // Dequeue
    frontindex = (frontindex + 1) % capacity;
    elementCount--;

    // Checks if queue needs resizing
    bool getSmaller = (elementCount < (capacity/4)); 
    if (getSmaller) { resizeSmall(); } // resizeSmall ensures new array not smaller 
                                       // than INITIAL_CAPACITY.
}

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];
}

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}