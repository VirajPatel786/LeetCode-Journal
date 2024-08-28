int minSwaps(int* nums, int numsSize) {
    int nTotalOnes = 0;
    for(int i = 0; i < numsSize; i++) {
        nTotalOnes += nums[i];
    }
    if ((nTotalOnes == 0) || (nTotalOnes == numsSize)) {
        return 0;
    }
    int nOnesSW = 0;
    for(int i = numsSize - nTotalOnes; i < numsSize; i++) {
        nOnesSW += nums[i];
    }
    int nMaxOnesSW = nOnesSW;
    for(int i = 0; i < numsSize; i++) {
        if (numsSize-nTotalOnes+i < numsSize) {
            nOnesSW += nums[i] - nums[numsSize-nTotalOnes+i];
        }
        else {
            nOnesSW += nums[i] - nums[i-nTotalOnes];
        }
        if (nOnesSW > nMaxOnesSW) {
            nMaxOnesSW = nOnesSW;
        }
    }
    return (nTotalOnes - nMaxOnesSW);
}