/* 
 * Queue.h 
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Izaz Zubayer (301386899) and Zoe Stanley (301427509)
 * Modified on: February 2024
 */
 
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue {

/* You cannot remove/modify the data members below, 
   except for the "int elements[INITIAL_CAPACITY];". 
   However, you can add more data members.              */
	
    private:
        static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        int *elements; // Pointer to an array
 
        unsigned int elementCount = 0;                  // Number of elements in the Queue - if you need it!
        unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex = 0;                    // Index of front element (next dequeued/peeked element)
        unsigned int backindex = 0;                     // Index of where the next element will be enqueued                     

/* You can add private methods. */

        // Description: Helper method to resize the array larger.
        // Precondition: Queue is full, and new element is to be added.
        // Postcondition: Queue is doubled in size with same elements.
        void resizeLarge();

        // Description: Helper method to resize the array smaller.
        // Precondition: Queue is less than a 1/4 full after dequeue.
        // Postcondition: Queue is halved in size, or reset to INITIAL_CAPACITY if not. 
        void resizeSmall();

    public:
 
/* You cannot remove/modify the public methods below. 
   This also applies to their documentation. 
   However, you can add public methods if you need them 
   like "printQueue()", etc.                            */

        // Description: Constructor
        Queue();

        //Destructor
        ~Queue();


        Queue(const Queue& other); // Copy Constructor
        Queue& operator=(const Queue& other); // Overloaded Assignment Operator


        // Description: Inserts newElement at the back of Queue
        // Time Efficiency: O(1)
        void enqueue(int newElement);

        // Description: Removes the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        void dequeue();

        // Description: Returns a copy of the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        int peek() const;

        // Description: Returns true if and only if Queue empty
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
};
#endif