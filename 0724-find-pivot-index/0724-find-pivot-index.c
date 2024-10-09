/**
 * @brief Finds the pivot index in the array where the sum of elements to the left
 * is equal to the sum of elements to the right.
 *
 * @param nums (int*): Pointer to the array of integers.
 * @param numsSize (int): The size of the array.
 *
 * @return (int): The pivot index, or -1 if no such index exists.
 */
int pivotIndex(int* nums, int numsSize) {
    // Variable to store the total sum of the array
    int total_sum = 0;

    // Calculate the total sum of the elements in the array
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }

    // Variable to store the sum of the left side of the array
    int left_sum = 0;

    // Iterate through the array to find the pivot index
    for (int i = 0; i < numsSize; i++) {
        // If the sum of the left side is equal to the sum of the right side
        // Right sum is total_sum - left_sum - nums[i]
        if (left_sum == total_sum - left_sum - nums[i]) {
            return i;  // Return the pivot index
        }
        // Update the left sum to include the current element
        left_sum += nums[i];
    }

    // If no pivot index is found, return -1
    return -1;
}
