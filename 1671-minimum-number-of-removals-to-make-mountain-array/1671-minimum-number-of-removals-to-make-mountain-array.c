#include <stdio.h>
#include <stdlib.h>

// Define MAX macro for easy readability
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief Binary search helper to find the insertion point in a sorted array.
 *
 * @param arr (int*): Array in which to search.
 * @param size (int): Current size of the array.
 * @param target (int): Target value to search.
 * @return (int): Position where target should be placed.
 */
int binarySearchInsertPosition(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

/**
 * @brief Calculates the minimum number of elements to remove to make the array a mountain array.
 *
 * @param nums (int*): Pointer to the input array of integers.
 * @param numsSize (int): Size of the input array.
 * @return (int): Minimum number of elements to remove to form a mountain array.
 */
int minimumMountainRemovals(int* nums, int numsSize) {
    int* lis_length = (int*)malloc(numsSize * sizeof(int));
    int* lds_length = (int*)malloc(numsSize * sizeof(int));
    int* aux_seq = (int*)malloc(numsSize * sizeof(int));
    
    int seq_len, max_mountain_length = 0;

    // Step 1: Compute longest increasing subsequence (LIS) lengths ending at each index
    seq_len = 0;
    for (int i = 0; i < numsSize; i++) {
        int pos = binarySearchInsertPosition(aux_seq, seq_len, nums[i]);
        if (pos == seq_len) {
            aux_seq[seq_len++] = nums[i];
        } else {
            aux_seq[pos] = nums[i];
        }
        lis_length[i] = pos + 1;
    }

    // Step 2: Compute longest decreasing subsequence (LDS) lengths starting at each index
    seq_len = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        int pos = binarySearchInsertPosition(aux_seq, seq_len, nums[i]);
        if (pos == seq_len) {
            aux_seq[seq_len++] = nums[i];
        } else {
            aux_seq[pos] = nums[i];
        }
        lds_length[i] = pos + 1;
    }

    // Step 3: Find the maximum length of a valid mountain subarray
    for (int i = 1; i < numsSize - 1; i++) {
        if (lis_length[i] > 1 && lds_length[i] > 1) {
            int mountain_length = lis_length[i] + lds_length[i] - 1;
            max_mountain_length = MAX(max_mountain_length, mountain_length);
        }
    }

    // Step 4: Calculate minimum removals and free memory
    int min_removals = numsSize - max_mountain_length;
    
    free(lis_length);
    free(lds_length);
    free(aux_seq);
    
    return min_removals;
}
