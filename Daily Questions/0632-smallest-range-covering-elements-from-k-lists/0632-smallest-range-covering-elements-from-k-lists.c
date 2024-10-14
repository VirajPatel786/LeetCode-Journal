#include <stdlib.h>
#include <string.h>

/**
 * @brief Comparison function used for sorting.
 *
 * @param a (const void*): Pointer to the first element.
 * @param b (const void*): Pointer to the second element.
 *
 * @return (int): The difference between the two integers, used to sort in ascending order.
 */
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // Simple comparison for sorting integers
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Finds the smallest range that includes at least one number from each of the lists.
 *
 * @param nums (int**): A 2D array where each row is a sorted list.
 * @param numsSize (int): The number of lists.
 * @param numsColSize (int*): Array containing the size of each list.
 * @param returnSize (int*): Output parameter for the size of the result array.
 *
 * @return (int*): An array of size 2 representing the smallest range [start, end].
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    /* Calculate the total number of elements across all lists */
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        len += numsColSize[i];  // Accumulate the sizes of all lists
    }

    int idx = 0;
    int* data = (int*)calloc(len, sizeof(int));  // Allocate memory for all elements
    if (data == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    /* Store all elements in 'data' array with encoded list index */
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            // Encode element with list index: multiply element by 4096 and bitwise OR with list index
            data[idx++] = nums[i][j] * 4096 | i;
        }
    }

    /* Sort the 'data' array */
    qsort(data, len, sizeof(int), cmp);  // Sort based on element values

    /* Allocate memory for the result array to store the smallest range */
    int* ans = (int*)calloc(2, sizeof(int));
    if (ans == NULL) {
        free(data);
        return NULL;  // Return NULL if memory allocation fails
    }

    /* Initialize variables for sliding window approach */
    int left = 0, right = 0, listCnt = 0;  // left and right for the window, listCnt for tracking unique lists
    int minRange = (data[len - 1] >> 12) - (data[0] >> 12);  // Initial range
    ans[0] = data[0] >> 12;  // Starting point of the range
    ans[1] = data[len - 1] >> 12;  // End point of the range
    idx = 0;

    memset(numsColSize, 0, sizeof(int) * numsSize);  // Reuse numsColSize to count occurrences of list elements

    /* Sliding window to find the smallest range */
    while (right < len) {
        int listIdx = data[right++] & 0xFFF;  // Extract list index from encoded data
        numsColSize[listIdx]++;  // Count occurrence of element from list

        /* If all lists are represented in the window */
        if (numsColSize[listIdx] == 1) {
            listCnt++;  // Increment the count of lists in the current window

            /* Try to shrink the window from the left */
            while (listCnt == numsSize) {
                int currDiff = (data[right - 1] >> 12) - (data[left] >> 12);  // Calculate the current range
                if (currDiff < minRange) {  // Update the smallest range if a better one is found
                    ans[0] = data[left] >> 12;
                    ans[1] = data[right - 1] >> 12;
                    minRange = currDiff;
                }

                listIdx = data[left++] & 0xFFF;  // Move left pointer and reduce the count of that list's element
                numsColSize[listIdx]--;
                if (numsColSize[listIdx] == 0) {  // If a list is no longer represented, reduce the list count
                    listCnt--;
                }
            }
        }
    }

    *returnSize = 2;  // The result size is always 2 (start and end of the range)
    free(data);  // Free the dynamically allocated memory for 'data'
    return ans;  // Return the result array containing the smallest range
}
