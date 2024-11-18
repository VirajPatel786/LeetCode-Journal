#include <stdlib.h>
#include <limits.h>

/**
 * @brief Finds the length of the shortest subarray with a sum >= k.
 *
 * @param nums (int*): Array of integers.
 * @param numsSize (int): Size of the nums array.
 * @param k (int): Target sum.
 *
 * @return (int): Length of the shortest subarray with a sum >= k, or -1 if no such subarray exists.
 */
int shortestSubarray(int* nums, int numsSize, int k) {
    // Create the prefix sum array
    long* prefixSum = (long*)malloc((numsSize + 1) * sizeof(long));
    if (!prefixSum) return -1;  // Handle memory allocation failure

    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // Initialize a deque to store indices
    int* deque = (int*)malloc((numsSize + 1) * sizeof(int));
    if (!deque) {
        free(prefixSum);
        return -1;
    }
    int dequeStart = 0, dequeEnd = 0;

    int result = INT_MAX;  // Initialize result to infinity (no valid subarray found)

    // Iterate over the prefix sum array
    for (int i = 0; i <= numsSize; i++) {
        // Remove elements from the front of the deque if they form a valid subarray
        while (dequeStart < dequeEnd && prefixSum[i] - prefixSum[deque[dequeStart]] >= k) {
            result = (i - deque[dequeStart] < result) ? i - deque[dequeStart] : result;
            dequeStart++;
        }

        // Maintain monotonicity: remove elements from the back if they are greater than or equal to the current prefix sum
        while (dequeStart < dequeEnd && prefixSum[deque[dequeEnd - 1]] >= prefixSum[i]) {
            dequeEnd--;
        }

        // Add the current index to the deque
        deque[dequeEnd++] = i;
    }

    // Free allocated memory
    free(prefixSum);
    free(deque);

    // Return the result, or -1 if no valid subarray was found
    return result == INT_MAX ? -1 : result;
}
