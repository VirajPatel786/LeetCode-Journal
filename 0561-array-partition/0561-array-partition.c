#include <stdlib.h>

/**
 * @brief Comparison function for qsort to sort integers in ascending order.
 *
 * @param a (const void*): Pointer to the first integer.
 * @param b (const void*): Pointer to the second integer.
 *
 * @return (int): -1 if a < b, 1 if a > b, 0 if a == b.
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * @brief Computes the maximum sum of minimum values of n pairs formed from the input array.
 *
 * @param nums (int*): Array of integers where 2n elements form n pairs.
 * @param numsSize (int): The size of the nums array.
 *
 * @return (int): Maximum possible sum of minimum values of each pair.
 */
int arrayPairSum(int* nums, int numsSize) {
    // Sort the array in ascending order to maximize the sum of minimums in pairs
    qsort(nums, numsSize, sizeof(int), compare);
    
    int result = 0;  // Initialize result to store the final sum

    // Loop through the array, summing every other element (the minimum in each pair)
    for (int i = 0; i < numsSize; i += 2) {
        result += nums[i];
    }
    
    return result;  // Return the final result
}
