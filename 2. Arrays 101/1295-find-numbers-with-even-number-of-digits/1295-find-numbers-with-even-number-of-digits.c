int findNumbers(int* nums, int numsSize) {
    int countEven = 0;
    for (int i = 0; i < numsSize; i++) {
        int countDigit = 0;
        int num = nums[i];
        while (num > 0) {
            num /= 10;
            countDigit++;
        }
        if (!(countDigit & 1)) {
            countEven++;
        }
    }
    return countEven;
}