#include <stdlib.h>

/**
 * @brief Decrypts a circular array based on the rules provided.
 *
 * @param code (int*): Circular array representing the bomb code.
 * @param codeSize (int): Length of the input array.
 * @param k (int): Determines the range and direction of summation.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 *
 * @return (int*): The decrypted array (caller must free the allocated memory).
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    *returnSize = codeSize;  // Result array size is the same as the input array
    int* result = (int*)malloc(codeSize * sizeof(int));  // Allocate memory for the result
    if (!result) return NULL;  // Handle memory allocation failure

    if (k == 0) {
        // Case 1: If k == 0, fill the result array with 0s
        for (int i = 0; i < codeSize; i++) {
            result[i] = 0;
        }
        return result;
    }

    // Initialize variables for sliding window
    int windowSum = 0;
    int start, end;

    if (k > 0) {
        // Case 2: k > 0, summing the next k elements
        start = 1;
        end = k;
    } else {
        // Case 3: k < 0, summing the previous |k| elements
        k = -k;
        start = codeSize - k;
        end = codeSize - 1;
    }

    // Compute the initial window sum
    for (int i = start; i <= end; i++) {
        windowSum += code[i % codeSize];
    }

    // Populate the result array using the rolling sum
    for (int i = 0; i < codeSize; i++) {
        result[i] = windowSum;  // Store the current sum in the result

        // Slide the window: Remove the element that is leaving the window
        // and add the new element entering the window
        windowSum += code[(end + 1) % codeSize] - code[start % codeSize];

        // Move the window
        start++;
        end++;
    }

    return result;
}
