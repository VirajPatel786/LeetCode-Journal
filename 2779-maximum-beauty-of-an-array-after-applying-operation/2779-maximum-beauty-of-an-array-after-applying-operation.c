#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Compare function for sorting integers in ascending order.
 *
 * @param a (const void *): Pointer to the first integer.
 * @param b (const void *): Pointer to the second integer.
 *
 * @return (int): Difference between *a and *b.
 */
static int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * @brief Find the maximum beauty of the array after applying the operation.
 *
 * @param nums (int *): The input array.
 * @param numsSize (int): The size of the input array.
 * @param k (int): The maximum allowable change for each element.
 *
 * @return (int): The maximum possible beauty of the array.
 */
int maximumBeauty(int *nums, int numsSize, int k) {
    int left = 0;       /* Initialize the left pointer of the sliding window */
    int max_beauty = 0; /* Variable to store the maximum beauty */
    int right;          /* Variable for the right pointer in the sliding window */

    /* Sort the array in ascending order to facilitate range overlap checks */
    qsort(nums, numsSize, sizeof(int), compare);

    /* Sliding window to find the maximum overlapping range */
    for (right = 0; right < numsSize; ++right)
    {
        /* Maintain the window where the difference between nums[right] and nums[left]
         * does not exceed 2 * k, representing allowable range changes */
        while (nums[right] - nums[left] > 2 * k)
        {
            ++left; /* Move the left pointer to maintain the valid window */
        }

        /* Calculate the current window size and update max_beauty if needed */
        int current_beauty = right - left + 1;
        if (current_beauty > max_beauty)
        {
            max_beauty = current_beauty;
        }
    }

    return max_beauty; /* Return the maximum beauty found */
}
