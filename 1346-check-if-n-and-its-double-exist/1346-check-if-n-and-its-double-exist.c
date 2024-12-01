#include <stdbool.h>

/**
 * @brief Check if there exist indices i and j such that arr[i] == 2 * arr[j].
 *
 * @param arr (int*): The input array.
 * @param arrSize (int): Size of the array.
 * 
 * @return bool: True if such a pair exists, otherwise False.
 */
bool checkIfExist(int* arr, int arrSize) {
    // Create a hash table to store occurrences of numbers
    // Using an offset of 1000 to handle negative indices (range is -1000 to 1000)
    int hashTable[2001] = {0};

    // Loop through each element in the array
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];  // Current number

        // Check if the double of the current number exists in the hash table
        if ((num >= -500 && num <= 500) && (hashTable[num * 2 + 1000] > 0)) {
            return true;  // Return true if double exists
        }

        // Check if half of the current number exists in the hash table
        // (Only valid if the number is even)
        if (num % 2 == 0 && hashTable[num / 2 + 1000] > 0) {
            return true;  // Return true if half exists
        }

        // Add the current number to the hash table
        hashTable[num + 1000]++;
    }

    // Return false if no such pair is found
    return false;
}
