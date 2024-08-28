int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int countPairs(int *nums, int numsSize, int maxDistance) {
    int count = 0;
    int start = 0;
    for (int i = 0; i < numsSize; i++) {
        while (start < numsSize && nums[i] - nums[start] > maxDistance) {
            start++;
        }
        count += i - start;
    }
    return count;
}

int smallestDistancePair(int* nums, int numsSize, int k) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    int low = 0;
    int high = nums[numsSize - 1] - nums[0];
    
    while (low < high) {
        int mid = (low + high) / 2;
        if (countPairs(nums, numsSize, mid) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}