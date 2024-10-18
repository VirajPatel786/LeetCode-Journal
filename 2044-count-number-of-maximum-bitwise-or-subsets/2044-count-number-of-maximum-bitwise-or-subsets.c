#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Count the number of subsets whose OR equals the maximum possible OR.
 *
 * @param nums (int*): The array of integers.
 * @param numsSize (int): The size of the nums array.
 *
 * @return (int): The number of subsets whose bitwise OR equals the maximum possible OR.
 */
int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOr = 0; // To store the maximum OR value

    // Calculate the maximum OR value by OR'ing all elements together
    for (int i = 0; i < numsSize; i++) {
        maxOr |= nums[i];
    }

    // Initialize an array to store the OR values we encounter
    int dp[1 << numsSize];  // Dynamic programming array
    int dp_size = 0;        // Track the size of the array
    int maxOrCount = 0;     // To count subsets whose OR equals maxOr

    // Insert the initial OR = 0 (which represents the empty subset)
    dp[dp_size++] = 0;

    // Process each number in the nums array
    for (int i = 0; i < numsSize; i++) {
        int currentSize = dp_size;  // Capture the current size of dp array

        // Add new OR values by OR'ing the current number with existing subsets
        for (int j = 0; j < currentSize; j++) {
            int newOr = dp[j] | nums[i];  // Compute new OR value
            dp[dp_size++] = newOr;  // Add this new OR to the list

            // If the new OR is equal to maxOr, increment the count
            if (newOr == maxOr) {
                maxOrCount++;
            }
        }
    }

    return maxOrCount;  // Return the count of subsets with maxOr
}
