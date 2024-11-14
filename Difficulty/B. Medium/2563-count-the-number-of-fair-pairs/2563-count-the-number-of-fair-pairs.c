#include <stdlib.h>

/**
 * @brief Compares two integers, used for sorting.
 *
 * @param a (const void*): Pointer to the first integer.
 * @param b (const void*): Pointer to the second integer.
 *
 * @return int: Negative if *a < *b, zero if *a == *b, positive if *a > *b.
 */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Finds the left boundary for binary search.
 *        Returns the first index where nums[j] >= target.
 *
 * @param nums (int*): The sorted array of integers.
 * @param start (int): The starting index for the search range.
 * @param end (int): The ending index for the search range.
 * @param target (int): The target value for comparison.
 *
 * @return int: The first index where nums[index] >= target.
 */
int binary_search_left(int *nums, int start, int end, int target) {
    while (start < end) {
        int mid = start + (end - start) / 2;
        // Move start to mid + 1 if nums[mid] is less than target
        if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;  // Narrow down to the left half
        }
    }
    return start;
}

/**
 * @brief Finds the right boundary for binary search.
 *        Returns the first index where nums[j] > target.
 *
 * @param nums (int*): The sorted array of integers.
 * @param start (int): The starting index for the search range.
 * @param end (int): The ending index for the search range.
 * @param target (int): The target value for comparison.
 *
 * @return int: The first index where nums[index] > target.
 */
int binary_search_right(int *nums, int start, int end, int target) {
    while (start < end) {
        int mid = start + (end - start) / 2;
        // Move start to mid + 1 if nums[mid] is <= target
        if (nums[mid] <= target) {
            start = mid + 1;
        } else {
            end = mid;  // Narrow down to the left half
        }
    }
    return start;
}

/**
 * @brief Counts the number of fair pairs (i, j) in an array such that:
 *        - 0 <= i < j < numsSize
 *        - lower <= nums[i] + nums[j] <= upper
 *
 * @param nums (int*): The array of integers.
 * @param numsSize (int): The size of the array.
 * @param lower (int): The lower bound for the sum of pairs.
 * @param upper (int): The upper bound for the sum of pairs.
 *
 * @return long long: The count of fair pairs that satisfy the conditions.
 */
long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    // Sort the array to facilitate binary search for valid pairs
    qsort(nums, numsSize, sizeof(int), compare);

    long long count = 0;  // Initialize count of fair pairs

    // Iterate through each element to find fair pairs
    for (int i = 0; i < numsSize - 1; i++) {
        // Calculate the range for valid pairs with nums[i]
        int min_val = lower - nums[i];
        int max_val = upper - nums[i];

        // Binary search for the left boundary (first index where nums[j] >= min_val)
        int j_start = binary_search_left(nums, i + 1, numsSize, min_val);

        // Binary search for the right boundary (first index where nums[j] > max_val)
        int j_end = binary_search_right(nums, i + 1, numsSize, max_val) - 1;

        // Add the count of valid pairs in the range [j_start, j_end]
        if (j_start <= j_end) {
            count += (j_end - j_start + 1);
        }
    }

    return count;
}
