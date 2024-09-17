#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Comparator function for qsort to sort strings.
 * 
 * @param a const void* - First string to compare.
 * @param b const void* - Second string to compare.
 * @return int - Result of string comparison.
 */
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Finds words that appear exactly once across both sentences.
 * 
 * @param s1 char* - The first sentence.
 * @param s2 char* - The second sentence.
 * @param returnSize int* - Pointer to store the size of the returned array.
 * @return char** - Array of uncommon words, dynamically allocated.
 */
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    // Split both sentences into words (with enough space)
    char *words[200];
    int word_count = 0;

    // Tokenize first sentence
    char *token = strtok(s1, " ");
    while (token) {
        words[word_count++] = strdup(token);  // Duplicate word into words array
        token = strtok(NULL, " ");
    }

    // Tokenize second sentence
    token = strtok(s2, " ");
    while (token) {
        words[word_count++] = strdup(token);  // Duplicate word into words array
        token = strtok(NULL, " ");
    }

    // Sort all the words
    qsort(words, word_count, sizeof(char *), compare);

    // Temporary array to store uncommon words (max size will be word_count)
    char **result = malloc(word_count * sizeof(char *));
    int result_index = 0;

    // Find uncommon words (that appear exactly once)
    for (int i = 0; i < word_count; ) {
        int j = i + 1;
        // Check how many times the current word appears
        while (j < word_count && strcmp(words[i], words[j]) == 0) {
            j++;
        }
        if (j == i + 1) {  // If the word appears exactly once
            result[result_index++] = strdup(words[i]);
        }
        i = j;  // Move to the next word
    }

    // Free memory used by words array
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }

    // Set the return size
    *returnSize = result_index;
    
    // Resize result array to fit exactly the number of uncommon words
    result = realloc(result, result_index * sizeof(char *));
    
    return result;
}