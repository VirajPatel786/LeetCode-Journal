#include <stdlib.h>

/**
 * @brief Comparator function for sorting items by price.
 *
 * @param a (const void*): Pointer to the first item (a pointer to an array of two integers).
 * @param b (const void*): Pointer to the second item (a pointer to an array of two integers).
 *
 * @return int: The comparison result; negative if a < b, zero if a == b, positive if a > b.
 */
int compare(const void* a, const void* b) {
    int priceA = (*(int**)a)[0];
    int priceB = (*(int**)b)[0];
    return priceA - priceB;
}

/**
 * @brief Computes the maximum beauty for each query based on item prices and their beauties.
 *
 * @param items (int**): A 2D array where each sub-array contains [price, beauty] for each item.
 * @param itemsSize (int): Number of items in the array.
 * @param itemsColSize (int*): Array representing the number of columns in each row of items (always 2 here).
 * @param queries (int*): Array of maximum prices for which to find the maximum beauty.
 * @param queriesSize (int): Size of the queries array.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 *
 * @return int*: An array containing the maximum beauty for each query. Caller is responsible for freeing the memory.
 */
int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    // Step 1: Sort items by price (ascending)
    qsort(items, itemsSize, sizeof(int*), compare);

    // Step 2: Build a prefix maximum beauty array for sorted prices
    int* prefix_max = (int*)malloc(itemsSize * sizeof(int));
    int* prices = (int*)malloc(itemsSize * sizeof(int));
    int max_beauty = 0;
    for (int i = 0; i < itemsSize; ++i) {
        prices[i] = items[i][0];
        max_beauty = (items[i][1] > max_beauty) ? items[i][1] : max_beauty;
        prefix_max[i] = max_beauty;
    }

    // Step 3: Allocate memory for the result array
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));

    // Function to perform binary search to find the rightmost index of price <= query
    int binary_search(int* arr, int size, int target) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }

    // Step 4: Process each query
    for (int i = 0; i < queriesSize; ++i) {
        int idx = binary_search(prices, itemsSize, queries[i]);
        result[i] = (idx >= 0) ? prefix_max[idx] : 0;  // Set beauty if available, else 0
    }

    // Free allocated memory for intermediate arrays
    free(prefix_max);
    free(prices);

    return result;
}
