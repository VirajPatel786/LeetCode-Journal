void insert(int* arr, int arrSize, int index, int val) {
    // Start from the last element and move each element one position to the right
    for (int i = arrSize - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new value at the specified index
    arr[index] = val;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0;
    while (j < n) {
        if ((i >= m+j) || (nums2[j] <= nums1[i])) {
            insert(nums1, nums1Size, i, nums2[j]);
            j++;
        }
        i++;
    }
}