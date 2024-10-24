#include <stdlib.h>

/**
 * @brief Return all elements of the matrix in spiral order.
 *
 * @param matrix (int**): The input matrix.
 * @param matrixSize (int): The number of rows in the matrix.
 * @param matrixColSize (int*): An array of size matrixSize, each element containing the number of columns in the corresponding row.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 *
 * @return (int*): A dynamically allocated array containing elements in spiral order.
 *                 The caller must free this array.
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;  // Number of rows
    int n = matrixColSize[0];  // Number of columns (assuming matrix is well-formed)

    // Allocate memory for the result array
    int* result = (int*)malloc(m * n * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize the boundaries of the matrix
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int index = 0;

    // Traverse the matrix in spiral order
    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int col = left; col <= right; col++) {
            result[index++] = matrix[top][col];
        }
        top++;  // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int row = top; row <= bottom; row++) {
            result[index++] = matrix[row][right];
        }
        right--;  // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int col = right; col >= left; col--) {
                result[index++] = matrix[bottom][col];
            }
            bottom--;  // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int row = bottom; row >= top; row--) {
                result[index++] = matrix[row][left];
            }
            left++;  // Move the left boundary right
        }
    }

    *returnSize = m * n;  // Set the return size to the total number of elements
    return result;        // Return the dynamically allocated result array
}
