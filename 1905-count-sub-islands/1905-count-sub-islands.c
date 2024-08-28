#include <stdbool.h>

void dfs(int** grid1, int** grid2, int numRows, int numCols, int row, int col, bool* isSubIsland) {
    // Mark the current cell in grid2 as visited by setting it to 0
    grid2[row][col] = 0;

    // If the corresponding cell in grid1 is water, mark this island as not a sub-island
    if (grid1[row][col] == 0) {
        *isSubIsland = false;
    }

    // Explore the 4 neighboring directions (up, down, left, right)
    if (row > 0 && grid2[row - 1][col] == 1) { // Up
        dfs(grid1, grid2, numRows, numCols, row - 1, col, isSubIsland);
    }
    if (row < numRows - 1 && grid2[row + 1][col] == 1) { // Down
        dfs(grid1, grid2, numRows, numCols, row + 1, col, isSubIsland);
    }
    if (col > 0 && grid2[row][col - 1] == 1) { // Left
        dfs(grid1, grid2, numRows, numCols, row, col - 1, isSubIsland);
    }
    if (col < numCols - 1 && grid2[row][col + 1] == 1) { // Right
        dfs(grid1, grid2, numRows, numCols, row, col + 1, isSubIsland);
    }
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    int subIslandCount = 0;
    int numRows = grid2Size;
    int numCols = grid2ColSize[0];

    // Traverse through each cell in grid2
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            // If a land cell is found in grid2, initiate DFS to check if it's a sub-island
            if (grid2[row][col] == 1) {
                bool isSubIsland = true;
                dfs(grid1, grid2, numRows, numCols, row, col, &isSubIsland);

                // If the entire island is confirmed as a sub-island, increment the count
                if (isSubIsland) {
                    subIslandCount++;
                }
            }
        }
    }

    return subIslandCount;
}
