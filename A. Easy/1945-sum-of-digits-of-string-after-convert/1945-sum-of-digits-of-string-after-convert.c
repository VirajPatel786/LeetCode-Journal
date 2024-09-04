#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to sum digits of a number represented as a string
int sumOfDigits(char *numericStr) {
    int sum = 0;
    for (int i = 0; numericStr[i] != '\0'; i++) {
        sum += numericStr[i] - '0';  // Convert each character to its integer value
    }
    return sum;
}

// Function to convert a string 's' to its "lucky number" after k transformations
int getLucky(char *s, int k) {
    char numericS[201] = "";  // Buffer to store the numeric string (maximum length 200 digits + 1 for null terminator)

    // Step 1: Convert each character in 's' to its corresponding numeric value ('a' -> 1, 'b' -> 2, ..., 'z' -> 26)
    for (int i = 0; s[i] != '\0'; i++) {
        int numericValue = s[i] - 'a' + 1;  // Get numeric value of each character
        char buffer[3];  // Buffer to store the string version of numeric value (up to 2 digits for '26')
        sprintf(buffer, "%d", numericValue);  // Convert the numeric value to a string
        strcat(numericS, buffer);  // Append the numeric string to the result
    }

    // Step 2: Perform k transformations
    int result = 0;
    for (int i = 0; i < k; i++) {
        result = sumOfDigits(numericS);  // Sum the digits of the current numeric string
        sprintf(numericS, "%d", result);  // Convert the sum back to a string for the next iteration
    }

    // Step 3: Return the final result after k transformations
    return result;
}
