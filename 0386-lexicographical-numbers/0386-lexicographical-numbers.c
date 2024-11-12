#include <stdlib.h>

/**
 * @brief Generates numbers from 1 to n in lexicographical order.
 *
 * This function uses an iterative approach to simulate lexicographical order,
 * starting with 1 and moving to each next lexicographical number until reaching n.
 *
 * @param n (int): The upper limit of numbers to include in lexicographical order.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 *
 * @return (int*): Pointer to an array of integers in lexicographical order.
 *                 The array is dynamically allocated and must be freed by the caller.
 */
int* lexicalOrder(int n, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;  // In case of memory allocation failure
        return NULL;
    }
    
    *returnSize = n;  // Set the return size to n, as we'll fill it up to n elements
    int current = 1;  // Start with the first lexicographical number

    // Fill the result array with numbers from 1 to n in lexicographical order
    for (int i = 0; i < n; ++i) {
        result[i] = current;  // Add the current number to the result array

        // Move to the next lexicographical number
        if (current * 10 <= n) {
            // Try to move to the next "child" by multiplying by 10
            current *= 10;
        } else {
            // If no child is possible, increment to the next "sibling"
            if (current >= n) {
                // If current exceeds n, move back to a parent level
                current /= 10;
            }
            current += 1;  // Move to the next sibling
            
            // Remove trailing zeros (moving back to a valid lexicographical parent)
            while (current % 10 == 0) {
                current /= 10;
            }
        }
    }
    
    return result;  // Return the populated result array
}
