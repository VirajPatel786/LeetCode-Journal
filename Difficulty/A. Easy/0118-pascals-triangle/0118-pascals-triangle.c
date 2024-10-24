#include <stdlib.h>

/**
 * @brief Generate Pascal's Triangle up to 'numRows' rows.
 *
 * @param numRows (int): The number of rows of Pascal's Triangle to generate.
 * @param returnSize (int*): Pointer to return the number of rows (numRows).
 * @param returnColumnSizes (int**): Pointer to return the size of each row (number of elements in each row).
 *
 * @return (int**): A dynamically allocated 2D array containing Pascal's Triangle.
 *                  The caller must free both the returned array and the returnColumnSizes array.
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the Pascal's Triangle (2D array)
    int** pascalTriangle = (int**)malloc(numRows * sizeof(int*));

    // Allocate memory for the returnColumnSizes array to store the size of each row
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // Generate each row of Pascal's Triangle
    for (int i = 0; i < numRows; i++) {
        // Allocate memory for the current row (i + 1 elements)
        pascalTriangle[i] = (int*)malloc((i + 1) * sizeof(int));

        // Set the size of the current row in the returnColumnSizes array
        (*returnColumnSizes)[i] = i + 1;

        // First and last elements of the row are always 1
        pascalTriangle[i][0] = 1;
        pascalTriangle[i][i] = 1;

        // Fill the elements between the first and last by summing values from the previous row
        for (int j = 1; j < i; j++) {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
    }

    // Set the return size (number of rows)
    *returnSize = numRows;

    // Return the generated Pascal's Triangle
    return pascalTriangle;
}
