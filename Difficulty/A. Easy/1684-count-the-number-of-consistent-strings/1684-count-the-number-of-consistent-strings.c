#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * Function to count the number of consistent strings in a given list.
 * A string is considered consistent if all its characters are present in the 'allowed' string.
 *
 * @param allowed (const char*): A string containing allowed characters (all lowercase letters).
 * @param words (char**): A list of words (array of strings) to be checked for consistency.
 * @param wordsSize (int): The number of words in the 'words' array.
 *
 * @return int: The count of consistent strings, i.e., words where all characters are in 'allowed'.
 */
int countConsistentStrings(const char* allowed, char** words, int wordsSize) {
    int allowedMask = 0;  // Initialize the bitmask to store allowed characters
    int count = 0;  // Initialize the counter for consistent strings

    // Create a bitmask for allowed characters
    // Each bit in 'allowedMask' will correspond to a letter in the alphabet.
    for (int i = 0; allowed[i] != '\0'; ++i) {
        // Set the bit corresponding to the character 'allowed[i]'
        // '1 << (allowed[i] - 'a')' shifts 1 left by the position of the character in the alphabet
        allowedMask |= (1 << (allowed[i] - 'a'));  // E.g., 'a' sets bit 0, 'b' sets bit 1, and so on.
    }

    // Iterate over each word in the 'words' array
    for (int i = 0; i < wordsSize; ++i) {
        bool isConsistent = true;  // Assume the word is consistent initially

        // Check every character in the current word
        for (int j = 0; words[i][j] != '\0'; ++j) {
            // Use the bitmask to check if the character is allowed
            // If the bit corresponding to 'words[i][j]' is not set in 'allowedMask', the word is inconsistent
            if (!(allowedMask & (1 << (words[i][j] - 'a')))) {
                isConsistent = false;
                break;  // No need to check further characters, break the loop
            }
        }

        // If the word is consistent, increment the count
        if (isConsistent) {
            count++;
        }
    }

    // Return the total count of consistent words
    return count;
}