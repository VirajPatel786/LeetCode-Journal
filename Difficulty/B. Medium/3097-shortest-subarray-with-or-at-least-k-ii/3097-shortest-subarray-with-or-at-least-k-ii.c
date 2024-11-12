#include <stdio.h>
#include <limits.h>

/**
 * @brief Finds the length of the shortest subarray with bitwise OR at least k.
 *
 * @param nums (int*): Array of non-negative integers.
 * @param numsSize (int): Size of the array.
 * @param k (int): Target OR value.
 *
 * @return (int): Length of the shortest subarray with OR at least k, or -1 if none exists.
 */
int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int left = 0;                 // Start index of the sliding window
    int current_or = 0;           // Current bitwise OR of the sliding window
    int min_length = INT_MAX;     // Stores the minimum length of a valid subarray
    
    int bit_count[31] = {0};      // Tracks how many numbers contribute to each bit position (supports up to 31 bits)

    // Expand the sliding window by increasing the right boundary
    for (int right = 0; right < numsSize; ++right) {
        // Update the OR for the window by including nums[right]
        current_or |= nums[right];

        // Add contributions of nums[right] to each bit in bit_count
        int num = nums[right];
        int bit_position = 0;
        while (num > 0) {
            if (num & 1) {
                bit_count[bit_position]++;
            }
            num >>= 1;
            bit_position++;
        }

        // Try to shrink the window from the left while OR condition is met
        while (left <= right && current_or >= k) {
            // Update minimum length if current window is smaller
            if ((right - left + 1) < min_length) {
                min_length = right - left + 1;
            }

            // Remove contributions of nums[left] from each bit in bit_count
            num = nums[left];
            bit_position = 0;
            while (num > 0) {
                if (num & 1) {
                    bit_count[bit_position]--;
                    // If nums[left] was the only contributor to this bit, update current OR
                    if (bit_count[bit_position] == 0) {
                        current_or &= ~(1 << bit_position);  // Clear the bit in current_or
                    }
                }
                num >>= 1;
                bit_position++;
            }

            // Move the left boundary of the window
            left++;
        }
    }

    // Return -1 if no valid subarray was found, otherwise the minimum length
    return (min_length == INT_MAX) ? -1 : min_length;
}
