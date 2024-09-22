#include <stdio.h>

/**
 * @brief Finds the k-th lexicographically smallest integer in the range [1, n].
 *
 * @param n (int): The upper limit of the range.
 * @param k (int): The position (1-indexed) of the lexicographically smallest number to find.
 * @return (int): The k-th lexicographically smallest number.
 */
int findKthNumber(int n, int k) {
    int current_number = 1;  // Start with the smallest lexicographical number (1).

    // Continue until we find the k-th smallest number.
    while (k > 1) {
        long count = 0;  // Count of numbers in the subtree rooted at `current_number`.

        // Calculate how many numbers exist under the prefix `current_number`.
        for (long step_size = 1, prefix = current_number; prefix <= n; prefix *= 10, step_size *= 10) {
            // Count numbers in the range [prefix, min(prefix + step_size - 1, n)].
            count += (n - prefix + 1 < step_size) ? (n - prefix + 1) : step_size;
        }

        // If the subtree rooted at `current_number` contains fewer than `k` numbers, skip it.
        if (k > count) {
            k -= count;  // Skip the current subtree.
            current_number++;  // Move to the next lexicographical prefix.
        } else {
            k--;  // Go deeper into the current subtree.
            current_number *= 10;  // Move to the next level in the tree (prefix `current_number` becomes `current_number0`).
        }
    }

    return current_number;  // Return the k-th smallest number.
}