/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* numsSquares = (int*)malloc(numsSize * sizeof(int));
    if (numsSquares == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int left = 0, right = numsSize - 1;
    int i = numsSize - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            numsSquares[i] = leftSquare;
            left++;
        }
        else {
            numsSquares[i] = rightSquare;
            right--;
        }
        i--;
    }
    *returnSize = numsSize;
    return numsSquares;
}