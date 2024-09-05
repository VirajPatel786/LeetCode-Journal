#include <stdlib.h>

// Function to compute the sum of an integer array
int sum(int* arr, int arrSize) {
    int sum = 0;
    // Iterate through the array and accumulate the sum
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }
    return sum;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    // Calculate the sum of the missing rolls
    int missingSum = (mean * (rollsSize + n)) - sum(rolls, rollsSize);
    
    // Check if the missing sum is valid (each roll should be between 1 and 6)
    if ((missingSum < n) || (missingSum > (6 * n))) {
        *returnSize = 0;  // No valid rolls, return size should be 0
        return NULL;  // Return NULL as it's impossible to get valid rolls
    }
    
    // Calculate the base value for the missing rolls
    int baseValue = missingSum / n;
    
    // Calculate the remainder that needs to be distributed (extra rolls)
    int extraRolls = missingSum % n;
    
    // Allocate memory for the result array (n missing rolls)
    int* result = (int*)malloc(sizeof(int) * n);
    
    // Fill the result array with baseValue, adding 1 to the first 'extraRolls' elements
    for (int i = 0; i < n; i++) {
        if (i < extraRolls) {
            result[i] = baseValue + 1;  // Add 1 to distribute the remainder
        } else {
            result[i] = baseValue;  // Assign base value to the rest
        }
    }
    
    // Set the returnSize to the number of missing rolls
    *returnSize = n;
    
    // Return the result array
    return result;
}