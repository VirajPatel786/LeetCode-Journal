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
    // Step 1: Allocate memory for the result array (same size as the input initially)
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    int carry = 1;  // We need to add 1 to the number
    
    // Step 2: Traverse the array from the last digit to the first
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;  // Add the carry to the current digit
        result[i + 1] = sum % 10;     // Store the last digit of the sum
        carry = sum / 10;             // Calculate the carry (1 if sum is 10, otherwise 0)
    }
    
    // Step 3: If there is a carry left after the loop, we need to resize the array
    if (carry == 1) {
        // The most significant digit also needs to carry, so the array grows by one
        result[0] = 1;
        *returnSize = digitsSize + 1;
        return result;
    } else {
        // No carry, just return the result starting from index 1 (skip the extra space at the front)
        *returnSize = digitsSize;
        return result + 1;  // Adjust the pointer to skip the extra space at the front
    }
}
