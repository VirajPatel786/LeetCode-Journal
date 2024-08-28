bool checkGridMagic(int grid[3][3]) {
    // Check if all numbers from 1 to 9 are present
    bool seen[10] = {false}; // Index 0 is unused
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }

    // Check if all row, column, and diagonal sums are the same
    int sum = grid[0][0] + grid[0][1] + grid[0][2]; // Reference sum

    // Check rows
    for (int i = 1; i < 3; i++) {
        int rowSum = grid[i][0] + grid[i][1] + grid[i][2];
        if (rowSum != sum) return false;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        int colSum = grid[0][j] + grid[1][j] + grid[2][j];
        if (colSum != sum) return false;
    }

    // Check diagonals
    int diag1Sum = grid[0][0] + grid[1][1] + grid[2][2];
    int diag2Sum = grid[0][2] + grid[1][1] + grid[2][0];
    if (diag1Sum != sum || diag2Sum != sum) return false;

    return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    int gridCount = 0;

    // Iterate over all possible 3x3 sub-grids
    for (int i = 0; i <= gridSize - 3; i++) {
        for (int j = 0; j <= gridColSize[i] - 3; j++) {
            int subGrid[3][3];
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    subGrid[x][y] = grid[i + x][j + y];
                }
            }
            if (checkGridMagic(subGrid)) {
                gridCount += 1;
            }
        }
    }

    return gridCount;
}