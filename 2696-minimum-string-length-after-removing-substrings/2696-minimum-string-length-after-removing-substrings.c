#include <stdio.h>
#include <string.h>

/**
 * @brief Removes the first occurrence of either "AB" or "CD" from the input string
 * and continues removing until neither is found.
 *
 * @param str (char*): The input string.
 *
 * @return int: The length of the string after all occurrences of "AB" and "CD" are removed.
 */
int minLength(char *str) {
    int length = strlen(str);  // Get the length of the input string
    int i, j;
    int found;

    do {
        found = 0;  // Reset the found flag before each iteration
        for (i = 0; i < length - 1; i++) {
            // Check if "AB" is found
            if (str[i] == 'A' && str[i + 1] == 'B') {
                // Shift characters left to remove "AB"
                for (j = i; j < length - 2; j++) {
                    str[j] = str[j + 2];
                }
                length -= 2;  // Reduce string length by 2
                str[length] = '\0';  // Null-terminate the string
                found = 1;  // Set found to indicate we made a change
                break;  // Restart the loop after the modification
            }
            // Check if "CD" is found
            if (str[i] == 'C' && str[i + 1] == 'D') {
                // Shift characters left to remove "CD"
                for (j = i; j < length - 2; j++) {
                    str[j] = str[j + 2];
                }
                length -= 2;  // Reduce string length by 2
                str[length] = '\0';  // Null-terminate the string
                found = 1;  // Set found to indicate we made a change
                break;  // Restart the loop after the modification
            }
        }
    } while (found);  // Continue looping while changes are made

    return length;  // Return the final length of the modified string
}
