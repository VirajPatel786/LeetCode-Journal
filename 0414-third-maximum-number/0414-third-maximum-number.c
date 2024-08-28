int thirdMax(int* nums, int numsSize) {
    long Max1 = LONG_MIN;
    long Max2 = LONG_MIN;
    long Max3 = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] == Max1) || (nums[i] == Max2) || (nums[i] == Max3)) {
            continue;
        }

        if (nums[i] > Max1) {
            Max3 = Max2;
            Max2 = Max1;
            Max1 = nums[i];
        }
        else if (nums[i] > Max2) {
            Max3 = Max2;
            Max2 = nums[i];
        }
        else if (nums[i] > Max3) {
            Max3 = nums[i];
        }
    }
    
    if (Max3 == LONG_MIN) {
        return (int)Max1;
    }
    return (int)Max3;
}