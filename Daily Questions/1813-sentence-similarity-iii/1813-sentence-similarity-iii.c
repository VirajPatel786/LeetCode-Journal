#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Check if two sentences are similar by inserting a sentence into one.
 *
 * @param sentence1 (char*): First input sentence.
 * @param sentence2 (char*): Second input sentence.
 *
 * @return (bool): Returns true if the sentences are similar, false otherwise.
 */
bool areSentencesSimilar(char* sentence1, char* sentence2) {
    // Split the sentences into words using space as a delimiter
    // Create pointers to keep track of the tokens
    char *token1, *token2;
    
    // Create a copy of sentence1 and sentence2 to tokenize
    char s1_copy[101], s2_copy[101];
    strcpy(s1_copy, sentence1);
    strcpy(s2_copy, sentence2);
    
    // Tokenize both sentences using spaces
    char *words1[101], *words2[101]; // Arrays to store the words of the sentences
    int len1 = 0, len2 = 0;
    
    // Tokenize sentence1
    token1 = strtok(s1_copy, " ");
    while (token1 != NULL) {
        words1[len1++] = token1;
        token1 = strtok(NULL, " ");
    }
    
    // Tokenize sentence2
    token2 = strtok(s2_copy, " ");
    while (token2 != NULL) {
        words2[len2++] = token2;
        token2 = strtok(NULL, " ");
    }
    
    // Initialize two pointers for prefix and suffix matching
    int i = 0, j = 0;
    
    // Check prefix matches: Compare words from the start of both lists
    // Increment i as long as the words at index i are the same in both lists
    while (i < len1 && i < len2 && strcmp(words1[i], words2[i]) == 0) {
        i++;
    }
    
    // Check suffix matches: Compare words from the end of both lists
    // Increment j as long as the words at index -1-j are the same in both lists
    while (j < len1 - i && j < len2 - i && strcmp(words1[len1 - 1 - j], words2[len2 - 1 - j]) == 0) {
        j++;
    }
    
    // The sentences are similar if the matched prefix + suffix covers at least the smaller sentence
    return i + j >= len1 || i + j >= len2;
}
