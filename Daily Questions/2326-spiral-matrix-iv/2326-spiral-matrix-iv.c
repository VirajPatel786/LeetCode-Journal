/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    // Initialize the matrix with -1 values
    int** result = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        result[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            result[i][j] = -1;  // Default fill with -1
        }
    }

    // Set return sizes for the result matrix
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        (*returnColumnSizes)[i] = n;
    }

    // Boundaries for the spiral traversal
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    struct ListNode* current = head;

    // Continue filling the matrix while there are elements in the list and space in the matrix
    while ((current != NULL) && (top <= bottom) && (left <= right)) {
        // Fill the top row (left to right)
        for (int j = left; ((j <= right) && (current != NULL)); ++j) {
            result[top][j] = current->val;
            current = current->next;
        }
        top++;  // Move the top boundary down

        // Fill the right column (top to bottom)
        for (int i = top; ((i <= bottom) && (current != NULL)); ++i) {
            result[i][right] = current->val;
            current = current->next;
        }
        right--;  // Move the right boundary left

        // Fill the bottom row (right to left)
        if (top <= bottom) {
            for (int j = right; ((j >= left) && (current != NULL)); --j) {
                result[bottom][j] = current->val;
                current = current->next;
            }
            bottom--;  // Move the bottom boundary up
        }

        // Fill the left column (bottom to top)
        if (left <= right) {
            for (int i = bottom; ((i >= top) && (current != NULL)); --i) {
                result[i][left] = current->val;
                current = current->next;
            }
            left++;  // Move the left boundary right
        }
    }

    return result;
}