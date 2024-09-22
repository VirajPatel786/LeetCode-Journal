#include <stdio.h>

/**
 * @brief Counts how many numbers exist with the given prefix in the range [1, n].
 *
 * @param prefix (long long): The current prefix (root of a subtree in lexicographical order).
 * @param n (long long): The upper limit of the range.
 * @return (int): The number of lexicographical steps (i.e., valid numbers) between `prefix`
 *                and `next_prefix` that are within the range [1, n].
 */
int count_steps(long long prefix, long long n) {
    long long current = prefix;
    long long next_prefix = prefix + 1;
    int steps = 0;

    // Traverse down the tree by powers of 10, counting how many numbers lie between
    // `prefix` and `next_prefix` at each level of the tree.
    while (current <= n) {
        // Add the range of numbers from `current` to `min(n + 1, next_prefix)` in the current level.
        steps += (next_prefix <= n + 1 ? next_prefix : n + 1) - current;
        current *= 10;       // Move to the next level in the tree (by appending digits to the prefix)
        next_prefix *= 10;   // Update the next_prefix accordingly.
    }
    return steps;
}

/**
 * @brief Finds the k-th lexicographically smallest integer in the range [1, n].
 *
 * @param n (int): The upper limit of the range.
 * @param k (int): The position (1-indexed) of the lexicographically smallest number to find.
 * @return (int): The k-th lexicographically smallest number.
 */
int findKthNumber(int n, int k) {
    int current = 1;
    k--;  // The first number is `1`, so decrement k by 1 to handle zero-indexing.

    // Loop until we find the k-th smallest number.
    while (k > 0) {
        // Count how many numbers exist in the subtree rooted at `current`.
        int steps = count_steps(current, n);

        if (steps <= k) {
            // If the entire subtree rooted at `current` has fewer or equal numbers than `k`,
            // skip this subtree by moving to the next prefix.
            current += 1;
            k -= steps;
        } else {
            // If the subtree contains more than `k` numbers, go deeper into the subtree
            // by multiplying `current` by 10 to move to the next level.
            current *= 10;
            k -= 1;
        }
    }

    return current;
}