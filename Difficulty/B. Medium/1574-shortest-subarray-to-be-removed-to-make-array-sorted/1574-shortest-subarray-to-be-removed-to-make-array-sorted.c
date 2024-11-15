#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the length of the shortest subarray to remove to make the array non-decreasing.
 *
 * @param arr (int*): The input array.
 * @param arrSize (int): The size of the array.
 *
 * @return (int): The length of the shortest subarray to remove.
 */
int findLengthOfShortestSubarray(int* arr, int arrSize) {
    int left = 0;              // Pointer to track the non-decreasing prefix
    int right = arrSize - 1;   // Pointer to track the non-decreasing suffix

    // Step 1: Find the longest non-decreasing prefix
    while (left < arrSize - 1 && arr[left] <= arr[left + 1]) {
        left++;
    }

    // If the entire array is already sorted, no removal is needed
    if (left == arrSize - 1) {
        return 0;
    }

    // Step 2: Find the longest non-decreasing suffix
    while (right > 0 && arr[right - 1] <= arr[right]) {
        right--;
    }

    // Step 3: Calculate the minimum length to remove by considering:
    // - Removing everything after the prefix
    // - Removing everything before the suffix
    int min_length = arrSize - (left + 1);  // Remove everything after the prefix
    min_length = (right < min_length) ? right : min_length;  // Remove everything before the suffix

    // Step 4: Use two pointers to merge prefix and suffix
    int i = 0;         // Start of prefix
    int j = right;     // Start of suffix
    while (i <= left && j < arrSize) {
        if (arr[i] <= arr[j]) {
            // If prefix element is less than or equal to suffix element, it's a valid merge point
            int length_to_remove = j - i - 1;  // Calculate the length of the subarray to remove
            if (length_to_remove < min_length) {
                min_length = length_to_remove;  // Update the minimum length
            }
            i++;  // Move the prefix pointer
        } else {
            j++;  // Move the suffix pointer to find a larger element
        }
    }

    // Return the minimum length of the subarray to remove
    return min_length;
}
