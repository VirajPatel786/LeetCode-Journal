#include <stdio.h>

/**
 * @brief Finds the length of the longest subarray whose bitwise AND equals the maximum possible bitwise AND value.
 * 
 * @param nums: int* - Pointer to an array of integers (input array).
 * @param numsSize: int - The size of the input array.
 *
 * @return int - Length of the longest subarray where the bitwise AND is equal to the maximum bitwise AND value.
 */
int longestSubarray(int* nums, int numsSize) {
    int max_num = 0;           // Holds the maximum number encountered so far in the array
    int max_length = 0;        // Holds the length of the longest subarray with max_num
    int current_length = 0;    // Holds the length of the current subarray of max_num

    // Iterate through the array to find the max_num and the longest subarray
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_num) {
            // Found a new maximum number, reset lengths
            max_num = nums[i];       // Update max_num to the new maximum
            current_length = 1;      // Start a new subarray with this new max_num
            max_length = 1;          // Reset max_length to 1 since it's the first occurrence of the new max_num
        }
        else if (nums[i] == max_num) {
            // If the current number is equal to max_num, extend the current subarray
            current_length++;        // Increment current subarray length
            // Update max_length to store the longest subarray found
            if (current_length > max_length) {
                max_length = current_length;
            }
        }
        else {
            // If the current number is less than max_num, reset the current subarray length
            current_length = 0;      // Current subarray ends, reset current_length
        }
    }

    // Return the length of the longest subarray with the maximum bitwise AND value
    return max_length;
}