#include <stdlib.h>

/**
 * @brief Struct representing a custom stack.
 * 
 * @param stack (int*): Dynamic array to store stack elements.
 * @param stack_size (int): Current number of elements in the stack.
 * @param stack_capacity (int): Maximum capacity of the stack.
 */
typedef struct {
    int* stack;
    int stack_size;
    int stack_capacity;
} CustomStack;

/**
 * @brief Creates a new CustomStack with the specified maximum size.
 * 
 * @param maxSize (int): The maximum size (capacity) of the stack.
 * 
 * @return CustomStack*: Pointer to the newly created stack.
 */
CustomStack* customStackCreate(int maxSize) {
    CustomStack* mystack = (CustomStack*)malloc(sizeof(CustomStack));
    if (mystack == NULL) {
        return NULL;  // Handle memory allocation failure.
    }
    mystack->stack = (int*)malloc(sizeof(int) * maxSize);
    if (mystack->stack == NULL) {
        free(mystack);  // Free memory in case stack allocation fails.
        return NULL;
    }
    mystack->stack_size = 0;
    mystack->stack_capacity = maxSize;
    return mystack;
}

/**
 * @brief Push an element onto the stack if there is space.
 * 
 * @param obj (CustomStack*): Pointer to the CustomStack.
 * @param x (int): The element to be pushed onto the stack.
 */
void customStackPush(CustomStack* obj, int x) {
    if (obj != NULL && obj->stack_size < obj->stack_capacity) {
        obj->stack[obj->stack_size] = x;  // Add element at the current top
        obj->stack_size++;  // Increment size after adding the element
    }
}

/**
 * @brief Pop an element from the stack.
 * 
 * @param obj (CustomStack*): Pointer to the CustomStack.
 * 
 * @return int: The popped element, or -1 if the stack is empty.
 */
int customStackPop(CustomStack* obj) {
    if (obj != NULL && obj->stack_size != 0) {
        obj->stack_size--;  // Decrement size first
        return obj->stack[obj->stack_size];  // Return the element at the new top
    }
    return -1;  // Return -1 if the stack is empty.
}

/**
 * @brief Increment the bottom k elements of the stack by a given value.
 * 
 * @param obj (CustomStack*): Pointer to the CustomStack.
 * @param k (int): Number of elements from the bottom to be incremented.
 * @param val (int): The value to increment each of the bottom k elements by.
 */
void customStackIncrement(CustomStack* obj, int k, int val) {
    if (obj != NULL) {
        int limit = (k < obj->stack_size) ? k : obj->stack_size;  // Determine the limit of elements to increment.
        for (int i = 0; i < limit; i++) {
            obj->stack[i] += val;  // Increment each element.
        }
    }
}

/**
 * @brief Frees the memory allocated for the CustomStack.
 * 
 * @param obj (CustomStack*): Pointer to the CustomStack.
 */
void customStackFree(CustomStack* obj) {
    if (obj != NULL) {
        free(obj->stack);  // Free the memory allocated for the stack array.
        free(obj);  // Free the memory allocated for the CustomStack struct.
    }
}


/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/