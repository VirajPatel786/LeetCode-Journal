#include <stdlib.h>

/**
 * @brief Computes the maximum XOR for each query by reversing the order and updating cumulative XOR.
 *
 * @param nums (int*): Array of non-negative integers.
 * @param numsSize (int): Size of the nums array.
 * @param maximumBit (int): Maximum bit length for XOR results.
 * @param returnSize (int*): Pointer to an integer where the size of the returned array will be stored.
 *
 * @return int*: Array of integers representing the maximum XOR values for each query.
 *         The array must be freed by the caller.
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    *returnSize = numsSize;  // The result array will have the same size as nums
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    if (result == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    // Calculate the maximum XOR mask for the given bit length
    int max_mask = (1 << maximumBit) - 1;  // Mask with all bits set to 1 within maximumBit length
    
    // Initialize cumulative XOR
    int current_xor = 0;
    
    // Traverse nums to calculate cumulative XOR and store results in reverse order
    for (int i = 0; i < numsSize; i++) {
        current_xor ^= nums[i];  // Update cumulative XOR
        result[numsSize - 1 - i] = max_mask ^ current_xor;  // Calculate max XOR and store in reverse
    }
    
    return result;
}
