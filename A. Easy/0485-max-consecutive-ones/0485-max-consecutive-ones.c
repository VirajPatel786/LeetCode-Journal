int max(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int countTemp = 0, countMax = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            countTemp++;
        }
        else {
            countMax = max(countTemp, countMax);
            countTemp = 0;
        }
    }
    return max(countTemp, countMax);
}