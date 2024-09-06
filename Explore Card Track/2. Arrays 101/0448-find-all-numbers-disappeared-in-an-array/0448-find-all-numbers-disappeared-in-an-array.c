/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    // First pass: Mark the indices corresponding to the numbers
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;  // Convert to zero-based index
        if (nums[index] > 0) {
            nums[index] = -nums[index];  // Mark as visited by making it negative
            count++;
        }
    }

    // Second pass: Collect the missing numbers
    int* result = (int*)malloc((numsSize - count) * sizeof(int));
    count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {  // If the value is positive, the number (i + 1) is missing
            result[count++] = i + 1;
        }
    }

    // Set the return size
    *returnSize = count;

    return result;
}