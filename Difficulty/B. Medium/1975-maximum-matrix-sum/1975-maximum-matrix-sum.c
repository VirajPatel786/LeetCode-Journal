#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/**
 * @brief Maximizes the sum of matrix elements using the given operation.
 *
 * @param matrix (int**): The n x n integer matrix.
 * @param matrixSize (int): The size of the matrix (number of rows).
 * @param matrixColSize (int*): The column size of the matrix (all rows have the same length).
 * @return (long long): Maximum sum of the matrix elements.
 */
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long total_sum = 0;       // Total sum of absolute values
    int min_abs_val = INT_MAX;     // Smallest absolute value in the matrix
    int negative_count = 0;        // Count of negative numbers in the matrix

    // Traverse each element in the matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            int abs_val = abs(matrix[i][j]);  // Get the absolute value of the current element
            total_sum += abs_val;            // Add the absolute value to the total sum
            if (abs_val < min_abs_val) {
                min_abs_val = abs_val;       // Track the smallest absolute value
            }
            if (matrix[i][j] < 0) {
                negative_count++;            // Count negative numbers
            }
        }
    }

    // If the count of negatives is odd, subtract twice the smallest absolute value
    if (negative_count % 2 == 1) {
        total_sum -= 2LL * min_abs_val;
    }

    return total_sum;  // Return the maximum sum
}
