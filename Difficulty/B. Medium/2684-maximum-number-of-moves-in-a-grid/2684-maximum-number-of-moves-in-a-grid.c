#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Calculates the maximum number of valid moves in a grid.
 * 
 * This function calculates the maximum number of moves starting from any cell
 * in the first column. A move is valid only if the target cell has a strictly 
 * greater value than the current cell.
 * 
 * @param grid (int**): 2D array representing the grid of positive integers.
 * @param gridSize (int): Number of rows in the grid.
 * @param gridColSize (int*): Pointer to the number of columns in each row (all equal).
 * 
 * @return int: The maximum number of moves possible from any cell in the first column,
 *              or 0 if no valid moves are possible.
 */
int maxMoves(int** grid, int gridSize, int* gridColSize) {
    int numRows = gridSize;
    int numCols = gridColSize[0];  // Number of columns in each row

    // Array to track rows in the current column that can initiate moves
    bool* canMoveFromCurrentCol = (bool*)malloc(numRows * sizeof(bool));
    // Array to track rows in the next column that are reachable from the current column
    bool* canMoveToNextCol = (bool*)malloc(numRows * sizeof(bool));

    // Initialize the current column moves tracking as true for each row
    for (int i = 0; i < numRows; i++) {
        canMoveFromCurrentCol[i] = true;
    }

    // Iterate over each column except the last one
    for (int colIdx = 0; colIdx < numCols - 1; colIdx++) {
        // Reset the next column tracking array to false
        for (int i = 0; i < numRows; i++) {
            canMoveToNextCol[i] = false;
        }

        // Iterate over each row in the current column
        for (int rowIdx = 0; rowIdx < numRows; rowIdx++) {
            // Skip rows that cannot make a move from the current column
            if (!canMoveFromCurrentCol[rowIdx]) {
                continue;
            }

            // Check moves from the current cell to the next column in three directions:
            // 1. Up-right move (only if there is a row above)
            if (rowIdx > 0 && grid[rowIdx - 1][colIdx + 1] > grid[rowIdx][colIdx]) {
                canMoveToNextCol[rowIdx - 1] = true;
            }

            // 2. Rightward move to the same row
            if (grid[rowIdx][colIdx + 1] > grid[rowIdx][colIdx]) {
                canMoveToNextCol[rowIdx] = true;
            }

            // 3. Down-right move (only if there is a row below)
            if (rowIdx + 1 < numRows && grid[rowIdx + 1][colIdx + 1] > grid[rowIdx][colIdx]) {
                canMoveToNextCol[rowIdx + 1] = true;
            }
        }

        // Check if any moves are possible to the next column
        bool anyMovePossible = false;
        for (int i = 0; i < numRows; i++) {
            if (canMoveToNextCol[i]) {
                anyMovePossible = true;
                break;
            }
        }

        // If no moves are possible to any row in the next column, return the current column index
        if (!anyMovePossible) {
            free(canMoveFromCurrentCol);
            free(canMoveToNextCol);
            return colIdx;
        }

        // Update current column tracking with next column's move possibilities
        for (int i = 0; i < numRows; i++) {
            canMoveFromCurrentCol[i] = canMoveToNextCol[i];
        }
    }

    // If we finish iterating through all columns, check if any move is possible in the last column
    bool anyMoveInLastColumn = false;
    for (int i = 0; i < numRows; i++) {
        if (canMoveFromCurrentCol[i]) {
            anyMoveInLastColumn = true;
            break;
        }
    }

    // Free allocated memory
    free(canMoveFromCurrentCol);
    free(canMoveToNextCol);

    // Return the number of moves based on the last column state
    return anyMoveInLastColumn ? numCols - 1 : numCols - 2;
}
