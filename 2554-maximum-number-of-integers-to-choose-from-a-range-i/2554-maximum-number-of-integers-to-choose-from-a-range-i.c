#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Finds the maximum number of integers that can be chosen
 *        from the range [1, n] under the given constraints.
 *
 * @param banned (int*): Array of banned integers.
 * @param bannedSize (int): Size of the banned array.
 * @param n (int): Maximum integer in the range [1, n].
 * @param maxSum (int): Maximum allowed sum of chosen integers.
 * @return int: Maximum number of integers that can be chosen.
 */
int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    // Step 1: Create a hash set for the banned numbers
    bool* bannedSet = (bool*)calloc(n + 1, sizeof(bool));
    for (int i = 0; i < bannedSize; i++) {
        if (banned[i] <= n) {
            bannedSet[banned[i]] = true;
        }
    }

    // Step 2: Iterate over the range [1, n] and calculate the result
    int currentSum = 0, count = 0;
    for (int num = 1; num <= n; num++) {
        if (bannedSet[num]) {
            continue;  // Skip banned numbers
        }
        if (currentSum + num > maxSum) {
            break;  // Stop if adding num exceeds maxSum
        }
        currentSum += num;
        count++;
    }

    // Step 3: Free memory and return the result
    free(bannedSet);
    return count;
}
