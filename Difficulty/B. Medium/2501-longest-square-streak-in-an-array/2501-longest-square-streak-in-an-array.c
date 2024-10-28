#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 100000

/**
 * @brief Comparison function for qsort to sort integers in ascending order.
 *
 * This function is used by qsort to compare two integer elements for sorting.
 * It returns a negative value if the first element is smaller, zero if they
 * are equal, and a positive value if the first element is greater.
 *
 * @param a (const void*): Pointer to the first element.
 * @param b (const void*): Pointer to the second element.
 *
 * @return (int): Negative if *a < *b, zero if *a == *b, positive if *a > *b.
 */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Finds the length of the longest square streak in nums.
 *
 * This function sorts the input array, then attempts to find the longest subsequence
 * where each element is the square of the previous one in ascending order.
 *
 * @param nums (int[]): Array of integers.
 * @param numsSize (int): Size of the array.
 *
 * @return (int): Length of the longest square streak, or -1 if no streak exists.
 */
int longestSquareStreak(int* nums, int numsSize) {
    // Sort the array to process elements in increasing order
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Hash set to store elements for O(1) lookups
    bool num_set[MAX_NUM + 1] = {false};
    for (int i = 0; i < numsSize; i++) {
        num_set[nums[i]] = true;
    }

    int max_streak = 0;  // Initialize variable to store the max streak length
    
    // Iterate through each element in the array
    for (int i = 0; i < numsSize; i++) {
        int current_length = 0;  // Track the current chain length
        long current_num = nums[i];  // Start chain with the current number

        // Build a chain by checking if each successive square exists in num_set
        while (current_num <= MAX_NUM && num_set[current_num]) {
            current_length++;  // Increase the chain length
            current_num *= current_num;  // Move to the next square in the chain
            if (current_num > MAX_NUM) break;  // Prevent overflow for large numbers
        }
        
        // Update max_streak if the current chain is the longest so far and meets criteria
        if (current_length >= 2) {
            if (current_length > max_streak) {
                max_streak = current_length;
            }
        }
    }
    
    // Return -1 if no valid streak was found; otherwise, return the max streak length
    return max_streak >= 2 ? max_streak : -1;
}
