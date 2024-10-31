#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

/**
 * @brief Compare function for sorting integers in ascending order.
 *
 * @param a (const void*): Pointer to the first element to compare.
 * @param b (const void*): Pointer to the second element to compare.
 *
 * @return (int): Returns the difference between the two elements, determining their order.
 */
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Compare function for sorting factories by position in ascending order.
 *
 * @param a (const void*): Pointer to the first factory's position.
 * @param b (const void*): Pointer to the second factory's position.
 *
 * @return (int): Returns the difference in positions between the two factories.
 */
int cmpfunc2(const void *a, const void *b) {
    return ((*(int **)a)[0] - (*(int **)b)[0]);
}

/**
 * @brief Calculate the minimum total distance that robots must travel to reach repairable factories.
 *
 * Uses dynamic programming to find the optimal assignment of robots to factories under the repair limits
 * of each factory, minimizing the travel distance.
 *
 * @param robot (int*): Array of robot positions.
 * @param robotSize (int): Number of robots in the robot array.
 * @param factory (int**): 2D array representing factories, where each factory has [position, limit].
 * @param factorySize (int): Number of factories in the factory array.
 * @param factoryColSize (int*): Array specifying the number of columns in each row of the factory array.
 *
 * @return (long long): Minimum total distance for all robots to be repaired.
 */
long long minimumTotalDistance(int* robot, int robotSize, int** factory, int factorySize, int* factoryColSize) {
    // Sort robots and factories for efficient assignment
    qsort(robot, robotSize, sizeof(int), cmpfunc);
    qsort(factory, factorySize, sizeof(int *), cmpfunc2);

    // Initialize dp array with maximum possible value (INT_MAX)
    long long dp[robotSize + 1][factorySize + 1];
    for (int i = 0; i <= robotSize; ++i) {
        for (int j = 0; j <= factorySize; ++j) {
            dp[i][j] = LLONG_MAX;
        }
    }
    dp[0][0] = 0;  // No robots, no factories, cost is zero.

    // Fill dp array to calculate minimum distances
    for (int j = 1; j <= factorySize; ++j) {
        int pos = factory[j - 1][0];    // Factory position
        int limit = factory[j - 1][1];  // Maximum robots the factory can repair

        for (int i = 0; i <= robotSize; ++i) {
            // Case 1: Skip the current factory
            dp[i][j] = dp[i][j - 1];

            // Case 2: Assign up to `limit` robots to this factory
            long long total_distance = 0;
            for (int k = 1; k <= min(i, limit); ++k) {
                total_distance += abs(robot[i - k] - pos);
                if (dp[i - k][j - 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + total_distance);
                }
            }
        }
    }

    return dp[robotSize][factorySize];
}
