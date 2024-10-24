#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Determines if each kid can have the greatest number of candies
 *        after receiving the extra candies.
 *
 * @param candies (int*): Array representing number of candies each kid has.
 * @param candiesSize (int): Size of the candies array.
 * @param extraCandies (int): Number of extra candies available.
 * @param returnSize (int*): Pointer to return the size of the result array.
 *
 * @return (bool*): Boolean array where each element is true if the corresponding kid 
 *                  can have the greatest number of candies, otherwise false.
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int maxCandies = 0;
    
    // Find the maximum number of candies
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }

    // Allocate memory for the result array
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;

    // Determine if each kid can have the greatest number of candies
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= maxCandies) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }

    return result;
}

