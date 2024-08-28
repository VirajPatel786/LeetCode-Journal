#include <string.h>
#include <math.h>

// Global memoization table to store the maximum stones Alice can collect
int dp[100][100] = {0};

// Recursive helper function to determine the maximum stones Alice can collect
// s: Array of suffix sums
// n: Total number of piles
// M: Current maximum move size
// p: Current pile index
int maxStones(int *s, int n, int M, int p) {
    // If the remaining piles are fewer than or equal to 2 * M, take all remaining stones
    if (p + 2 * M >= n) return s[p];

    // If this subproblem has already been solved, return the stored result
    if (dp[p][M] > 0) return dp[p][M];

    int max_stones = 0;
    // Try taking X piles where 1 <= X <= 2 * M
    for (int X = 1; X <= 2 * M; X++) {
        // Calculate the maximum stones Alice can get by subtracting the stones Bob would get
        max_stones = fmax(max_stones, s[p] - maxStones(s, n, fmax(X, M), p + X));
    }

    // Store the result in the memoization table
    dp[p][M] = max_stones;
    return max_stones;
}

// Main function to solve the Stone Game II problem
int stoneGameII(int* piles, int pilesSize) {
    // Reset the dp table for this game instance
    memset(dp, 0, sizeof(dp));

    // Create the suffix sum array to store the cumulative sum of stones from current pile to the end
    int suffix_sum[pilesSize];
    suffix_sum[pilesSize - 1] = piles[pilesSize - 1];
    for (int i = pilesSize - 2; i >= 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + piles[i];
    }

    // Start the recursive process from the first pile with an initial M of 1
    return maxStones(suffix_sum, pilesSize, 1, 0);
}