#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/**
 * @brief Determines if it is possible to achieve the given penalty with maxOperations.
 *
 * @param nums (int*): Array representing the number of balls in each bag.
 * @param numsSize (int): Size of the nums array.
 * @param maxOperations (int): Maximum number of operations allowed.
 * @param penalty (int): The current penalty (maximum number of balls allowed in any bag).
 * @return (bool): True if the penalty is achievable, False otherwise.
 */
bool canAchieve(int* nums, int numsSize, int maxOperations, int penalty) {
    int operations = 0;  // Initialize the number of operations performed

    // Iterate through each bag in nums
    for (int i = 0; i < numsSize; i++) {
        // Calculate the number of operations needed to reduce the bag size to <= penalty
        operations += (nums[i] - 1) / penalty;

        // If the operations exceed maxOperations, return false early
        if (operations > maxOperations) {
            return false;
        }
    }

    // If the total operations are within maxOperations, the penalty is achievable
    return true;
}

/**
 * @brief Minimizes the maximum number of balls in any bag after at most maxOperations.
 *
 * @param nums (int*): Array representing the number of balls in each bag.
 * @param numsSize (int): Size of the nums array.
 * @param maxOperations (int): Maximum number of operations allowed.
 * @return (int): The minimum possible penalty (maximum balls in any bag).
 */
int minimumSize(int* nums, int numsSize, int maxOperations) {
    // The penalty can range from 1 to the largest bag size in nums
    int left = 1;
    int right = 0;

    // Find the maximum number in the nums array to set the upper bound of the penalty
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) {
            right = nums[i];
        }
    }

    // Perform binary search to find the minimum possible penalty
    while (left < right) {
        int mid = left + (right - left) / 2;  // Middle point of the current search range

        // Check if the penalty 'mid' is achievable
        if (canAchieve(nums, numsSize, maxOperations, mid)) {
            right = mid;  // Try for a smaller penalty
        } else {
            left = mid + 1;  // Increase the penalty to make it achievable
        }
    }

    // Return the smallest achievable penalty
    return left;
}
