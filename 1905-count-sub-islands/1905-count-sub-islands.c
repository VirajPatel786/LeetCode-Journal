#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Perform DFS to explore an island in grid2 and check if it is a sub-island of grid1
bool exploreIsland(int** grid1, int** grid2, int row, int col, int numRows, int numCols) {
    // Base case: check if coordinates are out of bounds or if the cell is water in grid2
    if (row < 0 || col < 0 || row >= numRows || col >= numCols || grid2[row][col] == 0) {
        return true;
    }

    // Check if the corresponding cell in grid1 is water while it's land in grid2
    if (grid1[row][col] == 0) {
        return false;
    }

    // Mark the cell in grid2 as visited by setting it to 0
    grid2[row][col] = 0;

    // Recursively explore all 4 neighboring directions (up, down, left, right)
    bool up = exploreIsland(grid1, grid2, row - 1, col, numRows, numCols);
    bool down = exploreIsland(grid1, grid2, row + 1, col, numRows, numCols);
    bool left = exploreIsland(grid1, grid2, row, col - 1, numRows, numCols);
    bool right = exploreIsland(grid1, grid2, row, col + 1, numRows, numCols);

    // Return true only if all parts of this island are valid sub-island parts
    return up && down && left && right;
}

// Main function to count the number of sub-islands in grid2 that are also in grid1
int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    int subIslandCount = 0;

    // Iterate through each cell in grid2
    for (int row = 0; row < grid2Size; row++) {
        for (int col = 0; col < grid2ColSize[row]; col++) {
            // If a land cell is found in grid2, initiate DFS to check if it's a sub-island
            if (grid2[row][col] == 1) {
                if (exploreIsland(grid1, grid2, row, col, grid2Size, grid2ColSize[row])) {
                    subIslandCount++;  // Increment the count if the island in grid2 is a valid sub-island
                }
            }
        }
    }

    return subIslandCount;
}
