#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Check if searchWord is a prefix of any word in a sentence.
 *
 * @param sentence (const char*): The input sentence.
 * @param searchWord (const char*): The word to check as a prefix.
 * 
 * @return int: 1-based index of the first matching word or -1 if none.
 */
int isPrefixOfWord(const char* sentence, const char* searchWord) {
    int index = 1;  // Start index from 1
    const char* word = strtok((char*)sentence, " ");  // Tokenize sentence by spaces

    while (word != NULL) {
        // Check if searchWord is a prefix of word
        if (strncmp(word, searchWord, strlen(searchWord)) == 0) {
            return index;  // Return current word index
        }
        word = strtok(NULL, " ");  // Get the next word
        index++;
    }
    return -1;  // Return -1 if no matching word is found
}
