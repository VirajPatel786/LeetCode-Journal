void moveZeroes(int* nums, int numsSize) {
    int temp, i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
}