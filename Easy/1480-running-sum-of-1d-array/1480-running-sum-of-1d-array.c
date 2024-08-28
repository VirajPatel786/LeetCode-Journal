

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    result[0] = nums[0];
    for(int i=1; i<numsSize; i++) {
        result[i] = result[i-1] + nums[i];
    }

    return result;
}