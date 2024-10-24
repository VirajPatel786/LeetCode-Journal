#include <stdlib.h>

/**
 * @brief Increments the integer represented by an array of digits.
 *
 * @param digits (int*): Pointer to the array of digits.
 * @param digitsSize (int): The size of the digits array.
 * @param returnSize (int*): Pointer to the size of the returned array (output parameter).
 *
 * @return (int*): The new array of digits after incrementing by one.
 *                 The array is dynamically allocated and must be freed by the caller.
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Traverse the list from the last digit (rightmost side)
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            // If the current digit is less than 9, just increment it and return the result
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;  // Since no new space is needed, return the modified array directly
        }
        // If the digit is 9, it becomes 0 (carry over to the next significant digit)
        digits[i] = 0;
    }

    // If all digits were 9, we need an extra digit at the beginning (e.g., [9, 9, 9] -> [1, 0, 0, 0])
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;  // Set the first digit to 1 (carry from the previous digits)
    
    // The rest of the digits are all 0, which have already been set to 0 in the original array
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }

    *returnSize = digitsSize + 1;  // Update the return size to reflect the new length
    return result;  // Return the new array
}
