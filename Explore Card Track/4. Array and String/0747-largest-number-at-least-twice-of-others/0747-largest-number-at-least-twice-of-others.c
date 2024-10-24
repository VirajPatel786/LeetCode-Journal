/**
 * @brief Find the index of the largest number in an array where the largest number is at least twice as large
 *        as every other number. If no such number exists, return -1.
 *
 * @param nums (int*): Pointer to an array of integers.
 * @param numsSize (int): The size of the nums array.
 *
 * @return (int): The index of the largest number if it meets the condition, or -1 if no such number exists.
 */
int dominantIndex(int* nums, int numsSize) {
    // Edge case: Handle the case where the array has exactly two elements
    if (numsSize == 2) {
        if (nums[0] >= 2 * nums[1]) {
            return 0;  // First element is at least twice the second element
        } else if (nums[1] >= 2 * nums[0]) {
            return 1;  // Second element is at least twice the first element
        } else {
            return -1;  // Neither element is at least twice the other
        }
    }

    // Initialize variables for the largest and second largest numbers
    int largest_num = -1;           // Store the largest number in the array
    int second_largest_num = -1;    // Store the second largest number
    int largest_num_index = -1;     // Store the index of the largest number

    // Traverse the array to find the largest and second largest numbers
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > largest_num) {
            // If current number is greater than the largest, update the largest and second largest numbers
            second_largest_num = largest_num;  // The current largest becomes the second largest
            largest_num = nums[i];             // Update the largest number
            largest_num_index = i;             // Update the index of the largest number
        } else if (nums[i] > second_largest_num) {
            // If current number is smaller than the largest but larger than the second largest, update second largest
            second_largest_num = nums[i];
        }
    }

    // Check if the largest number is at least twice the second largest number
    if (largest_num >= 2 * second_largest_num) {
        return largest_num_index;  // Return the index of the largest number if the condition is satisfied
    }

    // Return -1 if no number satisfies the condition of being at least twice as large as all others
    return -1;
}
