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
    // Handle the edge case of an empty string
    if (word == NULL || word[0] == '\0') {
        char* empty_result = (char*)malloc(1);
        empty_result[0] = '\0';
        return empty_result;
    }

    // Allocate memory for the compressed result: 2 * length of word + 1 for null terminator
    int max_length = 2 * strlen(word) + 1;
    char* compressed = (char*)malloc(max_length * sizeof(char));
    if (compressed == NULL) {
        return NULL; // Memory allocation failed
    }

    int count = 0; // Initialize count to 0
    int index = 0; // Index to keep track of position in compressed result
    char current_char = word[0]; // Start with the first character

    // Iterate through the input word
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == current_char && count < 9) {
            // Increment count if the same character appears and count is less than 9
            count++;
        } else {
            // Write count and character to the buffer
            index += sprintf(&compressed[index], "%d%c", count, current_char);
            
            // Update current character and reset count to 1
            current_char = word[i];
            count = 1;
        }
    }

    // Append the last sequence of count and character
    sprintf(&compressed[index], "%d%c", count, current_char);

    return compressed;
}
