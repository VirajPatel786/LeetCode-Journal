#include <stdio.h>

/**
 * @brief Returns the maximum of two integers.
 *
 * @param num1 (int): The first integer.
 * @param num2 (int): The second integer.
 *
 * @return (int): The larger of the two integers.
 */
int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

/**
 * @brief Finds the maximum number of consecutive 1s in a binary array.
 *
 * @param nums (int*): Pointer to the array of integers (containing 0s and 1s).
 * @param numsSize (int): Size of the array.
 *
 * @return (int): The length of the longest sequence of consecutive 1s.
 */
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int currentCount = 0;  // Temporary counter for the current sequence of 1s
    int maxCount = 0;      // Maximum count of consecutive 1s found so far

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            // Increment the current sequence counter if the element is 1
            currentCount++;
        } else {
            // Update the maximum count if the current sequence ends
            maxCount = max(currentCount, maxCount);
            currentCount = 0;  // Reset the current sequence counter
        }
    }

    // After the loop, compare the last sequence of 1s with the maximum count
    return max(currentCount, maxCount);
}
