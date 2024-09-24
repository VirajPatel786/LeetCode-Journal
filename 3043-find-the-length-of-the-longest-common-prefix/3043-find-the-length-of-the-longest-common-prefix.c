#include <stdio.h>
#include <string.h>

/**
 * @brief Finds the length of the longest common prefix between pairs of numbers
 * in two arrays using a set-like structure for quick look-up of integer prefixes.
 *
 * @param arr1 Pointer to the first array of integers.
 * @param arr1Size Size of the first array.
 * @param arr2 Pointer to the second array of integers.
 * @param arr2Size Size of the second array.
 *
 * @return int: The length of the longest common prefix found.
 */
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int prefix_set[1000000] = {0}; // Array for storing prefixes, large enough for practical input.
    int max_common_prefix_length = 0;

    // Step 1: Add all possible prefixes of each number in arr1 to the set.
    for (int i = 0; i < arr1Size; i++) {
        int current_prefix = arr1[i];
        while (current_prefix > 0) {
            prefix_set[current_prefix] = 1; // Mark this prefix as present.
            current_prefix /= 10; // Remove the last digit.
        }
    }

    // Step 2: Check all numbers in arr2 for the longest matching prefix.
    for (int i = 0; i < arr2Size; i++) {
        int current_prefix = arr2[i];
        while (current_prefix > 0) {
            if (prefix_set[current_prefix]) {
                // A match is found. Calculate the length of this prefix.
                int length = 0, temp = current_prefix;
                while (temp > 0) {
                    length++;
                    temp /= 10; // Count the number of digits in the prefix.
                }
                if (length > max_common_prefix_length) {
                    max_common_prefix_length = length;
                }
                break; // Stop once we find the longest matching prefix.
            }
            current_prefix /= 10; // Remove the last digit.
        }
    }

    return max_common_prefix_length;
}
