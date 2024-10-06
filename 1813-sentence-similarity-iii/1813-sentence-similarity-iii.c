#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Check if two sentences are similar by inserting a sentence into one.
 *
 * @param sentence1 (char*): First input sentence.
 * @param sentence2 (char*): Second input sentence.
 *
 * @return (bool): Returns true if the sentences are similar, false otherwise.
 */
bool areSentencesSimilar(char* sentence1, char* sentence2) {
    // Get the lengths of the input sentences
    int len1 = strlen(sentence1);
    int len2 = strlen(sentence2);

    // Allocate dynamic memory to make copies of the input sentences
    char *s1_copy = (char *)malloc((len1 + 1) * sizeof(char));
    char *s2_copy = (char *)malloc((len2 + 1) * sizeof(char));
    
    // Copy the input sentences into the allocated memory
    strcpy(s1_copy, sentence1);
    strcpy(s2_copy, sentence2);

    // Tokenize the sentences into words using space as a delimiter
    int max_words1 = 0, max_words2 = 0;

    // Count the number of words in sentence1
    for (int i = 0; i < len1; i++) {
        if (s1_copy[i] == ' ') {
            max_words1++;
        }
    }
    max_words1++; // For the last word or if no spaces are present

    // Count the number of words in sentence2
    for (int i = 0; i < len2; i++) {
        if (s2_copy[i] == ' ') {
            max_words2++;
        }
    }
    max_words2++; // For the last word or if no spaces are present

    // Dynamically allocate arrays to hold the words
    char **words1 = (char **)malloc(max_words1 * sizeof(char *));
    char **words2 = (char **)malloc(max_words2 * sizeof(char *));
    
    // Tokenize sentence1
    char *token1 = strtok(s1_copy, " ");
    int len1_words = 0;
    while (token1 != NULL) {
        words1[len1_words++] = token1;
        token1 = strtok(NULL, " ");
    }
    
    // Tokenize sentence2
    char *token2 = strtok(s2_copy, " ");
    int len2_words = 0;
    while (token2 != NULL) {
        words2[len2_words++] = token2;
        token2 = strtok(NULL, " ");
    }

    // Check prefix matches: Compare words from the start of both lists
    int i = 0, j = 0;
    while (i < len1_words && i < len2_words && strcmp(words1[i], words2[i]) == 0) {
        i++;
    }
    
    // Check suffix matches: Compare words from the end of both lists
    while (j < len1_words - i && j < len2_words - i && strcmp(words1[len1_words - 1 - j], words2[len2_words - 1 - j]) == 0) {
        j++;
    }

    // Free allocated memory
    free(s1_copy);
    free(s2_copy);
    free(words1);
    free(words2);
    
    // The sentences are similar if the matched prefix + suffix covers at least the smaller sentence
    return i + j >= len1_words || i + j >= len2_words;
}
