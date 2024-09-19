#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Comparator function to decide the order based on the concatenation of two strings.
 *
 * @param a const void*: Pointer to the first string.
 * @param b const void*: Pointer to the second string.
 * @return int: Returns a negative value if (b + a) is lexicographically greater than (a + b),
 *              zero if they are equal, and a positive value otherwise.
 */
int compare(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;
    
    // Create two possible concatenations
    char order1[22], order2[22];  // Max possible length for a number is 10 digits + 1, so 2*10 + 2 for null terminator
    sprintf(order1, "%s%s", str1, str2);
    sprintf(order2, "%s%s", str2, str1);
    
    // Return comparison result: negative if order1 < order2, positive if order1 > order2
    return strcmp(order2, order1); // We reverse because we want descending order
}

/**
 * @brief Forms the largest number by arranging integers in the given list.
 *
 * @param nums int*: Array of integers to be arranged.
 * @param numsSize int: Number of elements in the nums array.
 * @return char*: Returns a string representing the largest number that can be formed by the integers.
 */
char* largestNumber(int* nums, int numsSize) {
    // Allocate space for string versions of each number
    char **strNums = (char **)malloc(numsSize * sizeof(char *));
    
    // Convert all numbers to strings
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = (char *)malloc(12 * sizeof(char)); // Allocate space for up to 10 digits + null terminator
        sprintf(strNums[i], "%d", nums[i]);
    }
    
    // Sort the numbers using the custom comparator
    qsort(strNums, numsSize, sizeof(char *), compare);
    
    // If the largest number is "0", return "0" (handle the case where all numbers are zero)
    if (strcmp(strNums[0], "0") == 0) {
        return "0";
    }
    
    // Calculate the total length of the resulting string
    int totalLength = 0;
    for (int i = 0; i < numsSize; i++) {
        totalLength += strlen(strNums[i]);
    }
    
    // Allocate space for the result
    char *result = (char *)malloc((totalLength + 1) * sizeof(char)); // +1 for null terminator
    result[0] = '\0'; // Initialize the result string as an empty string
    
    // Concatenate all strings into the result
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]);
        free(strNums[i]); // Free each string after use
    }
    
    // Free the string array itself
    free(strNums);
    
    return result; // Return the final result
}