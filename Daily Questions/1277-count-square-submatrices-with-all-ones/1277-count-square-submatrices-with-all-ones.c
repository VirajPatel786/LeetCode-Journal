#include <stdio.h>

/**
 * @brief Counts the number of square submatrices with all ones in the given matrix.
 *
 * @param matrix (int**): Pointer to the 2D binary matrix (1s and 0s).
 * @param matrixSize (int): Number of rows in the matrix.
 * @param matrixColSize (int*): Array where each element indicates the number of columns per row.
 *
 * @return (int): Total number of square submatrices with all ones.
 */
int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int total_squares = 0; // Variable to accumulate total count of square submatrices
    int dp[matrixSize][matrixColSize[0]]; // DP array to store the size of largest square ending at each cell

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            if (matrix[i][j] == 1) { // Only proceed if cell has a 1
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // Edge cells can only form 1x1 squares
                } else {
                    // Calculate the largest square size that can end at this cell
                    dp[i][j] = (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
                    dp[i][j] = (dp[i][j] < dp[i - 1][j - 1] ? dp[i][j] : dp[i - 1][j - 1]) + 1;
                }
                total_squares += dp[i][j]; // Add to total count
            } else {
                dp[i][j] = 0; // No square can end at this cell if it contains 0
            }
        }
    }
    
    return total_squares;
}
