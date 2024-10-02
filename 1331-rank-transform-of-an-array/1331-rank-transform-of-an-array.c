#include <stdio.h>
#include <stdlib.h>

// Define a structure to store both the value of the element and its original index
typedef struct {
    int value;
    int index;
} Element;

/**
 * @brief Compare function for qsort.
 *
 * This function is used by qsort to compare two elements based on their values.
 *
 * @param a (const void*): First element to compare.
 * @param b (const void*): Second element to compare.
 * @return int: Result of comparison, negative if a < b, 0 if a == b, positive if a > b.
 */
int cmp(const void* a, const void* b) {
    return ((Element*)a)->value - ((Element*)b)->value;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Rank transformation of an array.
 *
 * This function replaces each element in the array with its rank based on its value.
 * The smallest element gets rank 1, and equal elements get the same rank.
 *
 * @param arr (int*): Input array of integers.
 * @param arrSize (int): Size of the input array.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 * @return int*: Pointer to the dynamically allocated array containing the rank transformed values.
 */
int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    // Handle empty array case
    if (arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory for the result array to store the ranks
    int* result = (int*)malloc(arrSize * sizeof(int));
    // Allocate memory to store the elements and their original indices
    Element* elements = (Element*)malloc(arrSize * sizeof(Element));

    // Prepare elements array by copying values from the input array and storing their indices
    for (int i = 0; i < arrSize; i++) {
        elements[i].value = arr[i];
        elements[i].index = i;
    }

    // Sort the elements by value, while preserving their original indices
    qsort(elements, arrSize, sizeof(Element), cmp);

    // Start assigning ranks, initialize the rank to 1 for the smallest element
    int rank = 1;
    result[elements[0].index] = rank; // The smallest element gets rank 1

    // Traverse the sorted elements and assign ranks, ensuring that equal elements get the same rank
    for (int i = 1; i < arrSize; i++) {
        // If the current element is different from the previous one, increment the rank
        if (elements[i].value != elements[i - 1].value) {
            rank++;
        }
        // Assign the rank based on the original index of the element
        result[elements[i].index] = rank;
    }

    // Free the memory allocated for the elements array as it is no longer needed
    free(elements);

    // Set the return size to the size of the input array
    *returnSize = arrSize;

    // Return the result array containing the rank transformation
    return result;
}

