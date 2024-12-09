#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Determines if subarrays defined by queries are special.
 *
 * @param nums (int*): The input array of integers.
 * @param numsSize (int): The size of the nums array.
 * @param queries (int**): The list of queries where each query is [from, to].
 * @param queriesSize (int): The number of queries.
 * @param queriesColSize (int*): The size of each query (always 2).
 * @param returnSize (int*): The size of the returned boolean array.
 *
 * @return (bool*): A boolean array indicating if each subarray is special.
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Handle the edge case where numsSize is 1
    if (numsSize == 1) {
        bool* result = (bool*)malloc(queriesSize * sizeof(bool));
        if (!result) {
            return NULL; // Handle memory allocation failure
        }
        for (int i = 0; i < queriesSize; i++) {
            result[i] = true; // A single-element subarray is always special
        }
        *returnSize = queriesSize;
        return result;
    }

    // Step 1: Allocate memory for the special_prefix array
    bool* special_prefix = (bool*)malloc((numsSize - 1) * sizeof(bool));
    if (!special_prefix) {
        return NULL; // Handle memory allocation failure
    }

    // Populate special_prefix: true if adjacent elements have different parity
    for (int i = 0; i < numsSize - 1; i++) {
        special_prefix[i] = (nums[i] % 2) != (nums[i + 1] % 2) ? true : false;
    }

    // Step 2: Compute prefix sum of the special_prefix array
    int* prefix_sum = (int*)malloc((numsSize - 1) * sizeof(int));
    if (!prefix_sum) {
        free(special_prefix); // Free previously allocated memory
        return NULL;          // Handle memory allocation failure
    }

    prefix_sum[0] = special_prefix[0] ? 1 : 0;
    for (int i = 1; i < numsSize - 1; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + (special_prefix[i] ? 1 : 0);
    }

    // Step 3: Allocate memory for the result array
    bool* result = (bool*)malloc(queriesSize * sizeof(bool));
    if (!result) {
        free(special_prefix);
        free(prefix_sum);
        return NULL; // Handle memory allocation failure
    }
    *returnSize = queriesSize;

    // Step 4: Process each query
    for (int i = 0; i < queriesSize; i++) {
        int start = queries[i][0];
        int end = queries[i][1];

        if (start == end) {
            result[i] = true; // A single element is always special
        } else {
            // Calculate the count of special pairs in the range [start, end - 1]
            int special_count = prefix_sum[end - 1] - (start > 0 ? prefix_sum[start - 1] : 0);
            result[i] = (special_count == (end - start));
        }
    }

    // Free allocated memory for temporary arrays
    free(special_prefix);
    free(prefix_sum);

    return result;
}
