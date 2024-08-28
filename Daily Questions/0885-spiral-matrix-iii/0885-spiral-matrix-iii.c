/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int step = 1;
    int direction_index = 0;
    int totalCells = rows * cols;
    int** result = (int**)malloc(totalCells * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalCells * sizeof(int)); // Allocate memory for returnColumnSizes

    int row = 0;
    while (row < totalCells) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < step; j++) {
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result[row] = (int*)malloc(2 * sizeof(int));
                    result[row][0] = rStart;
                    result[row][1] = cStart;
                    (*returnColumnSizes)[row] = 2;
                    row++;
                }
                rStart += directions[direction_index][0];
                cStart += directions[direction_index][1];
            }
            direction_index = (direction_index + 1) % 4;
        }
        step++;
    }

    *returnSize = totalCells;
    return result;
}