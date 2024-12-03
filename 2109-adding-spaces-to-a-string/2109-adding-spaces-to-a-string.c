#include <stdlib.h>
#include <string.h>

/**
 * @brief Adds spaces to the string `s` at the specified indices in `spaces`.
 *
 * @param s (char*): The original string.
 * @param spaces (int*): The list of indices where spaces should be added.
 * @param spacesSize (int): The size of the `spaces` array.
 * @return (char*): The modified string with spaces added.
 */
char* addSpaces(char* s, int* spaces, int spacesSize) {
    int sLen = strlen(s);
    int newLen = sLen + spacesSize;  // New length of the string with spaces
    char* result = (char*)malloc((newLen + 1) * sizeof(char));  // Allocate memory for the new string

    int sIdx = 0, spaceIdx = 0, resIdx = 0;

    // Traverse the original string `s` and add spaces where needed
    while (sIdx < sLen) {
        // Check if the current index matches a space position
        if (spaceIdx < spacesSize && sIdx == spaces[spaceIdx]) {
            result[resIdx++] = ' ';  // Add a space
            spaceIdx++;  // Move to the next space index
        }
        result[resIdx++] = s[sIdx++];  // Add the current character
    }

    result[resIdx] = '\0';  // Null-terminate the result string
    return result;  // Return the modified string
}
