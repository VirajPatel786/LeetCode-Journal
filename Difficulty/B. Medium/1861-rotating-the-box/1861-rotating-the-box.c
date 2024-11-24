#include <stdlib.h>
#include <string.h>

/**
 * @brief Rotates the box 90 degrees clockwise after simulating gravity.
 *
 * @param box (char**): The m x n matrix representing the box.
 * @param boxSize (int): Number of rows in the box.
 * @param boxColSize (int*): Array representing the number of columns in each row of the box.
 * @param returnSize (int*): Pointer to store the number of rows in the rotated box.
 * @param returnColumnSizes (int**): Pointer to store the number of columns in each row of the rotated box.
 * @return (char**): The rotated n x m matrix.
 */
char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes) {
    int m = boxSize;           // Number of rows in the original box
    int n = boxColSize[0];     // Number of columns in the original box

    // Simulate gravity for each row
    for (int i = 0; i < m; i++) {
        int empty_position = n - 1;  // Start from the rightmost position
        for (int j = n - 1; j >= 0; j--) {
            if (box[i][j] == '#') {  // Stone
                // Move stone to the lowest available position
                char temp = box[i][j];
                box[i][j] = box[i][empty_position];
                box[i][empty_position] = temp;
                empty_position--;
            } else if (box[i][j] == '*') {  // Obstacle
                // Reset the empty position
                empty_position = j - 1;
            }
        }
    }

    // Allocate memory for the rotated box
    *returnSize = n;  // Number of rows in the rotated box
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    char** rotatedBox = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        rotatedBox[i] = (char*)malloc(m * sizeof(char));
        (*returnColumnSizes)[i] = m;  // Each row of the rotated box has `m` columns
    }

    // Rotate the box 90 degrees clockwise
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rotatedBox[j][m - 1 - i] = box[i][j];
        }
    }

    return rotatedBox;
}
