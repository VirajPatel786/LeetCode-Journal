#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Struct representing a circular deque.
 * 
 * @param capacity (int): Maximum number of elements the deque can hold.
 * @param dequeue (int*): Dynamic array to store the deque elements.
 * @param front (int): Index pointing to the front of the deque.
 * @param rear (int): Index pointing to the rear of the deque.
 * @param length (int): Current number of elements in the deque.
 */
typedef struct {
    int capacity;
    int* dequeue;
    int front;
    int rear;
    int length;
} MyCircularDeque;

// Function prototypes (forward declarations)
MyCircularDeque* myCircularDequeCreate(int k);
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value);
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value);
bool myCircularDequeDeleteFront(MyCircularDeque* obj);
bool myCircularDequeDeleteLast(MyCircularDeque* obj);
int myCircularDequeGetFront(MyCircularDeque* obj);
int myCircularDequeGetRear(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);
void myCircularDequeFree(MyCircularDeque* obj);

/**
 * @brief Creates and initializes a circular deque.
 *
 * @param k (int): The maximum capacity of the deque.
 *
 * @return MyCircularDeque*: Pointer to the created deque.
 */
MyCircularDeque* myCircularDequeCreate(int k) {
    // Allocate memory for the deque structure
    MyCircularDeque* mydeque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    
    // Ensure malloc was successful
    if (mydeque == NULL) {
        return NULL;  // Handle memory allocation failure
    }

    // Initialize the circular deque
    mydeque->capacity = k;
    mydeque->dequeue = (int*)calloc(k, sizeof(int));  // Allocate space for k integers

    // Ensure calloc was successful
    if (mydeque->dequeue == NULL) {
        free(mydeque);  // Clean up allocated memory
        return NULL;  // Handle memory allocation failure
    }

    // Initialize front, rear, and length
    mydeque->front = 0;
    mydeque->rear = k - 1;  // Rear starts at the last position
    mydeque->length = 0;

    return mydeque;  // Return the initialized deque
}

/**
 * @brief Inserts an element at the front of the deque.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 * @param value (int): The value to be inserted at the front.
 *
 * @return bool: True if the operation is successful, false if the deque is full.
 */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;  // Return false if deque is full
    }
    // Decrement front pointer circularly
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->dequeue[obj->front] = value;  // Insert the value at the front
    obj->length++;
    return true;
}

/**
 * @brief Inserts an element at the rear of the deque.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 * @param value (int): The value to be inserted at the rear.
 *
 * @return bool: True if the operation is successful, false if the deque is full.
 */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;  // Return false if deque is full
    }
    // Increment rear pointer circularly
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->dequeue[obj->rear] = value;  // Insert the value at the rear
    obj->length++;
    return true;
}

/**
 * @brief Deletes an element from the front of the deque.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 *
 * @return bool: True if the operation is successful, false if the deque is empty.
 */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;  // Return false if deque is empty
    }
    // Increment front pointer circularly
    obj->front = (obj->front + 1) % obj->capacity;
    obj->length--;
    return true;
}

/**
 * @brief Deletes an element from the rear of the deque.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 *
 * @return bool: True if the operation is successful, false if the deque is empty.
 */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;  // Return false if deque is empty
    }
    // Decrement rear pointer circularly
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->length--;
    return true;
}

/**
 * @brief Gets the front element of the deque.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 *
 * @return int: The front element, or -1 if the deque is empty.
 */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;  // Return -1 if deque is empty
    }
    return obj->dequeue[obj->front];  // Return the front element
}

/**
 * @brief Gets the rear element of the deque.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 *
 * @return int: The rear element, or -1 if the deque is empty.
 */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;  // Return -1 if deque is empty
    }
    return obj->dequeue[obj->rear];  // Return the rear element
}

/**
 * @brief Checks whether the deque is empty.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 *
 * @return bool: True if the deque is empty, false otherwise.
 */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->length == 0);  // Deque is empty if length is 0
}

/**
 * @brief Checks whether the deque is full.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 *
 * @return bool: True if the deque is full, false otherwise.
 */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->length == obj->capacity);  // Deque is full if length equals capacity
}

/**
 * @brief Frees the deque and its allocated memory.
 *
 * @param obj (MyCircularDeque*): Pointer to the deque structure.
 */
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->dequeue);  // Free the dynamic array
    free(obj);  // Free the deque structure
}


/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/