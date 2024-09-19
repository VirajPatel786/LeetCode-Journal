#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Precomputed powers of 10 to avoid repeated calls to pow()
static int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

/**
 * @brief Comparator function to sort numbers by their concatenated values.
 *
 * @param a const void*: Pointer to the first integer.
 * @param b const void*: Pointer to the second integer.
 * @return int: Returns a negative value if the first concatenation (b + a) is greater than the second (a + b),
 *              zero if they are equal, and a positive value if the second concatenation (a + b) is greater.
 */
static int compareNumbers(const void *a, const void *b) {
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;

    // Handle edge case where num1 or num2 is 0
    if (num1 == 0) return 1;  // Move zero to the end
    if (num2 == 0) return -1; // Move zero to the end

    // Calculate the number of digits in num1 and num2
    int num1Digits = 0, num2Digits = 0, temp;
    
    temp = num1;
    while (temp) {
        temp /= 10;
        num1Digits++;
    }
    
    temp = num2;
    while (temp) {
        temp /= 10;
        num2Digits++;
    }
    
    // Compare the two concatenated results: num1+num2 and num2+num1
    long long concatenatedNum1 = (long long)num1 * pow10[num2Digits] + num2;
    long long concatenatedNum2 = (long long)num2 * pow10[num1Digits] + num1;
    
    // Sort in descending order
    return (concatenatedNum2 > concatenatedNum1) ? 1 : -1;
}

/**
 * @brief Forms the largest number by arranging integers in the given array.
 *
 * @param nums int*: Array of integers to be arranged.
 * @param numsSize int: The number of integers in the array.
 * @return char*: A string representing the largest number formed by the integers.
 */
char* largestNumber(int* nums, int numsSize) {
    // Sort the numbers using the custom comparator
    qsort(nums, numsSize, sizeof(*nums), compareNumbers);
    
    // Calculate the total size required for the final string (including the null terminator)
    long totalLength = 1; // For null terminator '\0'
    for (int i = 0; i < numsSize; ++i) {
        int temp = nums[i];
        do {
            temp /= 10;
            ++totalLength;
        } while (temp);
    }

    // Allocate memory for the resulting string
    char *result = malloc(totalLength);
    int position = 0;
    
    // Concatenate the sorted numbers into the result string
    for (int i = 0; i < numsSize; ++i) {
        position += sprintf(result + position, "%d", nums[i]);
    }

    // Handle the edge case where the largest number is 0 (e.g., [0, 0, 0])
    if (result[0] == '0') {
        position = 1;  // Only keep one '0'
    }

    // Null-terminate the string
    result[position] = '\0';
    return result;
}