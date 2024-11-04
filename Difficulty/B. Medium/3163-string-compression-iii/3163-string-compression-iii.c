#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Compresses a string by counting consecutive characters.
 *
 * This function compresses a string by replacing consecutive repeating characters
 * with the character and the count of repeats (up to a maximum of 9).
 *
 * @param word (char*): The input string to compress.
 *
 * @return char*: A new compressed string. Caller is responsible for freeing the memory.
 */
char* compressedString(char* word) {
    // Handle edge case of an empty string
    if (word == NULL || word[0] == '\0') {
        char* empty_result = (char*)malloc(1);
        empty_result[0] = '\0';
        return empty_result;
    }

    // Pre-allocate memory for the compressed result
    int max_length = 2 * strlen(word) + 1;
    char* compressed = (char*)malloc(max_length * sizeof(char));
    if (compressed == NULL) {
        return NULL; // Memory allocation failed
    }

    int count = 1;  // Start count at 1
    int index = 0;  // Position in compressed output
    char current_char = word[0]; // Start with the first character

    // Loop through each character in the word starting from the second character
    for (int i = 1; word[i] != '\0'; i++) {
        if (word[i] == current_char && count < 9) {
            // Increment count if the current character is the same and count < 9
            count++;
        } else {
            // Append count and character to the compressed buffer directly
            compressed[index++] = '0' + count; // Convert count to ASCII
            compressed[index++] = current_char;

            // Reset count and update current_char
            current_char = word[i];
            count = 1;
        }
    }

    // Append the last count and character
    compressed[index++] = '0' + count;
    compressed[index++] = current_char;

    // Null-terminate the compressed string
    compressed[index] = '\0';

    return compressed;
}
