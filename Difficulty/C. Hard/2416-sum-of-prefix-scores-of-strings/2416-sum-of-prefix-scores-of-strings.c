#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

/**
 * @brief TrieNode structure representing a node in the Trie.
 * Each TrieNode contains:
 * - children: An array of TrieNode pointers representing the 26 lowercase English letters.
 * - count: The number of words that pass through this node.
 */
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];  // Array for child nodes
    int count;  // Number of words passing through this node
} TrieNode;

/**
 * @brief Initializes a new TrieNode.
 *
 * @return TrieNode*: Pointer to the newly created TrieNode.
 */
TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->count = 0;  // Initialize count to 0
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;  // Initialize all child nodes to NULL
    }
    return node;
}

/**
 * @brief Inserts a word into the Trie and increments the count of each prefix.
 *
 * @param root TrieNode*: The root of the Trie.
 * @param word char*: The word to be inserted.
 */
void insert(TrieNode *root, const char *word) {
    TrieNode *node = root;
    while (*word) {
        int index = *word - 'a';  // Map 'a' to 0, 'b' to 1, ..., 'z' to 25
        if (node->children[index] == NULL) {
            node->children[index] = createNode();  // Create a new TrieNode if it doesn't exist
        }
        node = node->children[index];
        node->count += 1;  // Increment the count at this node
        word++;
    }
}

/**
 * @brief Calculates the sum of prefix scores for a given word.
 *
 * @param root TrieNode*: The root of the Trie.
 * @param word char*: The word for which to calculate the prefix score.
 * @return int: The sum of prefix scores for the word.
 */
int calculatePrefixScore(TrieNode *root, const char *word) {
    TrieNode *node = root;
    int total_score = 0;  // Initialize total score to 0
    while (*word) {
        int index = *word - 'a';  // Map 'a' to 0, ..., 'z' to 25
        node = node->children[index];
        total_score += node->count;  // Add the count at this node to the total score
        word++;
    }
    return total_score;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Calculates the sum of prefix scores for each word in the list.
 * 
 * @param words char**: List of words.
 * @param wordsSize int: The number of words in the list.
 * @param returnSize int*: Pointer to store the size of the result array.
 * 
 * @return int*: The array of sums of prefix scores for each word.
 *         The returned array is dynamically allocated and must be freed by the caller.
 */
int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    // Create a new Trie and initialize the root node
    TrieNode *root = createNode();
    
    // Insert each word into the Trie
    for (int i = 0; i < wordsSize; i++) {
        insert(root, words[i]);  // Insert each word into the Trie
    }
    
    // Allocate memory for the result array
    int *result = (int*)malloc(wordsSize * sizeof(int));
    
    // Calculate the prefix score for each word and store in the result array
    for (int i = 0; i < wordsSize; i++) {
        result[i] = calculatePrefixScore(root, words[i]);
    }
    
    // Set the return size to the number of words
    *returnSize = wordsSize;
    
    // Return the result array
    return result;
}