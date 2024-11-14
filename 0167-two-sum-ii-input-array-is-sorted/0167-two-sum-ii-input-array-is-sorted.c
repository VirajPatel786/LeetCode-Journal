#include <stdlib.h>

/**
 * @brief Finds two indices such that the values at these indices add up to the target.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * @param numbers (int*): Sorted array of integers.
 * @param numbersSize (int): Size of the numbers array.
 * @param target (int): Target sum for two elements in numbers.
 * @param returnSize (int*): Pointer to store the size of the returned array (set to 2).
 *
 * @return (int*): Dynamically allocated array containing 1-based indices of the two numbers
 *                 that add up to the target. The caller is responsible for freeing this memory.
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // Initialize pointers for two-pointer approach
    int left = 0;
    int right = numbersSize - 1;

    // Allocate memory for the result (array of size 2)
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        // If memory allocation fails, set returnSize to 0 and return NULL
        *returnSize = 0;
        return NULL;
    }

    // Search for the two indices
    while (left < right) {
        int current_sum = numbers[left] + numbers[right];  // Calculate the current sum

        if (current_sum == target) {
            // If we found the target sum, store 1-based indices in result
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;  // Set the size of the returned array to 2
            return result;
        } else if (current_sum < target) {
            // If sum is less than target, move left pointer to increase the sum
            left++;
        } else {
            // If sum is greater than target, move right pointer to decrease the sum
            right--;
        }
    }

    // If no solution is found (shouldn't happen as per problem constraints), set returnSize to 0
    *returnSize = 0;
    free(result);  // Free the allocated memory if no solution is found
    return NULL;
}
