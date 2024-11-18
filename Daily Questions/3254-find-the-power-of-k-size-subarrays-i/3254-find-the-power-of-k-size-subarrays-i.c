#include <stdlib.h>

/**
 * @brief Computes the power of all k-size subarrays of nums efficiently.
 *
 * @param nums (int*): Array of integers.
 * @param numsSize (int): Size of the nums array.
 * @param k (int): Size of subarrays to process.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 *
 * @return (int*): Dynamically allocated array containing the results.
 *                 Caller must free the returned array.
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    // Handle the edge case when k == 1
    if (k == 1) {
        *returnSize = numsSize;  // Each element is its own subarray
        int* results = (int*)malloc(numsSize * sizeof(int));
        if (!results) return NULL;  // Return NULL if memory allocation fails

        // Copy all elements from nums to results
        for (int i = 0; i < numsSize; i++) {
            results[i] = nums[i];
        }
        return results;
    }

    *returnSize = numsSize - k + 1;  // Size of the result array
    int* results = (int*)malloc((*returnSize) * sizeof(int));  // Allocate memory for the result array
    if (!results) {
        return NULL;  // Return NULL if memory allocation fails
    }

    int left = 0, right = 1;  // Sliding window pointers
    int idx = 0;  // Index for the results array

    while (right < numsSize) {
        if (nums[right] - nums[right - 1] != 1) {
            // If the current pair is not consecutive
            while (left < right && left + k - 1 < numsSize) {
                results[idx++] = -1;  // Fill invalid windows with -1
                left++;
            }
            left = right;  // Reset left pointer to the current right position
        } else if (right - left == k - 1) {
            // If the window is valid and its size is exactly k
            results[idx++] = nums[right];  // Append the last element of the valid window
            left++;  // Move the left pointer forward
        }
        right++;  // Increment the right pointer
    }

    return results;  // Return the dynamically allocated results array
}
