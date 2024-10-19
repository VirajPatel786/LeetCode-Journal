#include <stdio.h>

/**
 * @brief Count the number of subsets whose OR equals the maximum possible OR.
 *
 * @param nums (int*): The array of integers.
 * @param numsSize (int): The size of the nums array.
 *
 * @return (int): The number of subsets whose bitwise OR equals the maximum possible OR.
 */
int countMaxOrSubsets(int* nums, int numsSize) {
    // Calculate the maximum OR for the entire array
    int max_or_value = nums[0];  // Initialize max OR with the first element
    int subset_count = 0;        // Counter for subsets with maximum OR

    // Calculate the maximum possible OR by OR'ing all elements together
    for (int i = 1; i < numsSize; i++) {
        max_or_value |= nums[i];  // Compute the global maximum OR value
    }

    // Helper function to recursively explore all subsets
    void findSubsets(int index, int current_or) {
        // If the current subset's OR matches the maximum OR, count all remaining subsets
        if (current_or == max_or_value) {
            subset_count += (1 << (numsSize - index));  // Add all remaining subsets
            return;  // Stop further exploration of this branch
        }

        // Explore remaining elements to form subsets
        while (index < numsSize) {
            // Recursively explore the subset including nums[index]
            findSubsets(index + 1, current_or | nums[index]);
            index++;  // Move to the next element
        }
    }

    // Start exploring subsets from the first element
    findSubsets(0, 0);

    return subset_count;  // Return the total count of subsets with maximum OR
}
