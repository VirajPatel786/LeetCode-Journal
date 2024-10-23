#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Simulates the sequence of strings that appear on the screen when typing the target string.
 *
 * @param target (char*): The target string Alice is typing.
 * @param returnSize (int*): Pointer to store the number of strings in the result.
 *
 * @return (char**): Array of strings showing the sequence that appears on the screen.
 *                   The returned array must be malloced, assume the caller calls free().
 */
char** stringSequence(char* target, int* returnSize) {
    int targetLength = strlen(target);  // Length of the target string

    // Estimate a larger size, but you can also dynamically resize this if needed.
    int maxResultSize = targetLength * 26;  // Max number of keypresses (26 letters)
    char** result = (char**)malloc(maxResultSize * sizeof(char*));
    if (result == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    char* str_on_screen = (char*)malloc((targetLength + 1) * sizeof(char));
    if (str_on_screen == NULL) {
        free(result);  // Clean up result array if memory allocation fails
        return NULL;
    }
    str_on_screen[0] = '\0';  // Start with an empty string
    
    int count = 0;  // Keep track of how many strings are generated

    // Iterate through each character in the target
    for (int i = 0; i < targetLength; ++i) {
        // Step 1: Append 'a' (Key 1 action)
        str_on_screen[i] = 'a';
        str_on_screen[i + 1] = '\0';
        result[count] = (char*)malloc((i + 2) * sizeof(char));  // Allocate memory for the current string
        if (result[count] == NULL) {
            // If memory allocation fails, free everything allocated so far
            for (int j = 0; j < count; j++) {
                free(result[j]);
            }
            free(result);
            free(str_on_screen);
            return NULL;
        }
        strcpy(result[count], str_on_screen);  // Copy the string into the result array
        count++;
        
        // Step 2: Increment the last character (Key 2 actions) until it matches target[i]
        while (str_on_screen[i] != target[i]) {
            str_on_screen[i] = str_on_screen[i] + 1;  // Increment character
            result[count] = (char*)malloc((i + 2) * sizeof(char));  // Allocate memory for the current string
            if (result[count] == NULL) {
                // If memory allocation fails, free everything allocated so far
                for (int j = 0; j < count; j++) {
                    free(result[j]);
                }
                free(result);
                free(str_on_screen);
                return NULL;
            }
            strcpy(result[count], str_on_screen);  // Copy the string into the result array
            count++;
        }
    }
    
    // Set the returnSize to the number of strings generated
    *returnSize = count;

    // Free the temporary string used to simulate the screen
    free(str_on_screen);
    
    // Return the array of strings
    return result;
}
