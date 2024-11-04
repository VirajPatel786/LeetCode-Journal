#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a fancy string from the input by ensuring no character appears more than twice consecutively.
 *
 * @param s (char*): The input string consisting of lowercase English letters.
 *
 * @return (char*): A dynamically allocated fancy string with no character appearing more than twice consecutively.
 */
char* makeFancyString(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char)); // Allocate space for the resulting string
    int count = 1; // To count consecutive identical characters
    int j = 0;     // Index for filling the result string

    // Ensure input is valid
    if (s == NULL) return NULL;

    // Add the first character to result
    result[j++] = s[0];

    // Process each character starting from the second character
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            count++; // Increment count for consecutive identical characters
        } else {
            count = 1; // Reset count if character is different
        }

        // Append character if it appears less than 3 times consecutively
        if (count < 3) {
            result[j++] = s[i];
        }
    }

    result[j] = '\0'; // Null-terminate the result string
    return result;
}
