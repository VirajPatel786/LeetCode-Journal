#include <stdio.h>

/**
 * @brief Calculate the minimum possible last element of a strictly increasing array with a given bitwise AND.
 *
 * @param n (int): The length of the array.
 * @param x (int): The target bitwise AND value.
 *
 * @return (long long): The minimum possible value of the last element in the array.
 */
long long minEnd(int n, int x) {
    // Start with the minimum last element as `x` since we need the final AND to be `x`
    long long min_last_element = x;

    // Number of increments needed to make an increasing sequence of length `n`
    int increments_needed = n - 1;

    // Current bit position, starting from the least significant bit
    long long bit_position = 1;

    // Iterate while we still have increments needed
    while (increments_needed > 0) {
        // Check if the current bit position in `x` is not set (0)
        if (!(x & bit_position)) {
            // Set this bit in `min_last_element` only if the current increment is needed
            min_last_element |= (long long)(increments_needed & 1) * bit_position;

            // Right-shift `increments_needed` by 1 to process the next bit
            increments_needed >>= 1;
        }
        
        // Move to the next bit position (shift left by 1)
        bit_position <<= 1;
    }

    return min_last_element;
}
