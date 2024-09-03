#include <stdio.h>

// Function to calculate the sum of elements in an array
long sum(int arr[], int size) {
    long total = 0;  // Initialize the total sum to 0
    for (int i = 0; i < size; i++) {
        total += arr[i];  // Add each element to the total sum
    }
    return total;  // Return the accumulated sum
}

// Function to determine which student will run out of chalk
int chalkReplacer(int* chalk, int chalkSize, int k) {
    // Calculate the total amount of chalk used in one complete round
    long sumChalk = sum(chalk, chalkSize);

    // Find the remainder of chalk after completing full rounds within the total k
    long remainder = k % sumChalk;

    // Iterate over the chalk array to determine which student runs out of chalk first
    for (int i = 0; i < chalkSize; i++) {
        remainder -= chalk[i];  // Subtract the current student's chalk usage from the remainder

        // If remainder becomes negative, it means the current student will run out of chalk
        if (remainder < 0) {
            return i;  // Return the index of the student who needs more chalk
        }
    }

    // This line is just a safety return in case of an unexpected condition.
    // Normally, the function should return within the loop.
    return -1;  // If no student is found (shouldn't happen with valid inputs)
}