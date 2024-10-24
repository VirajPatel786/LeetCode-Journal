#include <stdlib.h>

/**
 * @brief Traverse the matrix diagonally and return the elements in diagonal order.
 *
 * @param mat (int**): The input matrix.
 * @param matSize (int): The number of rows in the matrix.
 * @param matColSize (int*): The number of columns in each row of the matrix.
 * @param returnSize (int*): Pointer to store the size of the returned array.
 *
 * @return (int*): A dynamically allocated array of elements in diagonal order.
 *                 The caller must free the returned array.
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize;        // Number of rows
    int n = matColSize[0];  // Number of columns (assuming the matrix is well-formed)
    
    // Allocate memory for the result array to hold all matrix elements
    int* result = (int*)malloc(m * n * sizeof(int));
    
    // Initialize variables to track the current position and direction
    int row = 0, col = 0;
    int direction = 1;  // 1 means moving up-right, -1 means moving down-left
    
    // Traverse the matrix for m * n elements
    for (int i = 0; i < m * n; i++) {
        result[i] = mat[row][col];  // Store the current element in the result array
        
        // Handle moving in the up-right direction
        if (direction == 1) {
            if (col == n - 1) {  // Hit the last column, go down to the next row
                row++;
                direction = -1;  // Change direction to down-left
            } else if (row == 0) {  // Hit the top row, move right to the next column
                col++;
                direction = -1;  // Change direction to down-left
            } else {  // Continue moving up-right
                row--;
                col++;
            }
        }
        // Handle moving in the down-left direction
        else {
            if (row == m - 1) {  // Hit the last row, move right to the next column
                col++;
                direction = 1;  // Change direction to up-right
            } else if (col == 0) {  // Hit the first column, move down to the next row
                row++;
                direction = 1;  // Change direction to up-right
            } else {  // Continue moving down-left
                row++;
                col--;
            }
        }
    }
    
    *returnSize = m * n;  // Set the return size as the total number of elements
    return result;        // Return the dynamically allocated result array
}
