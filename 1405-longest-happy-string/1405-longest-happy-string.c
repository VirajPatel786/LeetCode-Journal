#include <stdio.h>

/**
 * @brief Generates the longest happy string using the given counts of 'a', 'b', and 'c'.
 *
 * @param a (int): Number of 'a' characters.
 * @param b (int): Number of 'b' characters.
 * @param c (int): Number of 'c' characters.
 *
 * @return (char*): The longest happy string.
 */

char* longestDiverseString(int a, int b, int c) {
    static char result[201];  // Maximum length is 100 a's + 100 b's + 100 c's = 300 + 1 for '\0'
    int index = 0;
    
    // Run the loop while there are characters left to be used
    while (a > 0 || b > 0 || c > 0) {
        // Check the current result to avoid 3 consecutive same characters
        if ((a >= b && a >= c) && !(index > 1 && result[index - 1] == 'a' && result[index - 2] == 'a')) {
            result[index++] = 'a';  // Add 'a' to the result
            a--;
        } else if ((b >= a && b >= c) && !(index > 1 && result[index - 1] == 'b' && result[index - 2] == 'b')) {
            result[index++] = 'b';  // Add 'b' to the result
            b--;
        } else if (c > 0 && !(index > 1 && result[index - 1] == 'c' && result[index - 2] == 'c')) {
            result[index++] = 'c';  // Add 'c' to the result
            c--;
        } else {
            // If we are here, it means we have two consecutive characters and need to switch
            // Check if other characters are available and append one of them.
            if (a > 0 && !(index > 1 && result[index - 1] == 'a')) {
                result[index++] = 'a';
                a--;
            } else if (b > 0 && !(index > 1 && result[index - 1] == 'b')) {
                result[index++] = 'b';
                b--;
            } else if (c > 0 && !(index > 1 && result[index - 1] == 'c')) {
                result[index++] = 'c';
                c--;
            } else {
                // If no valid characters are available, break out of the loop
                break;
            }
        }
    }
    
    result[index] = '\0';  // Null-terminate the string
    return result;
}
