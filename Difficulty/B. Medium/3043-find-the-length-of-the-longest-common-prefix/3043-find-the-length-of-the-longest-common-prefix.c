#include <stdio.h>
#include <stdlib.h>

// Define the structure for the hash table entries
typedef struct HashNode {
    int key;                 // The prefix (key)
    struct HashNode* next;   // Pointer to the next node (for collision handling)
} HashNode;

// Define the hash table structure
#define TABLE_SIZE 100000  // Define a reasonable size for the hash table

HashNode* hashTable[TABLE_SIZE];

/**
 * @brief Hash function to map a key to an index in the hash table.
 *
 * @param key (int): The prefix to be mapped to a hash table index.
 * @return (unsigned int): The index corresponding to the key.
 */
unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/**
 * @brief Inserts a key (prefix) into the hash table.
 *
 * @param key (int): The prefix to be inserted into the hash table.
 */
void insert(int key) {
    unsigned int index = hashFunction(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

/**
 * @brief Searches for a key (prefix) in the hash table.
 *
 * @param key (int): The prefix to be searched in the hash table.
 * @return (int): 1 if the key is found, 0 otherwise.
 */
int search(int key) {
    unsigned int index = hashFunction(key);
    HashNode* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            return 1;  // Key found
        }
        current = current->next;
    }
    return 0;  // Key not found
}

/**
 * @brief Frees the memory used by the hash table.
 */
void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current != NULL) {
            HashNode* tmp = current;
            current = current->next;
            free(tmp);
        }
        hashTable[i] = NULL;
    }
}

/**
 * @brief Finds the length of the longest common prefix between pairs of numbers
 * in two arrays using a hash set for quick look-up of integer prefixes.
 *
 * @param arr1 (int*): Pointer to the first array of integers.
 * @param arr1Size (int): Size of the first array.
 * @param arr2 (int*): Pointer to the second array of integers.
 * @param arr2Size (int): Size of the second array.
 * @return (int): The length of the longest common prefix found.
 */
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int max_common_prefix_length = 0;

    // Step 1: Add all possible prefixes of each number in arr1 to the hash table
    for (int i = 0; i < arr1Size; i++) {
        int current_prefix = arr1[i];
        while (current_prefix > 0) {
            insert(current_prefix);  // Insert the prefix into the hash table
            current_prefix /= 10;    // Remove the last digit
        }
    }

    // Step 2: Check all numbers in arr2 for the longest matching prefix
    for (int i = 0; i < arr2Size; i++) {
        int current_prefix = arr2[i];
        while (current_prefix > 0) {
            if (search(current_prefix)) {
                // A match is found. Calculate the length of this prefix.
                int length = 0, temp = current_prefix;
                while (temp > 0) {
                    length++;
                    temp /= 10;  // Count the number of digits in the prefix
                }
                if (length > max_common_prefix_length) {
                    max_common_prefix_length = length;
                }
                break;  // Stop once we find the longest matching prefix
            }
            current_prefix /= 10;  // Remove the last digit
        }
    }

    // Free the hash table memory
    freeHashTable();

    return max_common_prefix_length;
}