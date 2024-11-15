#include <stdio.h>

/**
 * @brief Removes all occurrences of a specified value from an array in-place.
 *
 * @param nums (int*): Pointer to the array of integers.
 * @param numsSize (int): The size of the array.
 * @param val (int): The value to remove from the array.
 *
 * @return (int): The new length of the array after removing the specified value.
 */
int removeElement(int* nums, int numsSize, int val) {
    int notValIndex = 0;  // Index to place elements not equal to `val`

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        // If the current element is not equal to `val`, move it to `notValIndex`
        if (nums[i] != val) {
            nums[notValIndex] = nums[i];  // Overwrite the position at `notValIndex`
            notValIndex++;               // Increment the index for the next non-val element
        }
    }

    // Return the new size of the array (number of elements not equal to `val`)
    return notValIndex;
}
