void dfs(int** grid, int gridSize, int gridColSize, int i, int j, bool** visited) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == 0 || visited[i][j])
        return;

    visited[i][j] = true;

    dfs(grid, gridSize, gridColSize, i + 1, j, visited);
    dfs(grid, gridSize, gridColSize, i - 1, j, visited);
    dfs(grid, gridSize, gridColSize, i, j + 1, visited);
    dfs(grid, gridSize, gridColSize, i, j - 1, visited);
}

bool isConnected(int** grid, int gridSize, int gridColSize) {
    bool** visited = (bool**)malloc(gridSize * sizeof(bool*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (bool*)calloc(gridColSize, sizeof(bool));
    }

    bool found_island = false;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                if (found_island) {
                    // More than one island found, no need to check further
                    for (int k = 0; k < gridSize; k++) {
                        free(visited[k]);
                    }
                    free(visited);
                    return false;
                }
                dfs(grid, gridSize, gridColSize, i, j, visited);
                found_island = true;
            }
        }
    }

    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return found_island;
}

int countLandCells(int** grid, int gridSize, int gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int minDays(int** grid, int gridSize, int* gridColSize) {
    if (!isConnected(grid, gridSize, *gridColSize)) {
        return 0;
    }

    if (countLandCells(grid, gridSize, *gridColSize) == 1) {
        return 1;
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (!isConnected(grid, gridSize, *gridColSize)) {
                    grid[i][j] = 1; // Restore the original state
                    return 1;
                }
                grid[i][j] = 1; // Restore the original state
            }
        }
    }

    return 2;
}
