#include <stdlib.h>

/**
 * @brief Counts the unguarded cells in a grid.
 *
 * @param m (int): Number of rows in the grid.
 * @param n (int): Number of columns in the grid.
 * @param guards (int**): Array of guard positions.
 * @param guardsSize (int): Number of guards.
 * @param guardsColSize (int*): Array specifying the column sizes of the guards array.
 * @param walls (int**): Array of wall positions.
 * @param wallsSize (int): Number of walls.
 * @param wallsColSize (int*): Array specifying the column sizes of the walls array.
 *
 * @return (int): Number of unguarded cells in the grid.
 */
int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    // Allocate and initialize the grid
    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0; // 0 means unoccupied
        }
    }

    // Mark guards as 1 and walls as 2
    for (int i = 0; i < guardsSize; i++) {
        grid[guards[i][0]][guards[i][1]] = 1;
    }
    for (int i = 0; i < wallsSize; i++) {
        grid[walls[i][0]][walls[i][1]] = 2;
    }

    // Directions for traversal: up, right, down, left
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Mark guarded cells
    for (int i = 0; i < guardsSize; i++) {
        int guardRow = guards[i][0];
        int guardCol = guards[i][1];
        for (int d = 0; d < 4; d++) {
            int r = guardRow + directions[d][0];
            int c = guardCol + directions[d][1];
            while (r >= 0 && r < m && c >= 0 && c < n) {
                if (grid[r][c] == 2 || grid[r][c] == 1) {
                    // Stop if a wall or another guard is encountered
                    break;
                }
                if (grid[r][c] == 0) {
                    grid[r][c] = -1; // Mark as guarded
                }
                r += directions[d][0];
                c += directions[d][1];
            }
        }
    }

    // Count unguarded and unoccupied cells
    int unguardedCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                unguardedCount++;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return unguardedCount;
}
