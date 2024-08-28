int removeElement(int* nums, int numsSize, int val) {
    int notValIndex = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[notValIndex] = nums[i];
            notValIndex++;
        }
    }
    
    return notValIndex;
}
