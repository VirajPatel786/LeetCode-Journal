#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a sentence is circular.
 *
 * A sentence is considered circular if the last character of each word
 * matches the first character of the next word, and the last character
 * of the last word matches the first character of the first word.
 *
 * @param sentence (char*): The sentence to be checked.
 *
 * @return bool: true if the sentence is circular, false otherwise.
 */
bool isCircularSentence(char* sentence) {
    // Tokenize the sentence into words
    char* first_word = strtok(sentence, " ");
    char* current_word = first_word;
    char* next_word = NULL;
    char last_char = current_word[strlen(current_word) - 1];
    char first_char = current_word[0];

    while ((next_word = strtok(NULL, " ")) != NULL) {
        // Check if the last character of the current word matches
        // the first character of the next word
        if (last_char != next_word[0]) {
            return false;
        }
        
        // Update last_char to the last character of the next word
        last_char = next_word[strlen(next_word) - 1];
        current_word = next_word;
    }
    
    // Check the circular condition: last character of the last word with first character of the first word
    return last_char == first_char;
}
