#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Check if array can be divided into pairs such that the sum of each pair is divisible by k.
 *
 * @param arr (int*): The input array of integers.
 * @param arrSize (int): The number of elements in the array.
 * @param k (int): The divisor for divisibility check.
 *
 * @return bool: True if the array can be arranged, otherwise False.
 */
bool canArrange(int* arr, int arrSize, int k) {
    // Create a variable-length array to count the frequency of remainders
    int remainder_count[k];
    
    // Initialize the remainder_count array to zero using memset
    memset(remainder_count, 0, sizeof(remainder_count));

    // Traverse the array to calculate remainders and store their frequency
    for (int i = 0; i < arrSize; i++) {
        int remainder = arr[i] % k;

        // Adjust the remainder if it is negative to ensure all remainders are non-negative
        if (remainder < 0) {
            remainder += k;
        }
        remainder_count[remainder] += 1;  // Increment count for this remainder
    }

    // Special case: Check if the number of elements with remainder 0 is even
    if (remainder_count[0] % 2 != 0) {
        return false;
    }

    // Check pairs for other remainders
    for (int i = 1; i < k / 2 + 1; i++) {
        // The count of elements with remainder i should match the count of remainder k-i
        if (remainder_count[i] != remainder_count[k - i]) {
            return false;
        }
    }

    // Special case for when k is even: elements with remainder k/2 must pair with each other
    if (k % 2 == 0 && remainder_count[k / 2] % 2 != 0) {
        return false;
    }

    // If all checks are passed, return true
    return true;
}