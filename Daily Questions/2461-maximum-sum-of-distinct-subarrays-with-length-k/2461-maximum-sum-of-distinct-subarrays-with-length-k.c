#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Computes the maximum sum of a subarray of size k with unique elements.
 *
 * @param nums (int*): Input array of integers.
 * @param numsSize (int): Size of the input array.
 * @param k (int): Size of the subarray.
 *
 * @return (long long): Maximum sum of a subarray of size k with all unique elements.
 */
long long maximumSubarraySum(int* nums, int numsSize, int k) {
    long long maxSum = 0;        // Maximum sum of subarrays
    long long currentSum = 0;   // Current sum of the sliding window
    int* freq = (int*)calloc(100001, sizeof(int));  // Frequency array for unique element tracking
    int left = 0;               // Left pointer for the sliding window

    for (int right = 0; right < numsSize; right++) {
        // Add the current element to the window
        currentSum += nums[right];
        freq[nums[right]]++;

        // If the element is repeated, shrink the window from the left
        while (freq[nums[right]] > 1) {
            freq[nums[left]]--;
            currentSum -= nums[left];
            left++;
        }

        // Check if the window size is exactly k
        if (right - left + 1 == k) {
            // Update the maximum sum if all elements are unique
            if (freq[nums[right]] == 1) {
                maxSum = (currentSum > maxSum) ? currentSum : maxSum;
            }

            // Shrink the window to maintain size k
            freq[nums[left]]--;
            currentSum -= nums[left];
            left++;
        }
    }

    free(freq);  // Free allocated memory for frequency tracking
    return maxSum;
}
