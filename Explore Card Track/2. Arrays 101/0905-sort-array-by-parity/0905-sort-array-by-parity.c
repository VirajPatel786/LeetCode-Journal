/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int temp, i = 0;
    for (int j = 0; j < numsSize; j++) {
        if ((nums[j] % 2) == 0) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    return nums;
}